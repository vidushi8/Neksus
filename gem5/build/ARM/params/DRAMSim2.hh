#ifndef __PARAMS__DRAMSim2__
#define __PARAMS__DRAMSim2__

class DRAMSim2;

#include <cstddef>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/AbstractMemory.hh"

struct DRAMSim2Params
    : public AbstractMemoryParams
{
    DRAMSim2 * create();
    bool enableDebug;
    std::string systemConfigFile;
    std::string traceFile;
    std::string deviceConfigFile;
    std::string filePath;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__DRAMSim2__
