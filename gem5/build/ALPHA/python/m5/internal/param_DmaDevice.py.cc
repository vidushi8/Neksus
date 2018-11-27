#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_DmaDevice[] = {
    120,156,197,88,253,114,219,198,17,223,3,64,74,164,40,75,
    178,44,201,31,178,69,59,81,195,122,26,177,77,227,186,51,
    81,61,85,227,180,73,166,81,84,48,25,219,74,166,40,68,
    156,72,80,4,192,1,142,178,153,82,51,157,202,211,244,5,
    250,8,253,35,111,211,233,11,181,187,123,0,4,81,210,76,
    58,173,89,153,56,31,14,119,123,251,241,219,143,187,54,164,
    127,37,124,126,89,7,72,254,41,0,60,252,9,232,3,4,
    2,246,5,8,41,192,187,1,71,37,136,223,7,175,4,175,
    1,246,13,144,6,156,98,199,132,175,12,8,107,188,166,12,
    125,147,71,4,140,170,32,45,216,47,193,179,112,9,44,89,
    134,163,42,196,127,0,33,68,40,224,185,55,3,222,44,188,
    70,234,216,169,48,193,89,160,193,42,15,86,192,155,227,193,
    42,120,53,238,204,193,104,17,100,13,246,231,105,218,254,53,
    36,251,16,201,46,48,217,127,16,89,15,191,172,128,119,141,
    166,35,95,47,104,166,69,51,121,191,5,166,178,152,113,185,
    4,251,215,179,254,114,161,127,163,208,95,41,244,87,11,253,
    181,66,255,102,161,127,171,208,191,93,232,223,41,244,215,11,
    253,187,220,71,169,174,67,239,30,244,54,160,87,135,67,84,
    244,82,46,193,125,144,38,244,30,192,254,3,144,248,187,15,
    167,104,11,239,122,97,197,91,188,98,57,95,241,54,175,216,
    132,253,77,144,248,123,91,175,40,67,171,177,138,246,245,255,
    133,127,13,180,47,168,26,54,199,50,78,252,40,116,252,240,
    48,242,13,250,94,166,134,208,208,166,102,38,133,197,135,4,
    139,239,128,49,225,25,41,44,78,0,9,11,146,165,111,192,
    9,119,78,12,24,53,96,44,160,103,129,103,194,24,183,41,
    17,3,29,1,167,6,124,109,210,132,19,108,45,52,222,61,
    176,148,198,68,143,141,167,41,205,192,73,9,198,37,104,61,
    31,27,52,112,84,129,248,239,240,205,58,19,157,101,162,6,
    140,177,181,224,212,130,147,50,60,195,73,56,212,171,144,248,
    226,249,24,37,197,145,86,195,66,110,119,11,226,146,40,158,
    31,135,110,32,213,34,246,157,129,27,187,129,243,52,112,159,
    202,99,191,45,27,213,108,86,148,108,13,92,213,181,121,153,
    73,250,8,6,138,201,69,161,84,115,216,57,244,67,207,9,
    34,111,216,151,106,150,104,57,135,126,95,58,14,127,252,36,
    24,68,177,250,40,142,163,216,38,149,242,96,63,114,243,21,
    164,208,118,63,74,100,131,118,227,109,108,34,175,104,246,225,
    128,41,18,3,204,42,45,246,100,210,142,253,129,66,75,105,
    138,52,155,168,53,200,70,220,36,95,98,211,236,70,129,108,
    30,251,222,48,233,250,205,223,200,224,105,28,249,158,115,16,
    69,71,137,31,52,59,50,120,212,60,24,250,125,175,185,243,
    219,189,143,119,154,131,145,234,70,97,19,71,253,80,73,84,
    77,191,57,161,148,45,156,114,157,200,191,244,59,142,207,130,
    57,93,217,31,200,120,158,70,111,211,214,98,81,212,68,89,
    152,162,33,230,177,87,194,199,20,235,198,156,216,245,73,180,
    54,137,75,168,178,138,56,34,227,10,56,50,32,94,39,148,
    244,240,39,200,172,136,149,22,125,51,248,219,239,72,39,122,
    180,103,146,237,245,224,152,145,133,16,195,153,219,100,236,16,
    24,30,37,232,149,65,195,6,209,166,113,20,143,168,197,233,
    68,198,64,226,22,36,127,3,212,49,2,102,12,41,152,78,
    77,16,225,34,168,42,197,11,28,93,197,13,255,204,120,108,
    53,136,253,93,198,133,234,250,73,244,50,100,237,83,159,61,
    168,133,154,217,27,125,126,208,147,109,149,108,224,192,139,104,
    88,111,187,97,24,169,186,235,121,117,87,169,216,63,24,42,
    153,212,85,84,223,76,26,100,80,123,41,131,86,78,111,52,
    200,160,68,102,71,40,233,23,207,111,43,124,89,230,23,182,
    66,34,21,194,162,27,121,9,142,19,137,142,84,54,49,169,
    72,201,17,51,194,168,113,104,42,109,143,243,174,225,251,78,
    198,9,67,179,81,206,128,148,200,254,161,170,50,38,221,36,
    113,152,19,26,103,248,17,225,99,183,63,148,76,61,65,122,
    200,16,117,53,15,83,1,224,77,18,38,147,157,5,10,163,
    208,27,33,127,126,251,29,218,250,38,195,176,198,64,92,65,
    16,206,96,91,198,255,203,98,213,104,91,41,244,202,25,252,
    40,12,42,96,227,139,212,254,8,197,83,12,57,13,131,99,
    6,203,196,94,249,128,122,180,216,94,167,230,46,53,247,168,
    217,200,196,126,211,178,207,79,202,254,152,246,51,88,96,22,
    141,12,100,102,162,121,231,60,235,214,153,103,97,104,108,145,
    135,24,228,71,103,30,98,81,24,141,159,80,139,83,217,247,
    76,72,190,160,160,77,158,196,196,200,105,16,254,212,59,115,
    10,86,148,77,97,180,49,155,225,217,38,144,22,145,218,41,
    32,213,38,27,49,76,237,91,89,76,116,104,134,6,168,125,
    135,72,149,46,209,116,157,154,251,211,82,247,25,212,58,23,
    160,246,1,109,189,152,66,109,158,33,86,197,103,209,104,155,
    169,13,242,76,185,60,1,49,194,151,117,9,190,126,64,61,
    243,162,212,83,134,86,42,235,175,11,208,34,246,140,162,72,
    187,216,25,173,145,36,69,80,173,97,218,127,22,174,97,38,
    55,56,147,255,152,51,57,87,3,92,115,233,64,109,114,172,
    214,157,18,169,228,208,132,213,52,67,39,21,108,7,113,244,
    106,84,143,14,235,138,101,166,184,186,189,153,108,109,38,31,
    96,196,172,63,225,88,165,99,166,142,138,177,28,80,84,163,
    165,31,189,106,75,206,140,252,230,56,58,136,57,28,208,156,
    52,227,34,190,86,72,161,70,166,105,14,231,137,138,41,138,
    79,69,215,213,92,215,196,250,167,180,89,149,21,109,138,53,
    196,82,85,48,71,142,142,222,92,121,241,87,124,126,69,202,
    39,169,37,80,29,110,183,52,191,44,10,9,101,255,232,28,
    94,222,176,32,118,19,41,127,153,225,164,124,134,19,122,204,
    12,250,223,2,215,164,2,254,2,132,4,52,120,10,253,220,
    83,200,244,203,52,253,247,192,62,114,73,45,192,241,166,69,
    249,159,103,96,24,74,30,243,84,93,26,124,10,127,45,56,
    88,150,192,205,180,234,44,38,112,43,143,85,12,161,239,149,
    164,173,243,65,141,140,211,117,19,154,166,35,213,153,207,158,
    165,131,188,92,196,72,253,166,241,52,171,183,113,136,163,175,
    207,208,68,41,240,142,88,54,10,24,249,9,53,239,229,240,
    16,217,216,27,100,110,3,174,206,215,142,206,8,95,17,7,
    22,243,188,48,195,158,155,83,200,209,95,202,208,255,94,142,
    126,201,153,235,53,31,67,168,53,200,220,167,134,192,243,38,
    22,110,116,188,179,64,150,96,191,76,126,194,101,182,72,221,
    72,100,113,140,162,222,185,180,200,42,217,213,202,202,45,174,
    141,73,205,171,169,196,7,178,231,118,223,13,14,60,247,73,
    66,91,209,126,237,204,177,140,140,249,197,34,243,228,20,226,
    42,254,249,245,81,38,196,241,84,98,195,207,82,198,153,121,
    246,4,47,106,115,64,248,162,43,235,129,12,14,240,180,217,
    245,7,245,195,190,219,97,203,152,169,112,159,103,194,41,54,
    237,100,161,145,60,164,54,170,183,163,16,131,246,176,173,162,
    184,238,73,60,132,73,175,254,110,157,35,126,221,79,234,238,
    1,126,117,219,74,131,252,188,159,114,69,235,198,157,132,139,
    215,163,151,212,157,154,101,29,60,95,251,88,198,15,33,79,
    176,250,232,151,7,112,46,208,181,207,96,46,196,227,149,26,
    233,136,69,69,135,189,69,205,15,97,154,113,254,125,164,28,
    211,22,164,174,178,184,99,84,12,181,80,116,211,61,90,147,
    92,116,214,23,223,199,89,245,181,16,78,144,101,232,205,112,
    59,75,17,158,110,125,172,244,214,135,6,231,96,191,150,221,
    54,205,147,79,151,255,91,159,102,159,152,154,55,140,255,167,
    174,108,63,254,191,240,110,255,28,210,188,126,149,27,159,43,
    20,119,180,27,107,75,96,246,31,221,96,57,245,201,131,229,
    20,207,194,219,88,49,90,92,49,110,83,197,56,230,170,210,
    49,116,209,120,102,64,62,16,240,141,7,109,31,202,151,206,
    4,254,116,81,72,168,112,7,3,25,122,246,67,40,214,121,
    252,121,42,26,35,63,253,19,20,18,177,41,110,96,97,119,
    17,171,20,135,10,18,50,38,75,57,58,215,167,105,225,111,
    51,11,55,174,157,11,70,246,54,53,139,231,34,143,182,194,
    187,23,35,128,195,119,66,94,224,58,24,157,67,172,94,233,
    58,177,29,13,67,69,199,138,255,112,5,214,11,138,142,135,
    87,206,96,61,43,58,193,123,178,47,149,156,196,131,190,217,
    211,129,212,147,152,14,162,17,158,5,184,182,198,247,190,227,
    76,47,130,254,2,41,255,17,210,211,12,70,80,60,42,174,
    24,149,114,69,112,82,154,184,108,213,28,209,113,80,87,144,
    163,196,102,215,91,200,85,207,151,130,89,106,32,3,113,213,
    180,235,6,250,58,135,175,42,236,183,32,61,84,218,239,228,
    214,35,125,114,217,174,15,72,232,68,156,48,57,63,218,63,
    165,113,234,5,143,182,50,97,182,180,48,123,126,164,133,225,
    107,201,224,17,159,141,47,78,107,141,18,37,131,11,52,100,
    56,12,156,207,100,16,197,163,207,34,79,170,251,19,223,119,
    210,92,173,167,56,199,146,146,186,170,95,186,197,249,185,87,
    176,139,31,245,37,28,151,159,23,191,127,216,143,218,71,210,
    75,231,220,189,122,206,211,40,112,113,252,242,93,90,126,182,
    203,210,196,119,47,166,85,43,19,163,137,140,125,183,239,127,
    35,213,250,164,2,60,47,182,221,176,35,51,217,201,192,217,
    87,78,181,147,102,32,243,229,111,156,160,217,17,114,208,49,
    234,99,217,241,209,32,49,83,200,103,167,193,146,32,201,140,
    76,122,100,113,229,212,60,68,23,189,250,132,254,132,238,131,
    146,61,108,232,14,175,178,80,17,101,131,98,168,137,71,227,
    121,97,153,181,197,138,85,155,171,88,149,25,147,175,93,230,
    241,144,83,181,42,115,53,113,249,191,13,244,179,170,177,49,
    95,17,255,6,115,143,18,175,
};

EmbeddedPython embedded_m5_internal_param_DmaDevice(
    "m5/internal/param_DmaDevice.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_DmaDevice.py",
    "m5.internal.param_DmaDevice",
    data_m5_internal_param_DmaDevice,
    2296,
    6878);

} // anonymous namespace
