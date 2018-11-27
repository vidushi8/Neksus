#include "sim/init.hh"

namespace {

const uint8_t data_m5_ticks[] = {
    120,156,173,148,207,111,27,69,20,199,223,236,58,118,214,113,
    219,208,54,38,42,32,86,21,33,150,40,177,132,84,85,32,
    20,74,27,26,56,80,85,155,156,34,36,107,179,51,118,54,
    217,157,9,51,227,180,150,226,11,225,15,224,208,19,71,110,
    252,59,252,39,220,145,224,189,55,94,71,84,220,202,202,222,
    157,125,51,251,126,125,63,51,5,44,174,22,254,31,167,0,
    110,132,3,137,63,1,21,192,81,24,71,80,9,168,35,56,
    138,64,200,24,242,24,84,11,242,21,144,45,248,25,23,181,
    65,174,240,160,3,178,13,71,171,32,59,252,154,128,196,49,
    222,187,32,215,96,210,130,163,46,249,61,24,244,48,70,249,
    55,94,207,7,2,135,158,130,191,204,173,158,224,243,183,215,
    247,234,39,5,165,68,83,49,254,159,82,90,123,192,57,97,
    54,152,214,28,191,17,224,30,131,143,32,23,112,9,112,26,
    195,105,11,252,10,248,54,92,9,250,9,204,122,249,222,223,
    255,86,115,41,7,3,242,248,156,131,187,79,112,184,95,153,
    227,188,74,199,86,253,56,85,186,152,165,78,249,52,247,233,
    150,76,125,89,156,185,244,92,89,180,21,70,203,65,135,114,
    93,165,220,181,87,86,231,149,79,200,114,238,70,227,242,149,
    146,92,198,161,157,42,30,20,198,42,255,14,14,208,225,211,
    202,20,103,207,154,16,62,14,46,248,137,95,115,15,50,186,
    13,160,185,185,207,240,54,60,49,181,26,94,148,114,234,78,
    202,225,190,170,247,172,41,229,112,162,234,135,67,103,139,225,
    249,204,159,24,61,196,55,78,117,7,223,111,227,103,152,76,
    168,106,25,241,35,242,216,229,158,246,162,182,104,139,190,40,
    40,94,180,16,158,59,252,235,162,195,17,117,184,22,48,199,
    30,98,127,237,199,128,137,162,234,88,85,255,167,8,176,143,
    216,86,108,57,118,214,119,96,28,193,21,46,218,35,75,222,
    2,157,53,179,171,108,255,161,177,127,209,216,19,182,95,129,
    239,194,165,128,211,53,50,6,197,104,217,29,240,61,194,202,
    223,88,216,41,36,235,182,178,212,45,48,211,225,30,235,11,
    101,189,251,244,191,132,204,43,171,114,57,75,89,27,150,116,
    28,36,29,186,29,119,159,136,179,70,79,82,63,59,87,233,
    246,150,219,78,199,198,134,5,47,148,61,8,138,223,108,34,
    213,15,119,166,190,172,50,18,60,163,182,121,154,250,218,123,
    91,30,79,189,250,198,90,99,51,230,131,218,92,186,82,59,
    159,235,66,101,237,134,239,10,131,121,42,98,92,153,60,104,
    239,188,101,139,53,83,45,217,97,174,103,135,230,26,20,138,
    118,136,249,177,123,246,66,217,14,150,241,255,157,45,39,247,
    255,32,132,204,190,129,208,3,178,110,50,66,235,173,182,136,
    197,141,104,67,36,226,22,255,55,163,88,76,254,250,253,207,
    63,190,63,126,241,85,209,236,219,37,89,175,41,85,96,245,
    5,169,239,182,104,227,34,107,216,133,107,149,53,55,202,61,
    34,80,16,194,96,193,105,68,239,12,137,217,167,193,65,224,
    238,243,57,203,130,140,45,225,153,243,49,128,68,109,226,227,
    189,121,4,151,17,177,118,214,2,251,11,137,130,76,133,249,
    171,24,132,230,209,130,41,247,33,145,148,235,109,159,46,120,
    10,56,120,19,216,224,198,236,226,154,239,116,106,172,196,227,
    0,103,164,89,44,118,165,209,238,65,234,79,84,58,121,147,
    192,122,234,124,122,172,2,129,37,107,50,108,228,46,17,61,
    69,178,166,187,232,175,82,150,104,233,166,120,33,166,188,2,
    161,197,64,91,114,176,70,204,209,145,153,145,230,25,233,147,
    221,105,56,204,120,150,200,99,212,178,117,234,53,205,46,211,
    24,45,221,103,204,6,159,58,84,249,69,94,225,89,149,132,
    195,104,20,222,104,18,211,122,123,138,214,56,5,83,7,52,
    221,19,114,245,62,227,115,75,244,25,160,36,234,137,86,220,
    141,110,139,155,162,135,24,117,69,182,65,21,208,1,155,221,
    163,91,159,146,32,71,97,183,204,92,70,155,139,171,8,123,
    141,170,120,150,87,78,133,86,240,151,27,205,151,236,131,55,
    239,104,148,87,213,104,116,93,212,91,85,70,81,190,172,141,
    156,86,106,247,3,242,67,130,244,196,58,29,172,113,178,154,
    220,109,71,201,187,137,248,7,140,121,157,226,
};

EmbeddedPython embedded_m5_ticks(
    "m5/ticks.py",
    "/home/vidushi/GemDroid/gem5/src/python/m5/ticks.py",
    "m5.ticks",
    data_m5_ticks,
    972,
    1882);

} // anonymous namespace
