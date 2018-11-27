%module(package="m5.internal") param_AlphaBackdoor

%{
#include "sim/sim_object.hh"
#include "params/AlphaBackdoor.hh"
#include <cstddef>
#include "params/Terminal.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "params/SimpleDisk.hh"
#include <cstddef>
#include "params/AlphaSystem.hh"
#include <cstddef>
#include "params/BaseCPU.hh"
#include "dev/alpha/backdoor.hh"
/**
  * This is a workaround for bug in swig. Prior to gcc 4.6.1 the STL
  * headers like vector, string, etc. used to automatically pull in
  * the cstddef header but starting with gcc 4.6.1 they no longer do.
  * This leads to swig generated a file that does not compile so we
  * explicitly include cstddef. Additionally, including version 2.0.4,
  * swig uses ptrdiff_t without the std:: namespace prefix which is
  * required with gcc 4.6.1. We explicitly provide access to it.
  */
#include <cstddef>
using std::ptrdiff_t;
%}

%import "python/m5/internal/param_Terminal.i"
%import "python/m5/internal/param_Platform.i"
%import "python/m5/internal/param_SimpleDisk.i"
%import "python/m5/internal/param_AlphaSystem.i"
%import "python/m5/internal/param_BaseCPU.i"

%import "python/m5/internal/param_BasicPioDevice.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault AlphaBackdoor;
class AlphaBackdoor
    : public BasicPioDevice
{
  public:
};

%include "params/AlphaBackdoor.hh"
