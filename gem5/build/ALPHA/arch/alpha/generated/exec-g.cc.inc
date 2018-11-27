// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   alpha/isa/main.isa

#include "decoder.hh"

#include <cmath>

#include "arch/alpha/decoder.hh"
#include "arch/alpha/registers.hh"
#include "arch/alpha/regredir.hh"
#include "arch/generic/memhelpers.hh"
#include "base/cp_annotate.hh"
#include "base/fenv.hh"
#include "config/ss_compatible_fp.hh"
#include "cpu/base.hh"
#include "cpu/exetrace.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"
#include "sim/full_system.hh"
#include "sim/pseudo_inst.hh"
#include "sim/sim_exit.hh"

using namespace AlphaISA;
