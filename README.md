# Neksus
Neksus is a full system simulation framework for System-in-Package (SiP) and System-on-Chip (SoC) applications. We integrate the IP definations given by GemDroid (https://github.com/gemdroid/GemDroid), DRAMSIM2 as memory module, and popular network simulator Booksim for a close loop simulation. It is based out of gem5 framework. Booksim has been configured for an optimized SiP interconnect. It supports common audio-video mobile applications like Youtube, Skype, etc. Application traces are collected from android emulator (https://github.com/huz123/GemDroid_QEMU).

Follow the below instructions to build and run Neksus.
## Build
        git clone https://github.com/gemdroid/GemDroid.git
        cd GemDroid/
        hg clone http://repo.gem5.org/gem5
        cd gem5/
        hg update -r 10231
        rm -rf src/
        cp -r ../gemdroid.src ./src
        cp -r ../gemdroid.needed/gemdroid.dramsim2/* ./ext/dramsim2/
        mkdir traces
        cp your_trace.trace tarces/
        cp ../gemdroid.needed/*.txt ./
        scons build/ARM/gem5.debug or scons build/ARM/gem5.opt

## Run
	build/ARM/gem5.debug -d results/test configs/example/se.py -n 1 --cpu-type=timing --caches --l2cache --num-dirs=1 --gemdroid --governor 0 --core_freq 1800 --mem_freq 2000 --ip_freq 500 --cpu_trace1 traces/user_input_trace_filename --num_cpu_traces=1 -c tests/test-progs/hello/bin/arm/linux/hello --cuttoffTime user_input_cuttofftime
