#!/bin/bash

trap 'kill $(jobs -p)' EXIT
trap exit_on_error ERR

exit_on_error() {
    echo ERROR: Server returns with error
    #exit 1
}

export command="build/ARM/gem5.opt"

rm trace.txt
rm trace1.txt
rm trace2.txt
rm trace1_vdr_5_3wrk.txt
$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/video-record.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_vdr_5_3wrk.txt

kill $(jobs -p)
wait

rm trace1_phcap_4_3wrk.txt

$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/photo-capture.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_phcap_4_3wrk.txt


kill $(jobs -p)
wait

rm trace1_gl1_3_3wrk.txt
$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/gallery_1.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_gl1_3_3wrk.txt

kill $(jobs -p)
wait

rm trace1_adply_1_3wrk.txt
$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/audio-play.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_adply_1_3wrk.txt

kill $(jobs -p)
wait

rm trace1_adr_1_3wrk.txt
$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/audio-record.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_adr_1_3wrk.txt

kill $(jobs -p)
wait

rm trace1_skype_1_3wrk.txt
$command -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/skype.trace --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime 3

rm watch_out_test_file
mv trace1.txt trace1_skype_1_3wrk.txt

kill $(jobs -p)
wait


exit(1)


