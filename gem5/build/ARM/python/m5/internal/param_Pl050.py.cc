#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Pl050[] = {
    120,156,197,88,109,115,27,73,17,238,217,149,100,75,182,98,
    59,142,243,234,156,21,130,137,46,199,89,185,131,112,7,164,
    82,228,18,72,133,170,248,204,26,72,78,92,177,172,119,71,
    214,202,251,162,218,29,217,167,43,251,11,78,1,223,248,17,
    20,31,248,31,252,47,232,238,217,93,173,29,153,74,21,68,
    216,210,84,107,166,183,167,95,158,238,233,89,23,178,191,42,
    126,127,214,2,72,111,26,0,30,126,4,4,0,161,128,174,
    0,33,5,120,171,112,80,133,228,135,224,85,225,13,64,215,
    0,105,192,41,18,38,252,206,128,104,145,159,169,65,96,242,
    140,128,113,3,100,5,186,85,120,21,173,64,69,214,224,160,
    1,201,31,64,8,17,9,120,237,205,129,55,15,111,80,58,
    18,117,22,56,15,94,131,137,58,120,11,76,52,96,188,12,
    114,1,186,40,124,14,186,77,20,117,31,69,93,98,81,255,
    36,81,30,174,92,1,175,73,236,168,203,87,196,89,33,78,
    222,227,18,75,89,202,53,91,134,238,74,78,95,46,209,171,
    37,250,74,137,94,43,209,87,75,244,181,18,125,189,68,223,
    40,209,55,75,244,173,18,189,94,162,111,151,232,15,74,244,
    70,137,110,149,232,59,37,250,59,37,250,46,211,75,32,87,
    96,240,93,24,108,194,224,123,208,195,128,45,23,94,185,7,
    210,132,65,27,186,109,144,248,185,7,167,24,83,111,165,244,
    196,135,252,196,229,226,137,251,252,196,71,208,253,8,36,126,
    238,235,39,106,176,219,94,67,156,248,255,194,191,182,64,74,
    45,226,112,40,147,212,143,35,219,143,122,177,111,208,122,141,
    6,66,149,75,195,92,6,175,167,4,175,127,0,99,203,51,
    50,120,157,0,10,22,100,75,96,192,9,19,39,6,140,219,
    112,44,96,80,1,207,132,99,220,166,74,10,236,11,56,53,
    224,107,147,24,78,112,172,32,32,62,128,138,210,216,26,48,
    32,180,164,57,56,169,194,113,21,118,95,31,27,52,113,80,
    135,228,239,240,237,58,11,157,103,161,6,28,227,88,129,211,
    10,156,212,224,21,50,225,212,160,78,230,139,215,199,104,41,
    206,236,182,43,168,237,118,201,92,50,197,243,147,200,9,37,
    155,110,15,157,196,9,237,157,224,193,195,7,237,70,206,17,
    167,91,67,71,245,45,126,196,36,95,132,67,197,162,226,72,
    170,5,36,122,126,228,217,97,236,141,2,169,230,73,142,221,
    243,3,105,219,188,248,34,28,198,137,250,121,146,196,137,69,
    238,228,201,32,118,138,39,200,153,110,16,167,178,77,187,241,
    54,22,137,87,196,221,27,178,68,82,128,213,164,135,61,153,
    186,137,63,84,24,37,45,145,184,73,90,155,226,195,67,250,
    27,28,58,158,163,156,79,58,253,56,148,157,67,223,27,165,
    125,191,243,92,134,207,146,216,247,236,189,56,62,72,253,176,
    179,47,195,135,157,189,145,31,120,157,39,214,203,206,112,172,
    250,113,212,193,57,63,82,18,93,19,116,74,78,217,194,229,
    203,36,254,200,223,183,125,54,204,238,203,96,40,19,210,43,
    189,73,91,139,101,177,40,106,194,20,109,209,68,170,138,95,
    83,172,27,11,98,219,39,211,92,50,151,16,101,230,24,250,
    27,112,180,48,216,7,6,36,235,132,144,1,126,4,133,20,
    113,178,75,107,6,175,253,138,124,162,103,7,38,197,93,79,
    30,51,170,16,94,200,249,136,2,29,1,67,163,10,131,26,
    104,200,32,210,52,134,146,49,141,200,78,98,12,20,94,129,
    244,175,103,37,68,203,128,62,199,202,131,83,87,113,171,63,
    50,10,119,219,164,248,54,35,66,245,253,52,62,138,216,239,
    68,51,120,118,209,39,59,227,47,247,6,210,85,233,6,78,
    124,21,143,90,174,19,69,177,106,57,158,215,114,148,74,252,
    189,145,146,105,75,197,173,205,180,93,167,64,175,228,160,42,
    228,141,135,57,136,40,224,8,34,253,195,243,93,133,63,86,
    249,7,251,63,149,10,1,209,143,189,20,231,73,196,190,84,
    22,41,169,46,225,240,36,223,142,145,215,174,229,56,73,101,
    208,83,13,134,156,147,166,54,111,71,243,140,46,122,250,208,
    9,70,82,17,127,170,28,133,187,18,169,55,154,9,190,174,
    147,133,185,129,228,52,59,138,35,111,140,250,249,238,93,218,
    250,58,163,108,17,8,103,107,136,177,57,28,107,208,68,204,
    45,27,46,153,82,201,16,198,232,186,74,134,3,71,92,100,
    117,2,145,118,138,213,164,109,112,57,96,155,56,233,90,68,
    209,195,22,1,217,186,69,195,58,13,183,115,179,223,183,237,
    205,243,182,63,160,253,12,54,216,53,51,211,138,196,217,62,
    147,56,55,38,137,131,85,111,151,18,192,160,52,153,36,128,
    73,198,39,143,51,180,83,106,97,192,113,185,132,113,118,137,
    181,76,166,214,114,120,90,132,185,50,240,246,75,192,179,40,
    26,140,58,235,198,69,238,219,152,189,251,246,181,251,126,64,
    251,45,102,120,105,50,78,26,194,165,96,27,153,51,217,145,
    207,144,24,95,35,71,150,93,120,13,207,175,87,81,147,15,
    34,62,204,184,13,209,149,66,123,86,19,21,66,86,207,132,
    171,217,1,147,82,98,15,147,248,155,113,43,238,181,20,228,
    58,60,218,76,183,54,211,159,98,234,183,30,115,49,209,201,
    175,211,59,145,195,4,211,184,206,63,116,106,218,156,166,118,
    118,76,160,171,233,176,230,8,177,131,185,18,165,42,161,2,
    52,19,239,54,10,239,146,178,63,166,205,26,236,90,19,174,
    225,183,33,88,35,59,230,10,200,173,2,175,226,247,11,114,
    50,217,41,129,26,80,107,87,235,203,166,144,81,214,189,51,
    8,121,207,134,88,247,73,165,60,177,106,80,224,129,190,38,
    169,74,88,255,51,112,19,37,224,79,64,177,199,16,103,217,
    193,121,72,95,10,225,42,177,255,30,184,184,76,57,192,12,
    157,101,70,86,126,48,9,211,207,152,85,159,103,191,132,191,
    148,42,211,169,9,130,206,30,51,107,147,202,103,79,165,200,
    75,6,205,59,157,47,149,179,9,76,193,233,59,41,177,233,
    84,53,139,84,157,20,185,162,199,193,250,243,190,241,52,175,
    183,177,73,163,231,19,52,81,97,191,37,86,141,18,70,190,
    79,195,199,5,60,68,62,247,30,149,219,56,95,137,75,167,
    144,173,171,223,47,72,131,10,235,188,84,227,163,147,159,46,
    144,95,205,145,255,105,129,124,201,181,248,13,247,204,52,26,
    20,234,83,67,224,37,11,251,13,186,223,84,64,86,161,91,
    163,28,225,190,80,100,41,36,242,90,69,53,238,76,161,103,
    119,108,107,71,21,209,214,129,164,225,155,153,212,6,138,229,
    163,192,9,247,60,231,177,71,91,209,126,110,158,84,70,174,
    252,114,89,121,74,8,113,145,254,252,243,65,110,196,225,76,
    234,194,39,192,119,101,173,60,103,129,23,187,92,12,126,221,
    151,173,80,134,123,120,53,234,251,195,86,47,112,246,57,50,
    102,102,220,151,185,113,138,67,123,254,64,77,169,226,108,199,
    45,55,142,176,96,143,92,21,39,45,79,226,173,65,122,173,
    143,91,92,237,91,126,218,114,246,112,213,113,149,6,248,217,
    28,229,30,205,73,246,83,110,199,14,142,136,156,89,100,109,
    188,12,250,216,125,202,220,57,250,166,82,148,110,110,56,117,
    182,224,185,135,183,1,53,214,181,234,71,52,124,72,195,38,
    204,178,194,119,64,95,86,83,114,86,13,203,73,93,240,205,
    137,25,118,136,55,125,59,77,143,222,37,77,245,91,144,44,
    89,107,196,41,231,232,18,74,99,157,10,124,183,145,79,46,
    240,184,200,147,205,252,69,203,37,158,92,130,238,50,221,246,
    105,102,133,114,125,238,191,205,117,206,149,153,101,201,193,255,
    52,197,173,79,255,47,186,91,220,29,254,167,244,22,101,195,
    154,58,189,7,34,111,158,203,86,241,53,252,242,89,132,217,
    110,34,29,37,117,120,110,206,200,68,46,15,122,227,176,8,
    82,110,71,113,115,248,172,176,229,148,187,155,241,149,82,87,
    203,49,19,175,176,21,193,206,247,152,205,181,13,221,252,78,
    32,88,41,172,94,194,33,146,71,118,201,114,221,216,146,38,
    206,112,40,35,111,210,180,242,202,76,66,77,165,103,8,147,
    174,2,59,212,43,248,125,59,201,200,146,146,97,28,173,106,
    145,86,179,138,27,67,115,148,71,172,77,80,154,212,87,139,
    226,165,43,106,81,76,173,159,20,17,184,126,14,119,126,138,
    119,134,81,42,233,22,116,241,34,246,53,92,220,243,9,190,
    225,149,57,15,35,151,37,76,155,167,135,9,77,72,179,167,
    25,251,158,12,164,146,101,32,40,210,57,187,53,122,18,79,
    183,120,140,215,26,190,38,224,239,192,182,103,119,36,124,14,
    92,148,116,129,162,35,161,134,135,194,26,254,215,43,117,193,
    231,236,185,151,157,90,43,106,51,117,67,60,78,45,174,26,
    75,133,223,249,197,92,126,222,113,74,209,245,109,219,9,245,
    59,23,126,159,96,221,161,225,110,30,58,78,10,125,67,226,
    107,136,190,240,97,250,112,19,192,103,190,181,69,243,132,187,
    240,225,86,110,205,150,182,230,183,145,251,34,26,142,20,191,
    26,12,31,170,91,83,185,118,253,80,191,134,82,43,231,214,
    189,196,65,122,237,220,108,42,19,223,9,252,111,37,119,189,
    111,203,123,18,238,57,47,34,245,76,30,250,174,84,55,166,
    242,124,225,164,242,185,239,94,160,247,78,224,168,94,156,132,
    234,246,212,101,20,158,60,141,113,136,3,198,235,20,147,198,
    41,22,180,183,236,149,209,40,180,95,202,48,78,198,47,99,
    79,170,59,231,214,159,100,29,149,102,177,15,37,181,94,170,
    53,221,202,51,188,23,184,22,23,51,215,78,119,213,211,32,
    118,15,164,151,241,76,183,150,121,158,197,33,133,98,253,188,
    194,158,151,88,78,180,47,115,93,167,171,177,227,199,89,52,
    46,142,216,132,103,186,189,24,49,223,157,48,113,41,200,56,
    56,229,167,197,158,206,192,51,51,220,105,77,14,62,206,244,
    68,238,251,24,173,132,165,156,225,206,78,135,207,167,21,173,
    242,147,51,171,10,250,222,162,95,176,60,166,84,76,191,198,
    129,94,44,214,151,234,162,102,208,171,107,83,52,68,83,84,
    196,98,179,110,214,107,245,170,137,149,131,102,86,69,195,172,
    55,22,197,187,252,111,96,141,105,24,27,139,117,241,111,135,
    0,54,96,
};

EmbeddedPython embedded_m5_internal_param_Pl050(
    "m5/internal/param_Pl050.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_Pl050.py",
    "m5.internal.param_Pl050",
    data_m5_internal_param_Pl050,
    2323,
    7074);

} // anonymous namespace
