/**
 * Copyright (c) 2016 The Pennsylvania State University
 * All rights reserved.
 *     
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contact: Shulin Zhao (suz53@cse.psu.edu)
*/

#include "gemdroid/gemdroid_ip_decoder.hh"
#include "gemdroid/gemdroid.hh"

void GemDroidIPDecoder::init(int ip_type, int id, bool isDevice, int computeLatency, int inBufferSize, int outBufferSize, int coding_ratio, int processing_chunk_size,  bool isDecoder, int ip_freq, int opt_freq, GemDroid *gemDroid)
{
	GemDroidIP::init(ip_type, id, isDevice, 0, ip_freq, opt_freq, gemDroid);

	stats_m_IPMemOutStall		= 0;
	stats_m_IPMemInStalls		= 0;
	stats_m_IPDataReadIntoIP	= 0;
	stats_m_IPTrueProcessCycles	= 0;

	m_IPMemOutStall 			= 0;
	m_IPMemInStalls 			= 0;
	m_IPDataReadIntoIP 			= 0;
	m_IPTrueProcessCycles 		= 0;

	this->computeLatency = computeLatency;
	this->inBufferSize = inBufferSize;
	this->outBufferSize = outBufferSize;
	this->coding_ratio = coding_ratio;
	this->targetOutputChunkSizeInCL = processing_chunk_size;

	currInBuffer = 0;
	currOutBuffer = 0;
	
}

bool GemDroidIPDecoder::updatePower()
{
	return (GemDroidIP::updatePower());
}

void GemDroidIPDecoder::regStats()
{
	GemDroidIP::regStats();
	m_IPMemOutStall			.name(desc + ".m_IPMemOutStall			").desc("GemDroid: Number of Ip cycles that were stalled by out memory").flags(Stats::display);
	m_IPMemInStalls			.name(desc + ".m_IPMemInStalls			").desc("GemDroid: Number of Ip cycles that were stalled by in memory").flags(Stats::display);
	m_IPDataReadIntoIP		.name(desc + ".m_IPDataReadIntoIP		").desc("GemDroid: Number of Ip cycles where daa was read into IP compute units").flags(Stats::display);
	m_IPTrueProcessCycles	.name(desc + ".m_IPTrueProcessCycles	").desc("GemDroid: Number of Ip cycles that were true process cycles").flags(Stats::display);
}

void GemDroidIPDecoder::resetStats()
{
	GemDroidIP::resetStats();
}

void GemDroidIPDecoder::printPeriodicStats()
{
	GemDroidIP::printPeriodicStats();

	std::cout.precision (0);

	cout<<desc<<"_extra ";
	cout<<	m_IPMemOutStall.value()			- stats_m_IPMemOutStall			<<" "<<\
			m_IPMemInStalls.value()			- stats_m_IPMemInStalls			<<" "<<\
			m_IPDataReadIntoIP.value()		- stats_m_IPDataReadIntoIP		<<" "<<\
			m_IPTrueProcessCycles.value()	- stats_m_IPTrueProcessCycles 	<<" "<<\
			" "<<endl;
	//Set stats to latest value
	stats_m_IPMemOutStall			= m_IPMemOutStall.value();
	stats_m_IPMemInStalls			= m_IPMemInStalls.value();
	stats_m_IPDataReadIntoIP		= m_IPDataReadIntoIP.value();	
	stats_m_IPTrueProcessCycles		= m_IPTrueProcessCycles.value();
}

void GemDroidIPDecoder::memResponse(uint64_t addr, bool isRead)
{
	if (isRead) {
		currInBuffer++;
	}
	else {
	}
	GemDroidIP::memResponse(addr, isRead);
}

bool GemDroidIPDecoder::enqueueIPReq(int core_id, uint64_t addr, int size, bool isRead, int frameNum, int flowType, int flowId)
{
	if (GemDroidIP::enqueueIPReq(core_id, addr, size, isRead, frameNum, flowType, flowId)) {
		m_reqCount = ceil((double) size / CACHE_LINE_SIZE);
		if(ip_type == IP_TYPE_VD) {
			m_reqOutAddr = VD_ADDR_START + FRAME_SIZE;

			if (frameNum % FRACTION_OF_IFRAMES == 0)
				m_frameType = I_Frame;
			else {
				m_frameType = P_Frame;
				m_dependenceCount = ceil((size * 0.4) / CACHE_LINE_SIZE);
				m_dependenceAddr = VD_ADDR_START + 2 * FRAME_SIZE;
				m_reqCount = ceil(m_reqCount * 0.6);
			}
		}
		else if(ip_type == IP_TYPE_AD)
			m_reqOutAddr = AD_ADDR_START + AUD_FRAME_SIZE;

		m_IPMemStallsFrame = 0;

		assert(currInBuffer == 0);
		assert(currOutBuffer == 0);

		inputProcessedInCL = 0;
		inputToBeProcessedInCL = size / CACHE_LINE_SIZE; // changes vidushi
		
		reqSent = 0;

		//changes vidushi
		first_send_data = 0;
		sent_IPIP_req = 0;
		subframe_cache_line_size = SUB_FRAME_CACHE_LINE;
		subframe_sent = 0;
		subframe_max = size/SUB_FRAME_SIZE;
		send_prev_subframe = 0;	

		// DBGPRINT<<" got request for:"<< size<<" "<<frameNum<< " " << flowType<<" "<<flowId;
		// cout<<" inputToBeProcessedInCL to be:"<<inputToBeProcessedInCL<<endl;
		return true;
	}
	return false;
}

void GemDroidIPDecoder::sendDataOut()
{
	if (currOutBuffer > 0 && ((currOutBuffer%subframe_cache_line_size == 0 && !send_prev_subframe) )) {
	int ready = 1;
		//Successfully enqueued
			if (ready) {
			m_reqOutAddr = m_reqOutAddr + CACHE_LINE_SIZE;
			m_MemReqs++;
			first_send_data = first_send_data + subframe_cache_line_size;
			currOutBuffer = currOutBuffer - subframe_cache_line_size;
			/// changes vidushi
			if (first_send_data%subframe_cache_line_size == 0) {
				send_prev_subframe = 0;
				subframe_sent++;
			}
			else 
				send_prev_subframe = 1;
			/// changes done 
	    	}
	}
}

void GemDroidIPDecoder::requestDependentData()
{
	if (reqSent >= inBufferSize)
		return;

	// Enqueue memory request through gemdroid class
	if(!gemDroid->gemdroid_sa.enqueueIPMemRequest(ip_type, ip_id, core_id, m_dependenceAddr, true)) {
		// Unable to inject. Retry next tick.
		m_memRejected++;
	}
	else {
		//Successfully enqueued
		m_dependenceCount--;
		m_dependenceAddr = m_dependenceAddr + CACHE_LINE_SIZE;
		m_MemReqs++;
		reqSent++;

		IPActivityUpdate();
	}
}

void GemDroidIPDecoder::requestData()
{
	if(m_reqCount > 0 && reqSent < inBufferSize) {
		if(sendMemoryReq())
			reqSent++; //cout<<"Requested data"<<endl;
		else
			; //cout<<"Need to retry"<<endl;
	}
}

// returns true when processed something
enum process_event GemDroidIPDecoder::process()
{
	int ready = 0;
	switch (ip_type) {
	case IP_TYPE_AD:
	    if (m_flowType == IP_TYPE_MMC_IN)
		if (((gemDroid->gemdroid_ip_mmc_in[0].subframe_sent*subframe_cache_line_size + gemDroid->gemdroid_ip_mmc_in[0].first_send_data%subframe_cache_line_size) > subframe_sent*subframe_cache_line_size + currOutBuffer + first_send_data%subframe_cache_line_size && gemDroid->gemdroid_ip_mmc_in[0].is_busy && gemDroid->gemdroid_ip_mmc_in[0].m_frameNum ==  m_frameNum ) || !gemDroid->gemdroid_ip_mmc_in[0].is_busy || (gemDroid->gemdroid_ip_mmc_in[0].m_frameNum > m_frameNum && gemDroid->gemdroid_ip_mmc_in[0].is_busy))
	        ready = 1;
	    if (m_flowType == IP_TYPE_SND)
		ready = 1;
	    break;
	case IP_TYPE_VD:
	    ready = 1;
	}
	
	if (ready) {
	if (currOutBuffer + coding_ratio > outBufferSize)
		return OUT_BUFFER_FULL;

	if (m_cyclesToSkip > 0) {
		m_cyclesToSkip--;

		if (m_cyclesToSkip == 0) {
			inputProcessedInCL++;
			currOutBuffer += coding_ratio;
		}

		return TRUE_PROCESS_CYCLE;
	}

	if (currInBuffer > 0) {
		m_cyclesToSkip = computeLatency;
		currInBuffer--;
		reqSent--;
	}
	else
		return IN_BUFFER_EMPTY;
	
	//data is sent from input buffers to compute units
	return INBUFFER_DATA_RECVD;
	}
	else
	return IN_BUFFER_EMPTY; 
}

void GemDroidIPDecoder::tick()
{
	ticks++;

	if(!updatePower()) {
		return;
	}

	assert(isPStateActive());

	if (is_busy == false) {
		idleCycles++;
		return;
	}
	else
		m_IPWorkingCycles++;

	sendDataOut(); // change vidushi should change the position of sending data after processing is done so that once data is processed it should be sent out in same cycle??

	if(m_dependenceCount > 0) {
		requestDependentData();
	}
	else
		requestData();

	enum process_event is_success;
	if (inputProcessedInCL < inputToBeProcessedInCL)
		is_success = process();

	//changes vidushi
	if (first_send_data == subframe_cache_line_size && sent_IPIP_req == 0) {
		gemDroid->gemdroid_sa.enqueuefirstIPResponse(ip_type, ip_id, core_id, m_frameNum, m_flowType, m_flowId);
		sent_IPIP_req = 1;	
	}
	
	if (inputProcessedInCL == inputToBeProcessedInCL && currOutBuffer == 0) {
		is_busy = false;
		gemDroid->gemdroid_sa.enqueueIPResponse(ip_type, ip_id, core_id, m_frameNum, m_flowType, m_flowId);
		// DBGPRINT << " completed processing frame " << m_frameNum << endl;
		// Added vidushi for data
		if (m_frameNum == 0) {
		FILE *trace1;
                trace1 = fopen("trace1.txt","a");
		//fprintf(trace1, "%d\n", -(gemDroid->gemdroid_ip_dc[0].subframe_sent*subframe_cache_line_size + gemDroid->gemdroid_ip_snd[0].first_send_data%subframe_cache_line_size+gemDroid->gemdroid_ip_snd[0].currOutBuffer - subframe_sent*subframe_cache_line_size)*CACHE_LINE_SIZE);
		fprintf(trace1, "ip_type = %d, start_cycle = %ld, Stall IP ticksIP=%lf m_frameNum=%d m_IPMemOutStall=%lf, m_IPMemInStalls = %lf, m_IPDataReadIntoIP= %lf, m_IPTrueProcessCycles=%lf m_IPActiveCycles=%lf m_IPLowPowerCycles=%lf m_IPIdleCycles=%lf, m_IPWorkingCycles= %lf, m_MemReqs=%lf \n", ip_type, startCycle, ticks.value(), m_frameNum, m_IPMemOutStall.value() - stats_m_IPMemOutStall, m_IPMemInStalls.value() - stats_m_IPMemInStalls, m_IPDataReadIntoIP.value() - stats_m_IPDataReadIntoIP, m_IPTrueProcessCycles.value() - stats_m_IPTrueProcessCycles, m_IPActiveCycles.value() - stats_m_IPActiveCycles, m_IPLowPowerCycles.value() - stats_m_IPLowPowerCycles, m_IPIdleCycles.value(), m_IPWorkingCycles.value() - stats_m_IPWorkingCycles, m_MemReqs.value() - stats_m_MemReqs);
		fclose(trace1);
		//exit(1);
		}
		if (!m_frameNum)
		cout<<"DC procesed"<<gemDroid->gemdroid_ip_dc[0].subframe_sent*subframe_cache_line_size + gemDroid->gemdroid_ip_dc[0].first_send_data%subframe_cache_line_size+gemDroid->gemdroid_ip_dc[0].currOutBuffer<<"VD subframe sent"<<subframe_sent*subframe_cache_line_size<<"\n";
		long finish_cycle = ticks.value();
		end_cycle.push_back(finish_cycle);
		gemDroid->avg_procs_cycle[ip_type] = ((startCycle - finish_cycle) + gemDroid->avg_procs_cycle[ip_type]*m_frameNum)/(m_frameNum+1);
		/*
		FILE  *trace;
                trace = fopen("trace.txt", "a");
                fprintf(trace, "Request for IP %d completed for frame Number %d time=%ld\n", ip_type, m_frameNum, finish_cycle);
                fclose(trace);*/
		first_send_data = 0;
	}

	switch(is_success) {
	    case OUT_BUFFER_FULL:
	        m_IPMemOutStall++;
	        break;
	    case IN_BUFFER_EMPTY:
	        m_IPMemInStalls++;
	        break;
	    case INBUFFER_DATA_RECVD:
	        m_IPDataReadIntoIP++;
	        break;
	    case TRUE_PROCESS_CYCLE:
	        m_IPTrueProcessCycles++;
	        break;
	} 
}
