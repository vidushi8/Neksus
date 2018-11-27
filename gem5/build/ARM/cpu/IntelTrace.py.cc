#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_IntelTrace[] = {
    120,156,173,144,193,78,131,64,16,134,103,129,162,54,30,234,
    213,196,68,111,196,3,27,15,189,52,198,24,211,196,244,162,
    9,244,34,151,13,238,174,130,97,11,97,169,105,207,250,222,
    58,179,20,121,1,23,248,51,255,48,12,223,140,132,195,241,
    241,185,191,4,176,75,12,20,222,12,42,0,195,32,99,192,
    200,123,80,121,176,166,200,135,202,7,227,67,230,227,155,0,
    180,15,111,12,212,4,190,1,190,0,94,178,0,84,8,105,
    116,132,141,202,31,60,17,195,168,59,65,73,75,243,252,250,
    161,101,215,167,72,174,251,112,138,178,218,216,110,221,230,82,
    183,7,219,233,202,121,57,64,82,233,3,65,158,99,160,129,
    216,16,40,243,136,22,105,144,17,127,158,164,17,13,147,144,
    216,51,20,215,99,177,24,251,185,172,108,182,188,164,84,71,
    169,184,40,162,9,129,28,163,8,177,201,141,22,194,97,8,
    97,106,181,173,200,6,84,176,111,180,155,69,238,118,66,86,
    185,181,174,138,92,161,115,165,219,136,64,71,177,55,40,188,
    168,141,230,159,165,218,218,162,228,143,218,44,219,186,84,252,
    93,155,57,183,173,228,196,50,226,197,205,222,193,95,209,231,
    33,74,200,232,122,234,1,79,81,204,60,254,91,101,2,195,
    118,49,219,228,109,110,108,226,13,243,255,11,140,219,201,109,
    191,133,187,139,1,106,198,166,108,230,253,2,142,190,122,20,
};

EmbeddedPython embedded_m5_objects_IntelTrace(
    "m5/objects/IntelTrace.py",
    "/home/vidushi/GemDroid/gem5/src/cpu/IntelTrace.py",
    "m5.objects.IntelTrace",
    data_m5_objects_IntelTrace,
    320,
    576);

} // anonymous namespace
