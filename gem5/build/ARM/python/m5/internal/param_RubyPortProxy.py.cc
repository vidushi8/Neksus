#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RubyPortProxy[] = {
    120,156,197,88,123,115,219,198,17,223,3,64,74,164,68,75,
    178,100,203,15,57,130,227,40,97,51,141,152,164,117,211,135,
    199,83,55,110,51,237,140,21,5,204,140,29,246,129,66,192,
    137,4,69,0,28,224,36,135,25,233,159,202,211,246,191,126,
    136,78,255,232,247,232,39,200,23,106,119,247,0,8,164,228,
    78,102,218,161,37,226,102,113,143,189,125,252,118,111,15,62,
    228,127,53,124,126,110,3,100,223,10,128,0,127,2,70,0,
    145,128,158,0,33,5,4,235,112,84,131,244,135,16,212,224,
    21,64,207,0,105,192,57,18,38,252,214,128,120,153,215,212,
    97,100,114,143,128,73,19,164,5,189,26,60,143,215,192,146,
    117,56,106,66,250,71,16,66,196,2,94,4,11,16,44,194,
    43,228,142,68,131,25,46,66,208,100,162,1,193,18,19,77,
    152,172,130,92,130,30,50,95,128,94,11,89,189,143,172,174,
    49,171,127,17,171,0,71,54,32,104,209,116,148,229,43,154,
    105,209,76,222,227,26,115,89,41,36,91,133,222,90,65,95,
    175,208,235,21,122,163,66,223,168,208,55,43,244,102,133,190,
    85,161,111,87,232,59,21,250,110,133,222,170,208,247,152,94,
    1,185,6,195,183,96,184,13,67,27,14,209,208,171,165,54,
    247,65,154,48,124,27,122,111,131,196,223,125,56,71,95,4,
    107,149,21,15,120,197,245,114,197,59,188,98,7,122,59,32,
    241,247,142,94,81,135,110,251,6,250,55,252,55,254,181,209,
    191,160,150,177,57,145,105,22,38,177,27,198,135,73,104,208,
    120,157,26,66,131,79,205,66,14,139,79,9,22,255,4,198,
    68,96,228,176,56,3,100,44,72,151,145,1,103,76,156,25,
    48,105,195,169,128,161,5,129,9,167,184,77,141,4,232,11,
    56,55,224,119,38,77,56,195,214,66,71,190,5,150,210,152,
    24,178,35,53,167,5,56,171,193,105,13,186,47,78,13,234,
    56,106,64,250,15,248,102,139,153,46,50,83,3,78,177,181,
    224,220,130,179,58,60,199,73,216,53,108,144,250,226,197,41,
    106,138,61,221,182,133,210,238,85,212,37,85,130,48,141,189,
    72,170,13,164,221,177,151,122,145,235,28,31,76,246,147,84,
    237,167,201,215,147,118,179,152,153,100,187,99,79,13,28,94,
    106,146,77,162,177,98,150,73,44,213,18,18,135,97,28,184,
    81,18,28,143,164,90,36,126,238,97,56,146,174,203,131,191,
    142,198,200,243,151,105,154,164,14,153,149,59,71,137,87,174,
    32,163,250,163,36,147,109,218,141,183,113,136,189,162,217,135,
    99,230,72,2,176,184,180,56,144,153,159,134,99,133,222,210,
    28,105,54,113,107,147,159,184,201,126,143,77,39,240,148,247,
    81,103,144,68,178,115,18,6,199,217,32,236,124,38,163,167,
    105,18,6,238,65,146,28,101,97,212,233,203,232,97,231,224,
    56,28,5,157,39,206,179,206,120,162,6,73,220,193,190,48,
    86,18,77,52,234,92,97,156,93,156,118,157,182,121,25,246,
    221,144,21,116,7,114,52,150,41,201,151,221,33,17,196,170,
    88,22,117,97,138,182,104,33,85,195,199,20,91,198,146,216,
    11,73,69,159,212,38,132,153,5,166,254,14,236,61,116,254,
    145,1,233,22,33,102,136,63,65,46,70,220,116,105,204,224,
    177,47,200,54,186,119,104,18,14,116,231,41,163,12,225,134,
    51,31,145,227,99,96,168,212,96,88,7,13,33,68,158,198,
    84,58,161,22,167,19,27,3,153,91,144,253,109,154,67,188,
    10,104,123,204,32,216,117,19,183,250,19,163,178,219,38,193,
    247,24,25,106,16,102,201,203,152,237,79,52,199,81,23,109,
    178,63,249,252,96,40,125,149,109,99,199,87,201,177,237,123,
    113,156,40,219,11,2,219,83,42,13,15,142,149,204,108,149,
    216,59,89,187,65,14,95,43,192,85,242,155,140,11,48,145,
    227,17,76,250,37,8,125,133,47,235,252,194,246,207,164,66,
    96,12,146,32,195,126,98,209,151,202,33,33,213,53,108,158,
    20,219,49,2,219,245,2,47,153,28,29,170,38,67,207,203,
    50,151,183,163,126,70,25,173,62,241,70,199,82,209,252,76,
    121,10,119,37,82,111,52,87,156,221,34,77,11,69,201,120,
    110,156,196,193,4,229,12,253,7,36,194,45,70,219,50,16,
    222,110,32,214,22,176,173,67,11,177,183,106,248,164,146,149,
    35,141,81,118,147,12,0,236,121,145,231,15,68,220,57,102,
    153,182,193,105,130,117,227,32,180,137,162,197,14,1,218,185,
    75,205,22,53,247,10,245,231,101,131,214,172,13,62,164,125,
    13,86,220,55,115,21,203,64,218,155,10,164,219,23,129,132,
    89,177,75,1,97,80,216,92,4,132,73,70,72,31,231,232,
    167,80,67,0,224,112,5,243,108,26,103,149,84,174,23,112,
    117,8,131,85,32,246,43,64,116,200,43,140,66,231,246,235,
    204,184,253,230,204,216,215,102,252,1,237,187,156,227,167,197,
    184,105,10,159,156,111,228,70,101,131,62,69,98,178,73,6,
    173,154,114,19,207,185,231,113,139,15,44,62,244,184,204,208,
    25,68,91,88,19,22,33,237,208,132,155,249,65,148,81,192,
    143,73,38,59,57,180,21,20,50,60,218,201,118,119,178,159,
    97,74,176,31,115,146,209,73,65,135,125,42,199,41,134,119,
    131,95,116,200,186,28,190,110,126,140,160,201,233,80,103,79,
    177,161,57,67,101,42,165,196,52,87,43,55,75,43,147,208,
    63,161,77,155,108,98,19,54,241,105,10,150,204,77,56,67,
    114,105,193,163,248,252,130,140,77,250,74,160,66,211,233,106,
    185,89,37,82,206,121,111,10,49,115,82,200,121,159,68,43,
    2,174,14,37,62,232,49,73,100,138,129,191,0,23,95,2,
    254,12,132,5,116,121,30,53,28,159,244,144,75,215,105,250,
    31,128,147,207,21,7,157,161,163,207,200,211,19,6,103,246,
    9,79,213,231,222,111,224,175,149,204,117,110,130,160,51,202,
    204,203,171,234,25,101,149,241,202,32,250,78,231,144,53,29,
    216,228,164,129,151,209,52,29,194,102,25,194,23,73,176,172,
    137,48,47,205,11,95,139,122,59,151,36,251,236,2,93,116,
    0,220,21,235,70,5,51,223,167,230,131,18,46,162,232,155,
    131,144,219,179,25,187,114,106,185,58,75,254,138,36,177,88,
    246,149,58,231,166,41,46,101,100,212,138,200,248,184,140,12,
    201,185,251,21,215,224,212,26,4,129,115,67,224,101,11,235,
    21,186,231,88,32,107,208,171,83,12,113,125,41,242,16,19,
    69,78,163,253,166,14,6,54,207,158,54,92,137,2,237,96,
    106,190,158,107,14,33,31,63,26,121,209,65,224,61,166,112,
    201,104,95,191,8,58,163,80,98,181,170,4,5,140,120,157,
    30,252,250,97,161,204,201,92,243,199,71,184,67,169,4,71,
    75,144,248,156,52,190,28,72,59,146,209,1,94,189,6,225,
    216,62,28,121,125,246,148,153,43,249,121,161,164,98,87,207,
    30,200,25,101,166,189,196,246,147,24,19,253,177,175,146,212,
    14,36,222,70,100,96,127,96,243,41,97,135,153,237,29,224,
    168,231,43,29,0,211,177,204,53,159,151,246,51,46,239,142,
    94,18,57,119,79,187,120,233,12,177,170,117,11,35,233,155,
    80,153,242,185,144,213,209,132,231,38,222,50,212,68,231,182,
    31,81,243,61,106,118,224,77,156,12,29,220,129,118,201,200,
    120,117,76,63,13,193,5,209,212,196,125,90,155,93,14,231,
    103,223,37,156,245,87,147,60,168,235,197,231,150,5,144,139,
    116,205,237,53,233,219,1,245,44,81,164,47,252,175,145,206,
    17,50,247,216,144,255,215,0,119,62,126,163,58,56,92,83,
    254,183,224,22,85,5,91,58,184,135,162,40,189,171,218,241,
    229,254,206,213,120,114,253,84,122,74,106,183,221,153,179,202,
    156,44,180,0,253,210,121,133,94,229,61,228,147,82,183,115,
    174,137,38,27,149,218,152,125,41,158,99,1,131,245,243,41,
    171,239,26,186,132,190,128,168,85,90,97,19,155,88,190,116,
    175,176,132,46,147,73,34,111,60,150,113,112,81,2,243,200,
    92,161,64,9,105,0,23,53,9,214,187,27,248,92,14,74,
    210,172,162,40,123,177,86,134,225,188,253,201,16,142,10,79,
    182,233,54,114,145,125,29,242,163,206,183,101,170,117,126,10,
    69,250,45,65,26,200,145,84,242,42,15,41,90,156,95,18,
    3,137,135,81,50,193,219,11,223,2,240,125,228,186,243,207,
    220,63,214,246,215,55,47,202,220,117,204,221,13,171,33,248,
    104,156,249,254,169,37,123,23,138,90,119,146,57,28,234,43,
    165,254,252,141,174,56,154,24,247,116,83,219,243,34,253,217,
    133,63,37,56,247,169,121,80,216,145,17,171,47,65,124,195,
    208,119,59,196,56,159,219,124,76,59,187,133,109,163,135,187,
    133,70,187,211,26,241,87,194,232,33,127,38,185,60,171,59,
    201,148,140,212,221,153,65,25,31,71,238,51,25,37,233,228,
    89,18,72,117,127,102,252,73,94,49,232,41,238,137,164,210,
    66,217,87,110,49,61,247,210,86,122,18,14,234,47,98,92,
    24,95,30,255,116,148,248,71,50,200,231,220,123,253,156,167,
    73,228,97,255,213,187,116,195,98,151,181,153,241,32,165,85,
    55,102,122,51,153,134,222,40,252,70,170,173,89,3,4,65,
    234,120,113,95,22,186,207,78,184,112,66,110,98,66,64,49,
    202,245,202,140,155,22,43,105,156,235,134,203,137,157,3,36,
    149,253,16,25,166,204,163,28,214,137,142,64,203,94,184,234,
    60,168,46,158,123,60,233,130,93,127,137,120,76,64,206,246,
    177,161,47,114,141,149,134,168,27,244,237,215,20,77,209,18,
    150,88,110,53,204,70,189,81,51,49,230,168,103,93,52,205,
    70,115,89,188,238,127,27,163,178,105,108,55,27,226,63,197,
    29,34,85,
};

EmbeddedPython embedded_m5_internal_param_RubyPortProxy(
    "m5/internal/param_RubyPortProxy.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_RubyPortProxy.py",
    "m5.internal.param_RubyPortProxy",
    data_m5_internal_param_RubyPortProxy,
    2195,
    6815);

} // anonymous namespace
