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

#include "gemdroid/gemdroid_ip_nocoder.hh"
#include "gemdroid/gemdroid.hh"

void GemDroidIPNocoder::init(int ip_type, int id, bool isDevice, int computeLatency, int inBufferSize, int outBufferSize, int coding_ratio, int processing_chunk_size,  bool isDecoder, int ip_freq, int opt_freq, GemDroid *gemDroid)
{
	GemDroidIP::init(ip_type, id, isDevice, 0, ip_freq, opt_freq, gemDroid);

	this->computeLatency = computeLatency;
	this->inBufferSize = inBufferSize;
	this->outBufferSize = outBufferSize;
	this->coding_ratio = coding_ratio;
	this->targetOutputChunkSizeInCL = processing_chunk_size;

	currInBuffer = 0;
	currOutBuffer = 0;
	first_send_data = 0;
}

bool GemDroidIPNocoder::updatePower()
{
	return (GemDroidIP::updatePower());
}

void GemDroidIPNocoder::regStats()
{
	GemDroidIP::regStats();
}

void GemDroidIPNocoder::resetStats()
{
	GemDroidIP::resetStats();
}

void GemDroidIPNocoder::printPeriodicStats()
{
	GemDroidIP::printPeriodicStats();
}

void GemDroidIPNocoder::memResponse(uint64_t addr, bool isRead)
{
	if (isRead) {
		currInBuffer++;
	}
	else {
		GemDroidIP::memResponse(addr, isRead);
	}

	//GemDroidIP::memResponse(addr, isRead);
}

bool GemDroidIPNocoder::enqueueIPReq(int core_id, uint64_t addr, int size, bool isRead, int frameNum, int flowType, int flowId)
{
	if (GemDroidIP::enqueueIPReq(core_id, addr, size, isRead, frameNum, flowType, flowId)) {
		if(ip_type == IP_TYPE_IMG)
			m_reqOutAddr = IMG_ADDR_START + FRAME_SIZE;

		m_IPMemStallsFrame = 0;

		assert(currInBuffer == 0);
		assert(currOutBuffer == 0);

		inputProcessedInCL = 0;
		inputToBeProcessedInCL = size / CACHE_LINE_SIZE;
		reqSent = 0;

		//changes vidushi
                first_send_data = 0;
                sent_IPIP_req = 0;
                //subframe_cache_line_size = ceil(SUB_FRAME_SIZE/CACHE_LINE_SIZE);
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

void GemDroidIPNocoder::sendDataOut()
{
        if (currOutBuffer > 0 && ((currOutBuffer/subframe_cache_line_size >= 1 && !send_prev_subframe) || send_prev_subframe)) {
	// Same reason as encoder
	//if (currOutBuffer > 0) {
		/*if(!gemDroid->gemdroid_sa.enqueueIPMemRequest(ip_type, ip_id, core_id, m_reqOutAddr, false)) {
			// Unable to inject. Retry next tick.
			m_memRejected++;
		}
		else */{
			//Successfully enqueued
			m_reqOutAddr = m_reqOutAddr + CACHE_LINE_SIZE;
			m_MemReqs++;
			first_send_data++;
			currOutBuffer--;

			if (first_send_data%subframe_cache_line_size == 0) {
                                send_prev_subframe = 0;
                                subframe_sent++;
                        }
                        else
                                send_prev_subframe = 1;
		}
	}
}

void GemDroidIPNocoder::requestData()
{
	if(m_reqCount > 0 && reqSent < inBufferSize) {
		if(sendMemoryReq())
			reqSent++; //cout<<"Requested data"<<endl;
		else
			; //cout<<"Need to retry"<<endl;
	}
}

// returns true when processed something
bool GemDroidIPNocoder::process()
{
	int ready = 0;
	switch (m_flowType) {
	case IP_TYPE_CAM:
	if (((gemDroid->gemdroid_ip_cam[0].subframe_sent*subframe_cache_line_size + gemDroid->gemdroid_ip_cam[0].first_send_data%subframe_cache_line_size) > subframe_sent*subframe_cache_line_size + currOutBuffer + first_send_data%subframe_cache_line_size && gemDroid->gemdroid_ip_cam[0].is_busy && gemDroid->gemdroid_ip_cam[0].m_frameNum ==  m_frameNum ) || !gemDroid->gemdroid_ip_cam[0].is_busy || (gemDroid->gemdroid_ip_cam[0].m_frameNum > m_frameNum && gemDroid->gemdroid_ip_cam[0].is_busy))
            ready = 1;
            break;
	case IP_TYPE_MMC_IN:
	if (((gemDroid->gemdroid_ip_mmc_in[0].subframe_sent*subframe_cache_line_size + gemDroid->gemdroid_ip_mmc_in[0].first_send_data%subframe_cache_line_size) > subframe_sent*subframe_cache_line_size + currOutBuffer + first_send_data%subframe_cache_line_size && gemDroid->gemdroid_ip_mmc_in[0].is_busy && gemDroid->gemdroid_ip_mmc_in[0].m_frameNum ==  m_frameNum ) || !gemDroid->gemdroid_ip_mmc_in[0].is_busy || (gemDroid->gemdroid_ip_mmc_in[0].m_frameNum > m_frameNum && gemDroid->gemdroid_ip_mmc_in[0].is_busy))
                ready = 1;
	    break;
	default:
	    ready = 0;
	}

	if (ready) {
	if (currOutBuffer + targetOutputChunkSizeInCL > outBufferSize)
		return false;
	/* Moving in currInBuffer loop to take care of processing and reading in same cycle as done in encoder
	if (m_cyclesToSkip > 0) {
		m_cyclesToSkip--;

		if (m_cyclesToSkip == 0) {
			inputProcessedInCL++;
			// DBGPRINT<<" completed processing one input CL. Total inputProcessedInCL = "<<inputProcessedInCL<<endl;
			if (inputProcessedInCL % targetOutputChunkSizeInCL == 0) {
				currOutBuffer += targetOutputChunkSizeInCL;
				// DBGPRINT<<" Completed one chunk. currentOutBuffer = " << currOutBuffer<<endl;
			}
		}

		return true;
	}*/

	if (currInBuffer > 0) {
		m_cyclesToSkip = computeLatency;
		currInBuffer--;
		reqSent--;
		if (m_cyclesToSkip > 0) {
                m_cyclesToSkip--;

                if (m_cyclesToSkip == 0) {
                        inputProcessedInCL++;
                        // DBGPRINT<<" completed processing one input CL. Total inputProcessedInCL = "<<inputProcessedInCL<<endl;
                        if (inputProcessedInCL % targetOutputChunkSizeInCL == 0) {
                                currOutBuffer += targetOutputChunkSizeInCL;
                                // DBGPRINT<<" Completed one chunk. currentOutBuffer = " << currOutBuffer<<endl;
                        }
                }

                return true;
        	}
	}
	else
		return false;
	}

	return true;
}

void GemDroidIPNocoder::tick()
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

	sendDataOut();

	requestData();

	int m_respCount_req = inputToBeProcessedInCL/(targetOutputChunkSizeInCL);

	if (first_send_data == 1 && sent_IPIP_req == 0) {
		gemDroid->gemdroid_sa.enqueuefirstIPResponse(ip_type, ip_id, core_id, m_frameNum, m_flowType, m_flowId);
		sent_IPIP_req = 1;
	}

	bool is_success = false;
	if (inputProcessedInCL < inputToBeProcessedInCL)
		is_success = process();

	if (inputProcessedInCL == inputToBeProcessedInCL && currOutBuffer == 0 /*&& m_respCount == m_respCount_req*targetOutputChunkSizeInCL*/) {
		is_busy = false;
		gemDroid->gemdroid_sa.enqueueIPResponse(ip_type, ip_id, core_id, m_frameNum, m_flowType, m_flowId);
		// DBGPRINT << " completed processing frame " << m_frameNum << endl;
		first_send_data = 0;
		if (m_frameNum == 0) {
                FILE *trace1;
                trace1 = fopen("trace1.txt","a");
                fprintf(trace1, "ip_type = %d , start_cycle = %ld, Stall IP ticksIP=%lf m_frameNum=%d m_IPMemStalls = %lf, m_IPActiveCycles=%lf m_IPLowPowerCycles=%lf m_IPIdleCycles=%lf, m_IPWorkingCycles= %lf, m_MemReqs=%lf \n", ip_type, startCycle, ticks.value(), m_frameNum, m_IPMemStalls.value() - stats_m_IPMemStalls, m_IPActiveCycles.value() - stats_m_IPActiveCycles, m_IPLowPowerCycles.value() - stats_m_IPLowPowerCycles, m_IPIdleCycles.value(), m_IPWorkingCycles.value() - stats_m_IPWorkingCycles, m_MemReqs.value() - stats_m_MemReqs);
                fclose(trace1);
                //exit(1);
                }
                assert(m_reqCount <= 0);
                long finish_cycle = ticks.value();
                FILE  *trace;
                trace = fopen("trace.txt", "a");
                fprintf(trace, "Request for IP %d completed for frame Number %d time=%ld\n", ip_type,  m_frameNum, finish_cycle);
                fclose(trace);
	}

	if (!is_success) {
		m_IPMemStalls++;
	}
}
