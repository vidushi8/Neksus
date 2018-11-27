#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Prefetcher[] = {
    120,156,197,89,253,114,27,73,17,239,217,93,201,150,44,199,
    242,183,29,59,177,238,32,156,72,129,5,199,133,80,117,38,
    16,224,248,184,162,124,97,117,144,156,238,138,101,173,29,73,
    43,75,187,170,221,145,19,93,217,85,20,78,113,188,0,143,
    192,31,247,54,60,2,111,2,221,61,218,213,90,150,43,174,
    130,8,91,26,207,246,206,244,244,199,175,123,122,198,77,24,
    255,228,240,251,211,10,64,220,18,0,30,126,4,244,0,250,
    2,26,2,132,20,224,109,192,105,14,162,15,192,203,193,107,
    128,134,1,210,128,75,236,152,240,185,1,65,137,231,228,161,
    103,50,69,192,168,8,210,130,70,14,158,7,171,96,201,60,
    156,22,33,250,19,8,33,2,1,47,188,5,240,22,225,53,
    114,199,78,129,25,46,2,17,139,76,44,128,183,196,196,34,
    120,37,238,44,193,168,12,178,4,141,101,26,214,184,131,108,
    31,34,219,21,102,251,79,98,235,225,155,77,240,238,208,112,
    148,235,51,26,105,209,72,94,111,133,185,148,19,41,87,161,
    177,150,244,215,51,253,13,238,227,74,107,208,221,132,238,22,
    116,183,1,13,226,173,166,92,119,64,154,208,221,133,198,46,
    72,252,236,192,37,218,199,91,203,204,184,203,51,214,211,25,
    123,60,99,31,26,251,32,241,179,167,103,228,161,94,221,66,
    155,251,255,198,159,42,218,28,84,9,155,51,25,197,126,24,
    56,126,208,10,125,131,222,231,169,33,15,53,169,89,24,187,
    234,231,228,170,175,129,253,228,25,99,87,93,0,50,22,164,
    75,207,128,11,238,92,24,48,170,194,185,128,174,5,158,9,
    231,184,76,142,4,104,11,184,52,224,11,147,6,92,96,107,
    161,65,239,131,165,180,159,186,108,80,205,105,1,46,114,112,
    158,131,250,139,115,131,8,167,5,136,254,1,95,238,51,211,
    69,102,106,192,57,182,22,92,90,112,145,135,231,56,8,73,
    221,2,169,47,94,156,163,166,72,169,87,45,148,246,56,163,
    46,169,226,249,81,224,246,165,90,197,190,51,112,35,183,239,
    60,139,100,75,170,102,71,70,213,98,50,44,140,15,7,174,
    234,216,60,207,36,131,244,7,138,249,133,129,84,75,216,105,
    249,129,231,244,67,111,216,147,106,145,152,57,45,191,39,29,
    135,95,254,166,63,8,35,245,81,20,133,145,77,54,101,98,
    47,116,211,25,100,209,102,47,140,101,149,86,227,101,108,98,
    175,104,116,107,192,28,73,0,150,149,38,123,50,110,70,254,
    64,161,171,52,71,26,77,220,170,228,36,110,226,63,96,83,
    235,132,125,89,59,243,189,97,220,241,107,191,146,253,95,68,
    161,239,57,39,97,120,26,251,253,90,91,246,31,213,78,134,
    126,207,171,61,253,237,179,95,63,173,13,70,170,19,6,53,
    164,250,129,146,104,155,94,109,218,42,135,56,102,141,248,191,
    244,219,142,207,154,57,29,217,27,200,104,153,168,119,105,109,
    81,22,37,145,23,166,168,138,101,236,229,240,107,138,125,99,
    73,28,251,164,91,147,244,37,92,89,89,36,145,123,5,156,
    26,16,237,19,78,186,248,17,228,88,68,75,157,222,25,252,
    238,119,100,20,77,237,154,228,125,77,60,103,108,33,200,112,
    228,17,185,59,0,6,72,14,186,121,208,192,65,188,105,36,
    69,35,106,113,56,177,49,144,185,5,241,223,1,141,140,144,
    57,135,49,156,46,77,16,65,25,84,145,162,24,169,91,184,
    224,95,24,145,245,42,137,127,204,192,80,29,63,14,95,6,
    108,126,234,115,12,213,209,50,207,70,159,156,116,101,83,197,
    7,72,248,44,28,86,154,110,16,132,170,226,122,94,197,85,
    42,242,79,134,74,198,21,21,86,30,196,85,242,168,189,154,
    96,43,229,55,26,36,88,34,191,35,150,244,131,231,55,21,
    62,172,243,3,123,33,150,10,113,209,9,189,24,233,196,162,
    45,149,77,66,42,50,114,200,130,48,108,28,26,74,203,227,
    184,59,248,252,52,145,132,177,89,205,39,72,138,101,175,165,
    138,12,74,55,142,29,150,132,232,140,63,98,124,230,246,134,
    146,185,199,200,15,5,162,174,150,97,62,8,220,33,109,18,
    229,89,163,32,12,188,17,10,232,55,223,163,181,119,24,135,
    37,70,226,38,162,112,1,219,60,254,205,139,45,163,105,141,
    177,151,79,240,71,153,80,1,123,95,140,1,128,88,188,196,
    172,83,53,56,109,176,82,28,151,239,82,143,38,219,251,212,
    220,163,230,62,53,7,137,222,111,93,249,229,105,229,31,211,
    130,6,107,204,186,145,139,204,68,55,239,74,108,237,78,98,
    11,211,99,157,98,196,160,72,154,196,136,69,169,52,122,66,
    45,14,229,232,51,33,254,148,18,55,197,18,51,163,176,193,
    0,160,222,36,44,216,82,118,153,44,176,152,32,218,38,152,
    102,177,218,206,96,213,38,39,49,80,237,221,36,45,58,52,
    66,67,212,222,35,86,185,25,166,174,80,243,206,220,236,61,
    1,91,251,26,216,62,164,181,203,99,176,45,51,200,138,248,
    45,27,77,115,236,132,116,187,92,159,2,25,33,204,154,129,
    176,111,81,207,188,174,246,188,193,53,86,246,151,25,112,145,
    124,70,86,167,99,236,140,182,73,149,44,172,182,113,243,127,
    30,108,227,126,110,240,126,254,61,222,207,185,38,224,106,72,
    39,107,147,243,181,238,228,200,38,45,19,182,198,251,116,92,
    192,118,16,133,175,70,149,176,85,81,172,52,229,214,163,7,
    241,225,131,248,67,204,154,149,39,156,175,116,222,212,153,49,
    146,3,202,108,52,245,163,87,77,201,219,35,63,57,142,78,
    100,14,39,53,103,188,237,34,194,54,201,162,70,98,106,78,
    233,177,138,40,147,207,199,216,197,212,216,36,251,199,180,90,
    145,45,109,138,109,68,83,81,176,72,142,78,225,92,128,241,
    91,252,254,140,172,79,106,75,160,18,217,174,107,129,89,23,
    210,202,254,206,21,196,188,109,77,236,26,178,254,125,130,148,
    252,4,41,244,53,19,244,127,5,92,155,10,248,43,16,22,
    208,229,99,244,167,193,66,206,95,167,225,127,4,14,147,25,
    21,1,231,156,58,85,1,60,2,83,81,252,152,135,234,2,
    225,99,248,91,38,198,146,109,220,28,87,159,217,109,220,74,
    243,21,131,232,86,91,181,117,53,177,145,119,58,110,76,195,
    116,182,154,132,237,100,79,72,171,70,204,214,111,29,81,139,
    122,29,135,68,250,98,130,39,218,8,247,196,186,145,65,201,
    247,169,121,63,5,136,72,104,111,83,186,3,184,121,219,118,
    244,190,240,57,137,96,177,208,43,11,28,32,19,22,105,4,
    228,146,8,120,63,141,0,201,27,216,107,62,145,80,107,144,
    199,47,13,129,199,65,172,224,232,244,101,129,204,65,35,79,
    177,194,5,183,24,135,146,72,146,25,165,190,43,187,35,27,
    229,88,155,43,117,186,246,39,53,175,230,147,36,200,165,71,
    61,183,127,226,185,79,186,180,22,45,216,76,130,203,72,164,
    47,103,165,167,192,16,55,41,192,143,143,18,45,206,230,147,
    32,126,8,44,155,150,158,195,193,11,155,156,21,62,237,200,
    74,95,246,79,240,232,217,241,7,149,86,207,109,179,111,204,
    177,118,159,36,218,41,118,238,116,197,17,63,164,54,172,52,
    195,0,115,247,176,169,194,168,226,73,60,144,73,175,242,221,
    10,39,254,138,31,87,220,19,124,235,54,149,6,250,213,96,
    229,226,214,141,218,49,215,177,167,47,169,59,63,223,58,120,
    218,246,177,164,239,65,186,209,234,115,96,154,199,185,88,215,
    113,131,123,34,30,181,212,72,231,45,170,62,236,67,106,190,
    13,115,77,247,31,128,190,21,136,201,96,121,177,103,20,12,
    85,190,18,171,207,104,86,124,61,98,255,117,155,136,213,87,
    55,227,184,205,211,72,185,64,167,125,106,11,148,242,27,197,
    132,184,196,109,137,137,203,9,241,14,183,43,76,44,39,196,
    85,110,215,152,184,158,16,55,184,221,100,226,86,66,220,230,
    118,135,137,187,9,241,46,183,123,76,220,79,174,161,238,49,
    241,62,52,14,232,254,134,40,21,202,47,11,255,109,126,225,
    240,156,95,96,198,255,211,180,98,63,254,255,8,111,255,8,
    198,133,198,77,41,69,100,53,91,214,41,165,43,146,115,78,
    86,45,190,85,217,158,129,104,167,25,73,87,73,237,165,253,
    121,41,202,137,73,175,124,54,73,19,215,235,241,167,169,78,
    151,92,98,141,54,216,121,250,136,199,206,19,207,131,187,88,
    152,91,92,152,31,81,97,126,206,6,112,12,93,155,79,96,
    153,75,237,176,129,77,32,95,58,211,182,208,197,55,137,230,
    14,6,50,240,236,135,144,173,167,249,245,124,112,64,137,240,
    207,144,41,119,76,177,129,5,244,245,24,164,76,159,209,145,
    189,152,75,163,110,110,254,100,224,126,149,0,183,74,103,217,
    73,186,183,143,168,225,4,159,230,118,251,39,169,55,42,179,
    80,57,164,45,164,229,247,112,73,58,184,189,121,16,22,96,
    124,224,206,208,102,79,10,134,125,7,183,78,73,253,27,57,
    103,7,37,156,51,52,46,252,102,68,82,136,135,178,129,219,
    150,204,248,77,99,136,47,95,74,165,36,245,238,172,41,131,
    150,51,32,5,121,105,230,124,139,97,196,156,18,194,21,170,
    122,103,214,68,44,35,252,192,233,251,113,44,181,69,222,60,
    138,184,211,241,53,75,84,223,188,217,144,110,164,134,3,148,
    80,243,191,213,64,90,98,37,181,122,74,87,223,152,57,57,
    12,166,1,115,155,113,180,6,149,34,87,201,28,124,156,43,
    61,217,147,74,94,75,19,92,25,140,239,127,60,84,60,10,
    71,120,20,231,147,45,62,247,28,103,142,133,203,143,145,117,
    4,227,139,106,44,92,68,30,75,151,77,145,249,53,10,249,
    130,224,218,112,234,31,32,90,64,186,142,209,167,185,81,108,
    243,174,179,146,70,38,223,211,39,5,26,5,49,223,62,28,
    187,125,125,193,202,119,135,54,25,154,239,120,236,247,210,8,
    167,235,47,62,66,235,235,10,204,181,92,183,114,153,106,255,
    128,232,212,235,63,58,76,116,59,212,186,213,253,190,190,103,
    230,255,20,244,31,241,63,50,178,195,60,2,156,218,156,162,
    198,50,242,221,158,255,165,190,95,78,200,12,159,105,190,36,
    79,250,196,101,223,212,174,200,110,141,100,219,143,41,131,172,
    100,135,143,55,9,50,185,186,55,11,94,217,169,243,195,128,
    62,80,233,59,160,39,148,168,226,39,216,208,69,113,97,165,
    128,120,160,205,195,20,69,220,62,44,179,84,46,88,165,165,
    130,85,88,48,249,102,111,25,207,208,69,171,176,84,18,244,
    123,128,72,41,26,7,91,5,241,31,222,142,178,10,
};

EmbeddedPython embedded_m5_internal_param_Prefetcher(
    "m5/internal/param_Prefetcher.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_Prefetcher.py",
    "m5.internal.param_Prefetcher",
    data_m5_internal_param_Prefetcher,
    2382,
    7368);

} // anonymous namespace
