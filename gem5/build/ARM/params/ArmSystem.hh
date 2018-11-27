#ifndef __PARAMS__ArmSystem__
#define __PARAMS__ArmSystem__

class ArmSystem;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <string>

#include "params/System.hh"

struct ArmSystemParams
    : public SystemParams
{
    ArmSystem * create();
    bool have_virtualization;
    uint8_t phys_addr_range_64;
    bool highest_el_is_64;
    bool have_generic_timer;
    bool have_security;
    uint64_t reset_addr_64;
    Addr gic_cpu_addr;
    bool have_lpae;
    Addr flags_addr;
    bool have_large_asid_64;
    bool multi_proc;
    std::string boot_loader;
};

#endif // __PARAMS__ArmSystem__
