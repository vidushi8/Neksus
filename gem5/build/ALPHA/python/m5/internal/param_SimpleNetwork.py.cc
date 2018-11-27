#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_SimpleNetwork[] = {
    120,156,197,88,109,115,219,198,17,222,3,64,74,164,36,235,
    93,242,139,98,49,73,101,211,158,86,106,211,184,238,76,92,
    183,142,227,180,201,100,20,23,76,199,54,147,41,10,17,71,
    17,20,8,112,128,147,100,102,164,105,167,242,244,101,166,31,
    250,165,63,161,31,250,111,250,143,154,221,61,0,132,36,178,
    163,78,91,198,34,207,203,195,98,239,118,247,217,151,187,22,
    164,255,74,248,253,89,13,32,49,12,0,15,63,2,2,128,
    158,128,166,0,33,5,120,43,112,80,130,248,125,240,74,240,
    6,160,105,128,52,224,12,9,19,190,52,32,156,229,119,202,
    16,152,60,35,96,80,5,105,65,179,4,47,194,69,176,100,
    25,14,170,16,255,6,132,16,161,128,151,222,20,120,211,240,
    6,165,35,81,97,129,211,64,147,85,158,172,128,55,195,147,
    85,240,102,153,152,129,193,2,200,89,104,206,17,91,243,26,
    138,189,143,98,231,89,236,63,73,172,135,79,86,193,187,70,
    236,184,175,87,196,105,17,39,175,55,207,82,22,178,93,46,
    66,115,41,163,151,11,244,74,129,94,45,208,107,5,122,189,
    64,95,47,208,55,10,244,205,2,125,171,64,111,20,232,183,
    10,244,237,2,189,89,160,107,5,250,109,166,209,10,75,208,
    125,7,186,239,66,247,59,208,70,199,44,230,26,111,129,52,
    161,123,7,154,119,64,226,103,11,206,208,119,222,82,225,141,
    187,252,198,114,254,70,157,223,184,7,205,123,32,241,83,215,
    111,148,161,81,95,67,60,248,255,194,127,117,129,148,154,197,
    225,72,198,137,31,133,142,31,182,35,223,160,231,101,26,8,
    61,45,26,166,82,24,61,37,24,253,3,24,67,158,145,194,
    232,20,80,176,32,93,2,3,78,153,56,53,96,80,135,19,
    1,93,11,60,19,78,112,153,18,109,96,95,192,153,1,95,
    153,196,112,138,163,133,206,190,13,150,210,24,234,178,179,181,
    164,41,56,45,193,73,9,26,47,79,12,154,56,168,64,252,
    119,248,122,131,133,78,179,80,3,78,112,180,224,204,130,211,
    50,188,64,38,156,234,86,72,125,241,242,4,53,197,153,70,
    221,194,221,238,22,212,37,85,60,63,14,221,158,84,43,72,
    59,125,55,118,123,78,195,239,245,3,185,43,213,113,20,31,
    212,171,25,103,148,108,247,93,213,177,249,85,147,108,210,235,
    43,22,25,133,82,205,32,209,246,67,207,233,69,222,97,32,
    213,52,201,115,218,126,32,29,135,31,126,210,235,71,177,122,
    22,199,81,108,147,89,121,50,136,220,252,13,50,106,43,136,
    18,89,167,213,120,25,155,196,43,226,110,247,89,34,109,128,
    183,75,47,123,50,105,197,126,95,161,183,180,68,226,38,105,
    117,242,19,15,201,43,28,118,58,81,79,238,28,249,222,97,
    210,241,119,126,46,123,31,197,145,239,57,123,81,116,144,248,
    189,157,125,217,123,176,179,119,232,7,222,206,147,207,158,255,
    226,201,78,127,160,58,81,184,131,179,126,168,36,154,39,216,
    25,97,152,109,100,91,162,37,142,253,125,199,103,229,156,142,
    12,250,50,158,163,217,155,180,188,88,16,179,162,44,76,81,
    23,115,72,149,240,107,138,13,99,70,236,250,164,94,139,84,
    38,116,89,69,60,145,147,5,28,24,16,111,16,90,186,248,
    17,228,94,196,76,131,158,25,252,236,151,100,23,61,219,53,
    9,3,122,242,132,17,134,80,67,206,71,228,244,16,24,38,
    37,232,150,65,195,7,81,167,241,20,15,104,68,118,18,99,
    160,112,11,146,191,1,218,25,129,115,2,41,168,206,76,16,
    225,2,168,42,229,25,156,93,195,5,127,207,184,108,212,105,
    251,187,140,13,213,241,147,232,56,100,15,16,205,145,212,64,
    203,60,31,124,190,215,149,45,149,108,226,196,171,232,176,214,
    114,195,48,82,53,215,243,106,174,82,177,191,119,168,100,82,
    83,81,109,43,169,147,83,237,197,12,94,185,188,65,63,131,
    19,185,30,225,164,127,120,126,75,225,143,101,254,193,94,72,
    164,66,104,116,34,47,193,121,18,177,47,149,77,155,84,100,
    228,136,55,194,200,113,136,149,150,71,190,107,248,251,73,182,
    19,134,103,189,156,129,41,145,65,91,85,25,151,110,146,56,
    188,19,154,103,8,146,224,35,55,56,148,44,61,65,121,184,
    33,34,245,30,38,6,194,235,164,80,166,63,43,21,70,161,
    55,192,61,250,173,187,180,252,117,134,226,44,131,113,21,129,
    56,133,99,25,255,47,139,53,163,101,165,240,43,103,16,164,
    148,168,128,1,32,82,12,32,28,207,48,253,212,13,206,31,
    172,23,71,231,59,68,209,203,246,6,13,111,209,112,155,134,
    205,76,245,73,232,63,119,81,255,135,180,166,193,74,179,122,
    228,40,51,83,207,59,23,97,55,134,17,134,169,178,65,145,
    98,80,60,13,35,197,162,180,26,63,166,17,89,57,6,77,
    72,190,160,36,78,17,197,194,40,120,48,12,136,26,6,7,
    27,203,94,32,35,76,103,184,182,9,172,69,196,238,23,16,
    107,147,159,24,174,246,141,44,63,58,196,161,129,106,223,34,
    81,165,17,214,174,209,240,246,36,77,62,132,220,254,37,200,
    125,64,203,47,164,144,155,99,168,85,241,187,96,180,204,212,
    15,121,245,92,190,0,53,194,153,53,2,103,119,136,50,47,
    107,254,45,64,44,213,247,227,2,196,104,139,70,81,173,93,
    36,6,235,164,77,17,92,235,216,14,188,8,215,177,194,27,
    92,225,191,207,21,158,187,4,238,221,116,226,54,57,119,107,
    162,68,102,105,155,176,150,86,238,164,130,99,63,142,94,15,
    106,81,187,166,88,111,202,179,143,182,146,237,173,228,3,204,
    160,181,199,156,187,116,14,213,89,50,150,125,202,114,244,234,
    179,215,45,201,213,146,127,57,142,78,106,14,39,56,39,173,
    194,136,179,85,50,170,145,89,155,211,123,162,98,202,234,19,
    179,119,53,183,55,109,255,83,90,176,202,198,54,197,58,98,
    170,42,120,87,142,206,232,220,149,241,83,252,126,72,14,32,
    205,37,80,79,111,55,244,158,89,29,82,204,254,238,57,220,
    76,64,25,123,7,165,255,42,195,75,121,136,23,250,154,89,
    24,252,17,184,103,21,240,7,32,68,160,227,211,48,200,163,
    134,32,176,76,236,191,6,142,151,17,61,2,231,159,6,245,
    5,204,129,105,41,121,200,172,186,101,248,20,254,84,8,182,
    172,176,155,105,87,90,44,236,86,158,187,24,74,87,42,222,
    214,249,36,71,14,234,184,9,177,233,204,53,140,223,97,137,
    200,91,73,204,220,147,192,213,180,94,202,161,93,125,53,68,
    21,149,198,91,98,217,40,96,229,7,52,188,151,195,68,100,
    115,255,231,13,110,194,248,90,238,232,74,241,37,237,194,226,
    125,207,79,113,102,58,39,37,143,134,82,22,13,239,229,209,
    32,185,170,189,225,35,11,141,6,185,254,204,16,120,150,197,
    230,142,142,142,22,200,18,52,203,20,55,220,142,139,52,172,
    68,150,219,104,189,115,37,147,77,179,171,141,150,123,95,59,
    150,134,215,19,203,25,228,219,71,129,219,219,243,220,199,199,
    180,28,173,217,202,2,205,200,20,88,40,42,64,65,34,198,
    233,192,63,31,100,138,28,77,44,95,252,8,165,231,10,112,
    116,120,81,139,147,196,23,29,89,235,201,222,30,158,80,59,
    126,191,214,14,220,125,246,144,153,42,248,121,166,160,98,23,
    95,108,70,146,251,52,70,181,86,20,98,66,63,108,169,40,
    174,121,18,15,109,210,171,125,175,198,213,160,230,39,53,119,
    15,159,186,45,165,65,127,62,118,185,251,117,227,253,132,27,
    221,131,99,34,39,234,97,7,207,229,62,182,253,3,200,11,
    176,62,46,230,201,157,27,122,29,67,88,43,241,56,166,6,
    58,147,81,99,98,111,211,112,15,38,93,3,222,39,4,209,
    50,100,182,178,184,101,84,12,110,3,207,49,62,167,119,147,
    203,1,252,151,171,4,176,190,134,74,195,184,76,156,114,138,
    110,7,104,172,80,41,104,86,179,201,25,30,103,121,114,46,
    155,188,198,227,60,79,46,100,215,95,139,60,185,4,205,101,
    186,155,161,153,21,74,13,83,255,109,106,224,176,154,104,64,
    253,238,127,154,17,236,135,223,218,254,237,31,67,218,50,140,
    203,6,162,168,220,156,206,6,93,145,157,94,138,154,241,165,
    201,205,209,48,116,90,177,116,149,212,238,218,152,160,186,156,
    89,244,226,103,195,32,191,220,101,63,201,53,59,227,150,105,
    176,194,94,212,199,55,246,162,120,17,222,196,118,219,226,118,
    251,17,181,219,39,108,6,199,208,29,247,16,162,165,220,26,
    235,56,132,242,216,25,97,17,221,85,211,238,220,126,95,134,
    158,125,31,138,141,50,63,158,24,38,40,153,253,25,10,29,
    140,41,86,176,51,190,28,149,148,176,11,154,178,59,75,121,
    28,78,210,177,140,227,191,102,56,174,115,194,206,179,182,253,
    136,6,206,211,121,138,182,127,154,187,165,62,6,164,174,231,
    226,137,230,72,58,113,116,168,252,144,207,103,87,103,198,30,
    75,209,146,23,31,168,251,99,36,160,215,251,17,170,233,236,
    185,161,119,236,123,170,195,11,254,7,236,180,36,221,26,94,
    126,164,222,29,35,101,239,176,221,150,177,147,248,95,75,94,
    237,42,124,180,12,221,31,20,230,24,50,28,237,158,12,164,
    146,163,32,206,214,72,175,38,60,137,109,64,52,192,243,33,
    159,181,240,119,224,56,147,173,154,63,65,233,191,165,101,200,
    98,88,53,69,25,235,230,170,192,63,163,82,174,8,110,75,
    46,92,209,235,189,145,67,244,185,98,144,216,156,53,231,115,
    40,241,53,114,214,24,16,234,248,52,188,235,246,244,229,31,
    95,106,217,100,99,190,118,176,239,230,144,164,75,25,62,204,
    233,227,51,102,9,110,153,184,67,178,127,72,243,116,49,209,
    123,176,157,169,181,173,213,178,15,247,6,169,82,124,149,221,
    123,192,109,126,145,241,67,55,241,91,159,132,234,51,63,60,
    112,142,36,117,102,234,246,72,97,69,206,49,235,49,139,141,
    72,70,13,47,46,164,57,158,6,81,235,64,122,250,102,118,
    140,20,230,249,40,234,185,56,127,107,36,7,186,43,149,176,
    120,225,185,23,211,91,171,23,102,19,25,251,110,128,72,28,
    35,143,247,205,122,93,84,189,160,81,102,157,145,22,124,246,
    250,170,22,76,57,85,109,172,199,158,70,33,194,63,8,208,
    136,27,99,153,26,131,68,201,222,37,41,231,236,155,237,134,
    112,151,113,176,197,46,163,131,2,45,165,185,99,188,92,155,
    57,52,99,185,239,39,228,93,238,76,134,239,167,101,138,162,
    134,183,52,42,73,20,223,159,104,48,235,243,153,190,100,122,
    76,169,41,121,137,3,93,73,87,230,43,24,216,84,193,76,
    81,197,26,102,153,179,11,21,107,118,166,98,85,166,76,190,
    61,156,195,179,121,213,170,204,204,138,127,255,183,137,73,161,
    106,108,46,85,196,55,161,238,9,94,
};

EmbeddedPython embedded_m5_internal_param_SimpleNetwork(
    "m5/internal/param_SimpleNetwork.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_SimpleNetwork.py",
    "m5.internal.param_SimpleNetwork",
    data_m5_internal_param_SimpleNetwork,
    2442,
    7665);

} // anonymous namespace
