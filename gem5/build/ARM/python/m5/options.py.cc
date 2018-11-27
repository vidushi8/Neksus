#include "sim/init.hh"

namespace {

const uint8_t data_m5_options[] = {
    120,156,173,88,221,111,219,84,20,191,182,243,229,52,165,99,
    163,85,11,27,50,176,138,140,209,5,36,64,12,117,211,52,
    58,54,208,212,21,103,8,168,182,89,174,125,147,184,77,237,
    204,190,217,86,169,125,64,229,101,72,240,206,35,15,252,157,
    112,126,231,218,78,218,110,188,144,164,118,206,253,62,31,191,
    243,113,27,136,252,99,209,115,203,17,34,27,16,17,210,159,
    33,134,66,108,151,180,33,182,13,166,77,244,63,12,45,33,
    77,209,163,174,138,248,85,136,99,33,126,222,182,68,88,45,
    122,107,101,111,69,132,117,33,171,220,219,40,123,107,216,180,
    219,182,233,176,232,31,250,108,182,13,34,21,94,31,41,244,
    198,73,40,123,254,120,168,130,130,67,140,221,6,135,13,34,
    164,0,63,110,183,141,145,182,137,181,232,246,188,216,223,151,
    158,167,154,220,216,79,194,241,144,154,122,86,249,202,62,163,
    87,103,144,236,203,206,179,40,28,103,131,168,115,87,238,111,
    164,73,20,118,250,114,255,243,78,150,6,157,209,129,26,36,
    113,135,90,201,72,69,73,156,93,27,29,184,224,225,125,236,
    128,19,107,250,204,108,52,140,148,146,233,89,70,223,46,25,
    37,197,145,228,219,38,164,6,97,129,117,236,17,224,85,60,
    95,99,209,60,17,135,134,56,36,254,89,249,93,214,76,174,
    159,106,113,158,22,185,130,166,28,246,220,234,108,228,203,117,
    24,197,145,242,188,213,66,78,97,4,216,191,78,79,165,224,
    242,49,184,180,196,174,0,163,244,62,54,196,81,21,246,59,
    172,136,93,19,2,236,90,226,216,20,71,53,113,88,131,24,
    123,13,145,222,135,0,211,19,14,171,226,216,18,70,60,143,
    73,187,53,110,27,194,152,146,26,135,178,116,10,84,95,42,
    95,169,84,213,136,126,230,15,199,50,99,21,132,244,203,196,
    102,18,75,158,152,77,77,148,47,148,140,67,189,19,218,220,
    169,101,230,185,68,122,25,205,173,22,155,242,132,145,159,102,
    50,117,1,69,183,57,83,237,6,254,112,232,121,31,98,167,
    38,107,247,188,177,104,180,140,21,179,13,17,92,104,220,133,
    55,186,204,241,249,19,103,255,79,248,226,128,203,216,1,68,
    205,176,77,213,34,226,1,79,216,98,129,75,16,155,5,136,
    31,253,7,136,41,24,128,32,23,183,152,168,230,225,0,238,
    93,101,162,158,135,130,237,6,194,0,8,91,132,54,71,2,
    138,40,115,112,3,40,33,48,242,16,132,231,1,142,253,30,
    0,51,1,45,58,141,112,69,152,161,192,65,136,50,148,134,
    142,129,225,63,24,127,94,133,81,72,192,170,98,146,17,233,
    222,90,222,11,186,174,93,9,82,109,114,124,233,37,233,190,
    15,183,109,195,42,28,47,8,52,121,204,97,75,145,222,24,
    4,234,2,53,30,70,106,40,195,123,114,56,250,166,88,232,
    162,159,247,242,202,169,43,64,99,148,249,59,20,117,162,152,
    38,101,35,122,100,232,249,105,63,211,246,39,235,211,244,140,
    65,230,245,211,100,60,106,91,37,52,97,23,158,138,214,222,
    115,144,179,176,59,144,244,201,4,112,75,4,184,121,211,182,
    206,106,29,34,105,135,222,53,38,42,46,156,145,161,185,12,
    62,91,90,93,94,174,175,108,34,130,123,17,175,75,51,2,
    236,187,180,240,171,169,56,116,134,225,235,58,90,182,210,75,
    224,149,127,68,30,149,60,67,196,203,133,52,230,73,192,24,
    58,253,96,215,236,162,150,197,81,3,233,4,227,52,149,177,
    114,52,11,14,155,103,83,11,7,185,221,119,32,252,57,24,
    41,12,61,61,233,180,13,103,170,0,134,23,20,205,135,220,
    64,163,198,222,249,134,177,96,178,54,106,211,218,248,123,218,
    105,200,199,200,93,200,69,247,76,145,134,112,81,26,218,171,
    129,198,28,19,61,8,219,150,232,243,42,114,221,117,242,90,
    80,53,162,234,76,25,98,93,89,136,244,199,172,62,234,93,
    143,197,196,219,74,165,30,85,56,176,215,144,5,40,138,99,
    66,93,236,213,69,250,23,250,117,147,250,121,113,37,79,252,
    217,13,173,72,199,143,11,133,171,228,181,102,248,216,73,82,
    167,63,76,118,252,161,19,83,156,119,72,45,236,38,126,192,
    161,156,201,209,136,66,253,36,95,20,238,140,49,10,241,81,
    220,103,15,83,7,35,201,206,136,80,188,227,7,123,155,58,
    8,64,143,148,98,220,185,162,49,74,70,28,51,181,221,155,
    39,236,206,89,193,69,138,111,215,206,218,158,121,112,223,16,
    179,203,30,238,21,90,184,129,29,150,176,79,237,178,177,96,
    52,249,123,193,92,52,108,106,157,51,3,48,11,238,33,14,
    231,233,63,5,99,129,236,180,68,38,10,77,77,177,225,128,
    18,11,86,207,211,52,161,228,102,30,105,143,234,48,249,81,
    67,196,11,76,212,139,254,6,155,210,130,13,9,42,132,147,
    28,38,212,95,39,136,88,71,118,49,161,202,19,40,210,55,
    185,0,160,9,13,158,64,77,154,211,20,61,147,80,0,86,
    185,224,100,20,56,59,73,50,148,19,48,192,58,50,116,214,
    214,80,211,17,72,152,76,184,117,173,233,228,159,141,136,234,
    33,255,192,25,80,104,118,66,9,251,147,153,29,90,254,124,
    16,5,3,39,202,24,81,69,160,130,130,214,214,86,179,172,
    206,4,109,183,154,113,213,185,198,111,207,125,175,204,6,42,
    73,165,167,210,177,116,63,40,66,51,14,81,115,229,96,207,
    31,102,82,219,183,82,64,46,149,196,78,32,93,24,73,161,
    150,235,254,176,181,229,222,233,118,189,123,119,238,111,177,17,
    89,236,73,188,135,60,124,132,187,38,242,18,79,161,143,169,
    30,143,54,203,1,230,128,7,152,226,99,73,93,76,244,136,
    152,69,204,1,123,48,69,14,244,159,68,94,202,138,10,208,
    118,222,160,194,129,74,7,148,15,203,68,209,99,150,85,172,
    85,224,238,129,142,203,58,18,81,236,72,87,1,33,101,2,
    30,132,55,157,192,169,191,171,75,93,132,165,235,32,168,185,
    210,125,245,76,157,188,221,171,165,186,181,149,252,84,101,207,
    35,53,208,181,241,120,84,36,102,68,105,207,203,43,198,104,
    103,172,112,15,48,79,104,30,35,179,82,88,121,20,221,58,
    68,153,105,23,140,37,179,101,52,204,0,138,169,76,43,232,
    247,211,10,186,250,10,5,145,107,161,226,137,159,228,55,2,
    10,186,208,212,72,68,60,70,157,95,80,248,198,64,21,126,
    74,123,26,19,125,190,228,41,124,202,250,211,151,34,94,121,
    253,1,147,218,72,171,151,99,25,82,171,139,228,171,245,169,
    133,204,10,33,57,242,113,126,214,101,43,47,89,199,11,138,
    231,232,90,22,7,51,8,126,55,105,225,51,236,112,46,215,
    235,69,122,230,233,219,66,216,131,235,86,197,212,245,228,137,
    152,170,99,168,36,124,68,177,139,82,157,41,94,220,102,173,
    179,252,212,191,241,248,83,30,179,242,4,134,139,138,45,178,
    111,161,77,168,177,14,224,234,4,70,61,235,79,87,5,253,
    253,120,104,150,37,17,135,249,229,2,141,92,4,78,213,122,
    94,24,5,116,147,226,44,30,81,53,72,207,126,198,233,69,
    47,44,145,136,138,144,147,7,167,157,61,121,192,191,116,27,
    153,133,238,110,209,194,95,38,152,92,52,47,146,211,190,105,
    158,189,122,174,157,210,26,192,164,53,146,94,1,103,168,165,
    25,172,70,124,226,106,122,74,9,148,103,149,135,240,52,73,
    164,217,129,190,169,201,23,249,213,85,139,222,200,187,2,186,
    236,207,194,17,193,200,56,243,251,242,55,81,84,74,12,145,
    205,54,10,214,211,87,43,128,215,117,240,66,84,118,191,196,
    11,37,9,131,141,181,198,2,184,223,137,25,94,193,224,75,
    29,236,128,139,29,197,208,166,109,217,117,251,45,123,209,182,
    237,57,219,214,215,84,36,15,247,174,40,238,170,59,187,50,
    80,252,191,7,174,70,244,157,151,144,197,155,205,138,51,54,
    198,186,254,143,201,205,75,5,92,90,70,203,108,154,75,230,
    210,220,191,60,247,158,26,
};

EmbeddedPython embedded_m5_options(
    "m5/options.py",
    "/home/vidushi/GemDroid/gem5/src/python/m5/options.py",
    "m5.options",
    data_m5_options,
    1799,
    4650);

} // anonymous namespace
