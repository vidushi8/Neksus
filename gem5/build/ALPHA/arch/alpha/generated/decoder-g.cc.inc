// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   alpha/isa/main.isa

#include "decoder.hh"

#include <cmath>

#include "arch/alpha/decoder.hh"
#include "arch/alpha/registers.hh"
#include "arch/alpha/regredir.hh"
#include "base/loader/symtab.hh"
#include "base/cprintf.hh"
#include "base/fenv.hh"
#include "config/ss_compatible_fp.hh"
#include "cpu/thread_context.hh"  // for Jump::branchTarget()
#include "mem/packet.hh"
#include "sim/full_system.hh"

using namespace AlphaISA;
