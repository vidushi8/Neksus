#ifndef __PARAMS__VGic__
#define __PARAMS__VGic__

class VGic;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct VGicParams
    : public PioDeviceParams
{
    VGic * create();
    uint32_t ppint;
    Addr hv_addr;
    Platform * platform;
    Addr vcpu_addr;
    BaseGic * gic;
    Tick pio_delay;
};

#endif // __PARAMS__VGic__
