#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_SimpleTrace[] = {
    120,156,197,88,255,115,219,72,21,127,43,201,78,236,36,141,
    211,52,73,219,164,141,14,166,156,233,64,12,199,149,50,115,
    161,92,129,3,238,230,200,21,185,76,122,190,27,132,34,173,
    109,57,182,228,145,54,77,221,113,126,128,116,128,127,128,63,
    129,31,248,111,248,143,224,189,183,146,172,124,233,204,205,64,
    77,106,109,87,171,221,183,239,203,231,125,217,245,33,251,171,
    224,243,177,13,144,38,2,32,192,159,128,33,192,72,64,71,
    128,144,2,130,91,112,92,129,228,67,8,42,240,6,160,99,
    128,52,224,28,59,38,124,101,64,180,204,107,170,48,52,121,
    68,192,164,14,210,130,78,5,14,163,53,176,100,21,142,235,
    144,252,17,132,16,145,128,23,193,2,4,139,240,6,169,99,
    167,198,4,23,129,6,235,60,88,131,96,137,7,235,16,44,
    115,103,9,38,13,144,203,208,89,161,105,157,27,72,246,33,
    146,93,101,178,255,34,178,1,126,217,128,224,6,77,71,190,
    190,164,153,22,205,228,253,86,153,74,35,231,114,13,58,55,
    243,254,122,169,127,171,212,223,224,62,238,122,19,6,155,48,
    216,130,193,109,232,162,34,214,138,29,238,128,52,97,112,23,
    58,119,65,226,239,14,156,163,174,130,155,165,21,219,188,98,
    189,88,177,195,43,238,65,231,30,72,252,237,232,21,85,104,
    55,55,81,255,225,191,241,175,137,250,7,181,140,205,75,153,
    164,97,28,185,97,212,141,67,131,190,87,169,33,107,249,212,
    44,100,102,251,5,153,237,159,192,54,11,140,204,108,103,128,
    132,5,201,50,52,224,140,59,103,6,76,154,48,21,48,176,
    32,48,97,138,219,84,136,129,158,128,115,3,190,54,105,194,
    25,182,22,42,247,62,88,74,219,108,192,202,213,148,22,224,
    172,2,211,10,180,95,76,13,26,56,174,65,242,15,120,189,
    195,68,23,153,168,1,83,108,45,56,183,224,172,10,135,56,
    9,135,6,53,18,95,188,152,162,164,56,210,110,90,200,237,
    65,73,92,18,37,8,147,200,27,73,117,19,251,238,216,75,
    188,145,219,14,71,227,161,124,158,120,190,108,214,243,121,113,
    186,55,246,84,223,225,133,38,105,100,52,86,76,48,142,164,
    90,194,78,55,140,2,119,20,7,39,67,169,22,137,154,219,
    13,135,210,117,249,227,167,163,113,156,168,79,146,36,78,28,
    82,42,15,14,99,175,88,65,42,245,135,113,42,155,180,27,
    111,227,16,121,69,179,187,99,166,72,12,48,179,180,56,144,
    169,159,132,99,133,182,210,20,105,54,81,107,146,149,184,73,
    15,177,105,245,227,145,108,189,12,131,147,180,31,182,126,45,
    71,191,76,226,48,112,143,226,248,56,13,71,173,158,28,61,
    106,29,157,132,195,160,245,244,243,103,191,121,218,26,79,84,
    63,142,90,56,26,70,74,162,114,134,173,43,106,217,195,73,
    164,176,244,52,236,185,33,139,230,246,229,112,44,147,21,26,
    189,75,155,139,134,88,22,85,97,138,166,88,193,94,5,31,
    83,236,24,75,226,32,36,225,124,18,152,144,101,149,177,68,
    6,22,112,108,64,178,67,72,25,224,79,144,105,17,47,109,
    250,102,240,183,223,145,86,244,232,192,36,251,235,193,41,163,
    11,97,134,51,247,201,224,17,48,68,42,48,168,130,134,14,
    34,78,99,41,153,80,139,211,137,140,129,196,45,72,255,14,
    168,101,4,205,20,50,64,157,155,32,162,6,168,58,249,52,
    142,110,226,134,127,102,76,182,155,196,254,1,35,67,245,195,
    52,62,141,88,255,212,103,47,106,163,102,158,77,190,56,26,
    72,95,165,187,56,240,101,124,98,251,94,20,197,202,246,130,
    192,246,148,74,194,163,19,37,83,91,197,246,131,180,73,38,
    117,214,114,112,21,244,38,227,28,76,100,120,4,147,126,9,
    66,95,225,203,58,191,176,21,82,169,16,24,253,56,72,113,
    156,72,244,164,114,136,73,69,74,142,153,17,198,141,75,83,
    105,123,156,119,3,223,159,230,156,48,56,155,213,28,74,169,
    28,118,85,157,81,233,165,169,203,156,208,56,3,144,8,191,
    244,134,39,146,169,167,72,15,25,162,174,230,97,78,16,188,
    77,226,228,210,179,72,81,28,5,19,228,48,244,223,167,205,
    111,51,16,151,25,138,27,8,195,5,108,171,248,127,85,108,
    26,190,149,129,175,154,3,144,130,161,2,54,191,200,16,128,
    96,60,199,192,211,52,56,114,176,84,236,153,223,162,30,45,
    118,118,168,185,71,205,125,106,118,115,193,223,189,244,43,151,
    165,127,76,59,26,44,50,11,71,70,50,115,225,130,11,222,
    117,103,230,93,24,34,219,228,37,6,249,210,204,75,44,10,
    167,201,19,106,113,42,251,159,9,233,115,10,222,228,77,76,
    140,28,7,93,128,122,51,199,96,85,57,13,82,193,98,142,
    105,135,128,90,70,107,175,132,86,135,172,196,80,117,238,228,
    145,209,165,25,26,164,206,54,145,170,92,163,107,155,154,247,
    230,167,240,25,220,122,87,224,246,17,109,222,200,224,182,194,
    48,171,227,211,48,124,51,179,66,145,51,215,47,193,140,48,
    102,93,131,177,239,80,207,188,42,247,220,225,149,73,251,171,
    18,188,136,65,163,44,212,1,118,38,91,36,75,25,88,91,
    88,2,28,70,91,152,213,13,206,234,63,224,172,206,149,1,
    215,71,58,96,155,28,179,117,167,66,74,233,154,176,153,101,
    235,180,134,237,56,137,95,77,236,184,107,43,150,154,226,235,
    254,131,116,239,65,250,17,70,78,251,9,199,44,29,59,117,
    116,76,228,152,162,27,45,253,228,149,47,57,71,242,155,235,
    234,96,230,114,96,115,179,220,139,24,219,32,149,26,185,174,
    57,172,167,42,161,104,62,39,109,215,11,109,19,243,159,209,
    118,117,86,181,41,182,16,79,117,193,60,185,58,142,115,29,
    198,95,241,249,57,169,159,228,150,64,85,179,211,214,28,179,
    48,36,150,243,189,11,152,121,231,162,56,45,164,253,251,28,
    43,213,25,86,232,49,115,7,248,43,112,141,42,224,47,64,
    104,64,163,103,14,80,248,11,153,127,157,166,255,1,216,83,
    174,169,11,56,238,180,169,22,224,25,24,142,210,199,60,85,
    151,9,159,193,223,74,110,150,39,115,51,171,66,203,201,220,
    42,98,22,195,232,27,37,108,235,98,112,35,243,244,189,148,
    166,233,136,53,243,220,89,98,40,138,71,140,216,239,30,83,
    139,122,35,151,120,250,122,134,40,74,135,219,98,221,40,225,
    228,135,212,124,80,64,68,228,99,239,148,189,93,120,123,246,
    118,117,118,248,138,120,176,152,235,213,5,78,12,37,26,133,
    23,84,114,47,248,160,240,2,201,121,236,13,31,78,168,53,
    200,232,231,134,192,83,34,150,114,116,40,179,64,86,160,83,
    37,127,225,210,91,100,238,36,242,136,70,241,239,66,146,100,
    181,28,104,133,21,118,215,38,165,230,213,156,34,5,89,117,
    127,232,141,142,2,239,201,49,109,70,59,250,185,131,25,57,
    251,141,50,251,228,28,226,109,18,240,235,163,92,140,151,115,
    138,18,63,70,218,5,251,236,19,65,236,115,104,120,222,151,
    246,72,142,142,240,28,218,15,199,118,119,232,245,216,58,102,
    38,222,23,185,120,138,205,123,185,244,72,31,82,27,219,126,
    28,97,8,63,241,85,156,216,129,196,195,153,12,236,239,219,
    28,255,237,48,181,189,35,252,234,249,74,131,253,162,199,114,
    157,235,37,189,148,75,218,227,83,234,206,209,186,46,158,189,
    67,44,239,71,80,36,92,125,40,44,194,57,23,238,218,119,
    48,55,226,177,75,77,116,244,162,50,196,217,163,230,187,48,
    223,168,255,33,48,216,32,37,149,85,197,182,81,51,212,218,
    69,135,125,70,235,210,171,110,251,219,111,226,182,250,90,39,
    115,222,106,126,31,180,0,146,143,108,116,101,83,205,174,108,
    208,163,23,254,91,143,102,127,152,163,39,168,255,169,35,59,
    143,255,79,220,59,63,129,44,191,191,205,137,69,89,180,21,
    189,118,32,242,35,70,89,46,190,211,184,125,29,130,92,63,
    145,158,146,218,80,59,115,19,149,131,129,222,250,116,230,153,
    87,75,225,167,133,84,231,92,219,76,110,177,253,244,249,138,
    237,39,14,163,187,88,19,91,92,19,239,83,77,60,101,21,
    184,134,46,139,103,208,172,20,154,32,223,143,228,169,123,69,
    27,186,240,37,222,188,241,88,70,129,243,16,202,181,44,127,
    158,19,22,40,250,188,134,82,161,97,138,91,88,188,94,245,
    68,138,175,37,41,217,144,149,194,247,230,103,82,70,239,159,
    114,244,54,233,96,49,11,178,206,62,53,28,86,139,136,234,
    252,12,242,40,91,224,51,144,67,169,228,85,195,40,90,154,
    157,119,3,137,217,38,158,224,193,131,203,120,124,31,186,238,
    60,195,243,79,51,33,249,240,132,225,89,84,141,154,89,171,
    214,4,103,189,75,247,188,154,39,42,91,117,177,58,73,29,
    246,238,213,66,110,190,141,204,51,15,233,137,143,87,7,222,
    72,223,34,241,253,136,243,109,200,78,177,206,251,133,18,233,
    132,207,39,4,125,30,67,68,115,70,230,4,236,252,136,198,
    31,96,51,122,180,151,139,179,167,197,121,150,196,71,242,243,
    48,85,50,146,137,190,86,227,155,209,209,35,181,125,237,2,
    148,63,155,182,118,233,123,144,120,216,223,184,52,154,202,36,
    244,134,225,107,125,221,150,15,43,226,247,237,28,80,164,187,
    102,156,147,225,229,216,197,64,72,100,143,102,38,76,247,154,
    149,153,75,147,181,212,253,107,99,95,153,202,28,1,164,203,
    78,125,94,126,66,133,120,250,49,54,116,175,86,91,173,33,
    152,200,215,77,60,166,174,8,203,92,110,212,172,229,165,154,
    85,91,48,249,26,100,5,15,27,117,171,182,180,44,244,191,
    93,132,93,221,216,197,117,255,1,113,18,209,188,
};

EmbeddedPython embedded_m5_internal_param_SimpleTrace(
    "m5/internal/param_SimpleTrace.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_SimpleTrace.py",
    "m5.internal.param_SimpleTrace",
    data_m5_internal_param_SimpleTrace,
    2189,
    6664);

} // anonymous namespace
