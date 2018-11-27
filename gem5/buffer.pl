#/usr/bin/perl

use autodie;

$sim_file = "src/gemdroid/gemdroid_defines.hh";
system("rm trace1.txt");
system("rm trace.txt");
system("rm mem_access.txt");

for ($subframe_size = 1; $subframe_size < 20; $subframe_size = $subframe_size + 1)
{
  system("sed -i \"s/IO_LATENCY_IP (.*/IO_LATENCY_IP ($subframe_size)/\" $sim_file");
  #system("sed -i \"s/SUB_FRAME_SIZE (.*/SUB_FRAME_SIZE ($subframe_size*16)/\" $sim_file");
  #system("sed -i \"s/SUB_FRAME_CACHE_LINE (.*/SUB_FRAME_CACHE_LINE ($subframe_size*16)/\" $sim_file"); 
  #$injection_rate_5x=$injection_rate * 0.2;
#  system("sed -i \"s/inj_unifm uniform.*/inj_unifm uniform $injection_rate_5x/\" $sim_file"); 
#  system("sed -i \"s/inj_unifm2 uniform.*/inj_unifm2 uniform $injection_rate/\" $sim_file"); 
  system("scons build/ARM/gem5.debug");
  system("build/ARM/gem5.debug -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 1800 --ip_freq 500 --cpu_trace1 traces/youtube_together.trace --num_cpu_traces=1 --device_config=ini/your_device_config.ini --system_config=your_system_config.ini -c tests/test-progs/hello/bin/arm/linux/hello");
  #system("grep \"Packet latency average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_lat_packet");
  #system("grep \"Injected packet rate average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_injection_packet");
  #system("grep \"Accepted packet rate average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_accepted_packet");
  #system("grep \"Flit latency average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_lat_flit");
  #system("grep \"Injected flit rate average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_injection_flit");
  #system("grep \"Accepted flit rate average = [0-9]*\.[0-9]* (1 samples)\" output  >> $output_file_accepted_flit");
  #$i=$i+1;
}


