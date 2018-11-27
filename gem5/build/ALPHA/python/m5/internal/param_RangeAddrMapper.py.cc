#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RangeAddrMapper[] = {
    120,156,197,88,255,115,27,71,21,127,123,119,146,45,89,142,
    237,56,182,147,216,137,47,101,66,213,12,88,80,26,194,76,
    77,192,180,133,210,161,110,56,149,73,170,118,56,206,186,181,
    116,178,116,39,238,214,118,84,236,25,6,103,40,255,0,255,
    64,103,248,129,255,134,255,8,222,123,123,119,58,75,54,19,
    6,80,29,221,102,111,111,247,237,251,242,121,95,118,219,144,
    254,149,240,249,169,13,144,124,45,0,124,252,9,232,3,12,
    4,180,4,8,41,192,191,5,71,37,136,223,1,191,4,175,
    0,90,6,72,3,46,176,99,194,231,6,132,53,94,83,134,
    190,201,35,2,70,85,144,22,180,74,240,60,92,1,75,150,
    225,168,10,241,239,64,8,17,10,120,225,207,129,63,15,175,
    144,58,118,42,76,112,30,104,176,202,131,21,240,23,120,176,
    10,126,141,59,11,48,90,6,89,131,214,34,77,107,221,64,
    178,143,144,236,18,147,253,7,145,245,241,203,26,248,55,104,
    58,242,245,25,205,180,104,38,239,183,196,84,150,51,46,87,
    160,117,51,235,175,22,250,183,10,253,181,66,127,189,208,223,
    40,244,111,23,250,119,184,143,92,222,132,222,93,232,109,66,
    111,11,14,81,113,43,57,71,247,64,154,208,187,15,173,251,
    32,241,119,15,46,80,183,254,205,194,138,109,94,177,154,175,
    176,121,197,3,104,61,0,137,63,91,175,40,67,179,190,142,
    246,10,254,137,127,117,180,23,168,26,54,39,50,78,130,40,
    116,131,240,48,10,12,250,94,166,134,172,219,166,102,46,53,
    243,123,100,230,191,3,219,216,55,82,51,159,3,18,22,36,
    75,223,128,115,238,156,27,48,170,195,153,128,158,5,190,9,
    103,184,77,137,24,232,8,184,48,224,11,147,38,156,99,107,
    161,49,238,131,165,180,141,123,108,12,77,105,14,206,75,112,
    86,130,230,139,51,131,6,142,42,16,255,13,190,220,98,162,
    243,76,212,128,51,108,45,184,176,224,188,12,207,113,18,14,
    245,42,36,190,120,113,134,146,226,72,179,110,33,183,251,5,
    113,73,20,63,136,67,111,32,21,105,194,29,122,177,55,112,
    29,47,236,200,61,223,143,63,246,134,67,25,215,171,217,220,
    40,217,25,122,170,235,240,98,147,180,50,24,42,38,26,133,
    82,45,96,231,48,8,125,119,16,249,199,125,169,230,137,162,
    123,24,244,165,235,242,199,95,14,134,81,172,62,136,227,40,
    118,72,177,60,216,143,188,124,5,169,181,221,143,18,89,167,
    221,120,27,135,200,43,154,125,56,100,138,196,0,51,76,139,
    125,153,180,227,96,168,208,94,154,34,205,38,106,117,178,20,
    55,201,231,216,52,186,209,64,54,78,2,255,56,233,6,141,
    95,200,193,251,113,20,248,238,65,20,29,37,193,160,209,145,
    131,199,141,131,227,160,239,55,246,126,245,236,195,189,198,112,
    164,186,81,216,192,209,32,84,18,21,212,111,92,169,154,29,
    156,120,147,54,57,13,58,110,192,226,185,93,217,199,47,139,
    52,122,151,24,16,203,162,38,202,194,20,117,177,136,189,18,
    62,166,216,50,22,196,126,64,2,182,73,104,66,152,85,196,
    20,25,90,192,145,1,241,22,33,166,135,63,65,38,70,220,
    52,233,155,193,223,126,77,154,209,163,61,147,112,160,7,207,
    24,101,8,55,156,185,75,134,15,129,161,82,130,94,25,52,
    132,16,121,26,83,241,136,90,156,78,100,12,36,110,65,242,
    87,64,77,35,120,206,32,5,214,133,9,34,92,6,85,165,
    88,128,163,235,184,225,159,24,155,205,58,177,191,207,232,80,
    221,32,137,78,67,182,1,245,217,155,154,168,153,103,163,79,
    14,122,178,173,146,109,28,248,44,58,182,219,94,24,70,202,
    246,124,223,246,148,138,131,131,99,37,19,91,69,246,195,164,
    78,102,117,86,50,128,229,244,70,195,12,80,100,124,4,148,
    126,241,131,182,194,151,85,126,97,43,36,82,33,56,186,145,
    159,224,56,145,232,72,229,16,147,138,148,28,49,35,140,29,
    151,166,210,246,56,239,6,190,239,101,156,48,64,235,229,12,
    78,137,236,31,170,42,35,211,75,18,151,57,161,113,6,33,
    17,62,241,250,199,146,169,39,72,15,25,162,174,230,97,134,
    48,188,77,34,101,26,96,177,194,40,244,71,200,101,208,126,
    147,24,184,205,96,172,49,28,215,16,138,115,216,150,241,255,
    178,88,55,218,86,10,192,114,6,66,10,7,10,24,2,34,
    69,1,2,242,2,131,80,221,224,40,194,146,177,135,190,65,
    61,90,236,108,81,115,143,154,251,212,108,103,194,207,70,3,
    139,147,26,120,66,187,26,44,54,11,72,198,50,51,1,253,
    75,94,118,103,236,101,24,50,155,228,45,6,249,212,216,91,
    44,10,175,241,83,106,113,42,251,161,9,201,167,20,204,201,
    171,152,24,57,16,186,2,245,198,14,194,234,114,150,73,13,
    243,25,182,29,2,108,17,181,157,2,106,29,178,20,67,214,
    185,147,69,73,151,102,104,176,58,155,68,170,116,133,190,109,
    106,30,204,86,233,99,216,117,166,96,247,46,49,176,156,194,
    110,145,225,86,197,103,217,104,155,169,37,242,60,186,58,1,
    55,194,154,117,5,214,190,77,61,115,90,246,111,4,102,169,
    196,63,47,192,140,152,52,138,130,237,99,103,180,65,242,20,
    1,182,129,165,193,243,112,3,179,189,193,217,254,123,156,237,
    185,98,224,58,75,7,112,147,99,184,238,148,72,49,135,38,
    172,167,89,60,169,96,59,140,163,151,35,59,58,180,21,75,
    78,241,118,247,97,178,243,48,121,23,35,169,253,148,99,152,
    142,165,58,90,198,114,72,209,142,150,126,240,178,45,57,111,
    242,155,235,234,224,230,114,160,115,211,124,140,88,91,35,181,
    26,153,190,57,204,39,42,166,232,62,67,141,87,115,141,147,
    0,31,209,150,85,86,183,41,54,16,87,85,193,124,185,58,
    182,115,141,198,95,241,249,25,153,128,100,151,64,21,184,211,
    212,92,179,64,36,154,243,157,75,216,153,137,56,78,3,233,
    255,38,195,76,121,140,25,122,204,204,25,190,2,174,97,5,
    252,25,8,21,104,252,212,25,114,223,33,24,172,210,244,223,
    2,123,205,21,245,2,199,161,38,213,8,60,3,195,83,242,
    132,167,234,242,225,35,248,75,193,229,178,36,111,166,85,106,
    49,201,91,121,12,99,56,189,86,34,183,46,7,59,50,81,
    215,75,104,154,142,96,99,47,30,39,139,188,176,196,8,62,
    27,108,205,235,205,92,226,235,139,49,178,40,77,110,138,85,
    163,128,151,239,83,243,118,14,21,145,141,253,223,89,220,134,
    235,51,187,171,179,6,177,144,88,204,249,210,156,90,34,214,
    46,211,201,189,162,148,121,197,219,185,87,72,206,113,175,248,
    32,67,173,65,0,184,48,4,158,64,177,220,163,3,159,5,
    178,4,173,50,249,15,151,232,34,117,47,145,69,57,138,137,
    151,18,40,171,103,95,43,46,199,128,54,47,53,47,103,24,
    61,200,194,187,125,111,112,224,123,79,35,218,144,118,109,103,
    14,103,100,34,44,23,69,32,103,17,215,73,193,175,143,51,
    81,78,102,24,57,126,136,244,115,17,216,79,252,168,205,225,
    226,211,174,180,7,114,112,128,103,215,110,48,180,15,251,94,
    135,173,100,166,34,126,146,137,168,216,204,147,229,73,242,136,
    218,200,110,71,33,134,247,227,182,138,98,219,151,120,152,147,
    190,253,93,155,115,131,29,36,182,119,128,95,189,182,210,224,
    191,236,197,92,19,123,113,39,225,242,247,232,148,186,51,182,
    178,139,103,246,0,143,3,191,135,60,33,235,131,100,30,234,
    185,208,215,190,132,185,19,151,170,145,142,106,84,170,56,59,
    212,188,5,179,207,8,239,32,253,144,54,34,213,149,197,166,
    81,49,212,218,180,19,63,163,245,201,180,43,159,190,142,43,
    235,107,164,212,161,203,52,83,206,209,237,1,181,21,74,13,
    173,106,54,184,192,109,141,7,23,179,155,170,27,60,184,196,
    183,63,101,30,89,161,120,48,247,223,198,3,246,164,25,251,
    208,203,255,105,24,112,158,124,131,18,56,63,130,180,98,184,
    46,4,136,162,120,139,58,4,244,68,118,136,41,202,198,55,
    40,91,215,225,206,109,199,210,83,82,27,109,107,166,34,115,
    72,209,219,255,97,236,219,211,197,246,94,46,221,5,87,77,
    163,91,108,75,125,146,99,91,138,231,225,93,172,186,45,174,
    186,119,169,234,62,99,85,184,134,46,188,199,80,45,229,26,
    161,67,88,40,79,39,249,210,90,209,229,53,241,71,131,161,
    239,60,130,98,197,204,159,103,136,13,138,99,127,132,66,25,
    99,138,91,88,34,79,123,40,69,235,130,180,108,212,82,238,
    147,179,53,47,35,250,171,12,209,117,186,80,27,135,108,103,
    151,26,14,210,121,124,118,126,146,27,231,173,107,225,26,197,
    65,39,192,109,221,152,62,39,116,90,251,15,102,99,169,197,
    117,212,196,248,191,161,16,203,1,189,250,175,183,223,228,236,
    108,191,137,113,54,40,251,164,47,251,82,201,171,65,168,72,
    61,233,77,130,143,76,198,209,8,143,114,124,40,194,247,190,
    235,206,58,161,253,24,233,83,86,226,112,138,9,77,148,49,
    165,173,137,53,163,82,174,8,174,25,38,110,214,53,111,116,
    147,164,203,255,81,226,112,116,91,202,13,205,119,191,89,206,
    38,76,240,193,117,223,27,232,251,58,190,133,114,190,5,233,
    29,129,243,102,14,24,114,95,62,115,233,147,46,122,50,215,
    51,92,190,56,63,200,212,59,120,188,147,137,181,67,178,176,
    80,238,137,164,82,136,175,159,7,143,167,230,105,241,199,146,
    171,205,43,39,124,44,7,250,254,147,43,249,233,239,239,245,
    163,246,145,244,211,57,247,174,159,243,126,52,240,112,252,234,
    93,154,65,182,203,202,196,119,63,166,85,107,19,163,137,140,
    3,175,31,124,169,175,85,179,97,70,210,148,92,20,76,198,
    175,92,174,92,149,39,24,128,177,236,4,9,18,99,74,83,
    209,146,128,161,222,184,214,43,138,4,102,140,89,125,78,208,
    23,31,79,233,202,45,249,16,27,186,44,173,44,85,16,191,
    20,74,77,81,197,96,106,153,181,229,138,85,91,168,88,149,
    57,147,239,180,22,241,164,88,181,42,11,53,113,249,223,54,
    162,189,106,108,175,84,196,191,0,211,76,121,242,
};

EmbeddedPython embedded_m5_internal_param_RangeAddrMapper(
    "m5/internal/param_RangeAddrMapper.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_RangeAddrMapper.py",
    "m5.internal.param_RangeAddrMapper",
    data_m5_internal_param_RangeAddrMapper,
    2301,
    7201);

} // anonymous namespace
