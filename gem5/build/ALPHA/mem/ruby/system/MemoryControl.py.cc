#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_MemoryControl[] = {
    120,156,181,144,61,79,195,48,16,134,207,233,119,11,130,95,
    128,96,139,24,154,133,110,168,66,128,4,12,124,168,237,66,
    150,40,141,15,146,54,174,43,219,173,154,185,252,111,184,115,
    41,18,11,27,118,124,121,95,203,62,63,119,25,124,143,26,
    173,171,83,0,123,65,66,210,39,160,4,152,176,10,160,20,
    160,4,196,2,132,172,1,10,120,19,32,235,240,1,176,5,
    120,141,3,144,13,24,135,77,186,88,124,210,8,5,41,199,
    225,124,39,15,41,220,148,58,155,163,124,158,206,48,115,126,
    231,17,149,54,213,141,94,56,163,203,108,207,17,208,186,102,
    142,33,9,4,126,20,3,136,107,204,20,215,125,108,48,92,
    220,4,108,193,172,205,120,91,178,29,111,187,123,219,131,209,
    56,228,154,70,156,208,82,66,80,168,34,179,154,86,145,173,
    172,35,253,235,253,126,158,59,126,62,60,96,224,54,133,36,
    89,164,10,147,196,117,189,81,90,174,74,182,117,178,19,179,
    66,127,40,157,90,103,82,42,136,119,93,181,68,215,33,145,
    109,54,73,86,166,214,250,187,236,114,76,37,26,215,32,251,
    146,154,84,57,70,123,88,56,215,162,255,26,141,45,8,131,
    15,143,8,112,236,249,92,143,44,243,38,59,222,208,227,253,
    4,123,79,33,202,181,194,104,93,200,149,205,139,232,14,213,
    173,209,133,76,166,90,207,109,161,162,119,84,131,200,154,44,
    250,187,244,101,229,155,116,198,89,185,252,166,216,207,35,241,
    228,155,232,171,82,131,254,146,217,237,72,236,251,250,159,76,
    190,191,151,187,182,15,79,56,59,247,184,43,142,131,47,105,
    98,160,172,
};

EmbeddedPython embedded_m5_objects_MemoryControl(
    "m5/objects/MemoryControl.py",
    "/home/vidushi/GemDroid_booksim/gem5/src/mem/ruby/system/MemoryControl.py",
    "m5.objects.MemoryControl",
    data_m5_objects_MemoryControl,
    371,
    692);

} // anonymous namespace
