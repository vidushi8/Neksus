#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_SimpleLink[] = {
    120,156,181,82,77,79,131,64,16,157,229,171,180,209,196,131,
    233,209,152,24,35,241,208,61,245,102,140,105,52,198,196,143,
    132,122,145,11,161,236,42,180,44,16,160,10,103,253,223,186,
    179,208,90,111,246,80,2,47,51,143,101,102,222,240,66,232,
    46,93,62,87,199,0,229,92,6,76,222,4,18,128,231,46,
    34,109,164,65,162,129,208,193,211,129,96,174,67,98,128,48,
    193,51,65,88,224,89,146,53,128,91,240,74,128,153,240,5,
    240,9,240,226,245,128,89,192,77,197,246,214,172,13,204,134,
    169,211,151,237,226,111,121,57,68,70,21,194,121,27,226,155,
    105,44,158,102,115,30,86,142,134,212,158,132,73,80,198,225,
    93,90,221,199,233,226,151,184,169,91,98,191,253,40,79,120,
    199,132,43,129,88,115,130,2,15,101,192,1,60,130,50,61,
    13,245,73,61,238,84,181,112,13,9,229,169,4,193,5,45,
    150,179,134,166,188,250,200,138,5,45,85,89,218,86,199,210,
    163,40,114,240,120,101,75,240,253,52,16,220,247,171,129,74,
    68,198,150,9,166,234,64,147,115,197,135,117,237,71,60,96,
    188,112,112,164,95,40,31,36,208,40,19,156,190,199,108,89,
    70,49,189,229,226,186,200,98,230,207,178,108,33,123,211,55,
    46,198,180,44,66,250,143,201,242,70,9,57,193,210,24,88,
    196,34,27,187,233,214,183,237,110,250,219,239,198,53,17,44,
    132,30,130,253,71,246,174,180,227,160,103,155,218,31,149,207,
    148,165,196,120,148,7,69,32,74,245,219,48,43,178,186,81,
    78,146,201,218,112,238,218,131,202,95,88,217,85,75,208,87,
    46,81,93,118,174,69,77,121,209,218,233,242,8,91,160,145,
    6,100,64,14,200,80,27,26,63,133,208,220,47,
};

EmbeddedPython embedded_m5_objects_SimpleLink(
    "m5/objects/SimpleLink.py",
    "/home/vidushi/GemDroid_booksim/gem5/src/mem/ruby/network/simple/SimpleLink.py",
    "m5.objects.SimpleLink",
    data_m5_objects_SimpleLink,
    397,
    961);

} // anonymous namespace
