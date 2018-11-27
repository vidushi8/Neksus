%module(package="m5.internal") AlphaISA_vector
%{
#include "params/AlphaISA.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_AlphaISA.i"

%include "std_vector.i"

%template(vector_AlphaISA) std::vector< AlphaISA::ISA * >;
