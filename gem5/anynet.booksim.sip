// $Id: singleconfig 1535 2009-09-16 16:21:01Z dub $

// Copyright (c) 2007-2009, Trustees of The Leland Stanford Junior University
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// Redistributions of source code must retain the above copyright notice, this 
// list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright notice, 
// this list of conditions and the following disclaimer in the documentation 
// and/or other materials provided with the distribution.
// Neither the name of the Stanford University nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.


topology = anynet;

routing_function = min;
//network_file = ./examples/interposer_mesh_64ip_cf4;
//network_file = ./examples/interposer_fbfly_64ip_cf4_cmesh_1;
network_file = ./examples/interposer_xbar_64ip_cf4_debug;
traffic = uniform;

use_read_write = 0;

watch_out = watch_out_test_file;


//st_final_delay = 0;
sample_period = 1000;
injection_rate =  0.0980100000000001;
input_speedup = 1;
output_speedup = 1;

//arb_type = round_robin;
//hold_switch_for_packet = 1;

vc_allocator = separable_input_first; 
sw_allocator = separable_input_first;

packet_size = 4;

routing_delay = 0;
speculative = 1;

sim_type = throughput;

num_vcs     = 4;
vc_buf_size = 4;

deadlock_warn_timeout = 20024;
//latency_thres = 102400.00;
