/*
 * DO NOT EDIT THIS FILE! Automatically generated
 */

#include "base/debug.hh"
#include "debug/Annotate.hh"
#include "debug/AnnotateQ.hh"
#include "debug/AnnotateVerbose.hh"

namespace Debug {

CompoundFlag AnnotateAll("AnnotateAll", "All Annotation flags",
    Annotate,
    AnnotateQ,
    AnnotateVerbose);

} // namespace Debug
