#ifndef __PARAMS__GemDroid__
#define __PARAMS__GemDroid__

class GemDroid;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct GemDroidParams
    : public ClockedObjectParams
{
    GemDroid * create();
    std::string cpu_trace4;
    std::string cpu_trace2;
    std::string cpu_trace3;
    std::string cpu_trace1;
    std::string traceFile;
    int num_ip_instances;
    int cuttoffTime;
    AddrRange range;
    int ip_freq;
    int issue_width;
    std::string deviceConfigFile;
    std::string filePath;
    bool perfect_memory;
    bool enableDebug;
    bool no_periodic_stats;
    int dev_freq;
    double sweep_val2;
    std::string gpu_trace;
    double sweep_val1;
    int num_cpu_traces;
    int core_freq;
    int governor;
    std::string systemConfigFile;
    bool enable_gemdroid;
    int governor_timing;
    int mem_freq;
};

#endif // __PARAMS__GemDroid__
