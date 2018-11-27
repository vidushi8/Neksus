#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BasicPioDevice[] = {
    120,156,197,88,91,111,220,198,21,62,67,238,82,218,149,86,
    23,75,242,85,142,232,218,70,183,65,163,77,210,186,73,81,
    195,168,19,183,65,11,88,113,185,5,236,108,211,176,20,57,
    218,229,106,73,46,200,145,156,13,164,151,202,104,251,214,31,
    81,244,161,255,163,232,223,106,206,57,67,82,92,93,12,3,
    45,86,210,114,48,28,206,156,57,151,239,92,102,124,200,255,
    234,248,252,210,6,200,254,35,0,2,252,9,24,1,68,2,
    122,2,132,20,16,172,193,126,29,210,159,66,80,135,55,0,
    61,3,164,1,39,216,49,225,15,6,196,139,188,198,130,145,
    201,35,2,38,77,144,53,232,213,225,101,188,10,53,105,193,
    126,19,210,63,129,16,34,22,240,42,152,131,96,30,222,32,
    117,236,52,152,224,60,4,77,238,52,32,88,224,78,19,38,
    43,32,23,160,135,196,231,160,215,66,82,239,35,169,37,38,
    245,111,34,21,224,151,117,8,90,52,29,121,249,138,102,214,
    104,38,239,177,196,84,150,11,206,86,160,183,90,244,175,85,
    250,107,149,254,122,165,191,81,233,95,175,244,111,84,250,55,
    43,253,91,149,254,237,74,255,78,165,191,201,253,101,144,171,
    48,188,11,195,247,96,184,5,123,168,220,149,82,2,27,164,
    9,195,123,208,187,7,18,127,54,156,160,254,131,213,202,138,
    31,240,138,107,229,138,251,188,226,1,244,30,128,196,223,125,
    189,194,130,110,123,3,109,26,254,23,255,218,104,83,80,139,
    216,28,202,52,11,147,216,13,227,189,36,52,232,187,69,13,
    33,192,167,102,46,135,194,231,4,133,127,1,227,32,48,114,
    40,28,3,18,22,36,203,200,128,99,238,28,27,48,105,195,
    145,128,97,13,2,19,142,112,155,58,49,208,23,112,98,192,
    215,38,77,56,198,182,134,198,123,15,106,74,227,96,200,198,
    211,148,230,224,184,14,71,117,232,190,58,50,104,96,191,1,
    233,63,225,187,77,38,58,207,68,13,56,194,182,6,39,53,
    56,182,224,37,78,194,161,97,131,196,23,175,142,80,82,28,
    233,182,107,200,237,78,69,92,18,37,8,211,216,139,164,34,
    77,184,99,47,245,34,247,51,47,11,253,23,97,242,76,30,
    134,190,108,55,139,169,73,182,61,246,212,192,225,181,38,41,
    37,26,43,166,153,196,82,45,96,103,47,140,3,55,74,130,
    131,145,84,243,68,208,221,11,71,210,117,249,227,111,162,113,
    146,170,95,165,105,146,58,164,87,30,28,37,94,185,130,180,
    234,143,146,76,182,105,55,222,198,33,242,138,102,239,141,153,
    34,49,192,252,210,226,64,102,126,26,142,21,154,75,83,164,
    217,68,173,77,134,226,38,251,6,155,78,224,41,239,163,206,
    32,137,100,231,48,12,14,178,65,216,249,66,70,207,210,36,
    12,220,221,36,217,207,194,168,211,151,209,163,206,238,65,56,
    10,58,79,157,231,157,241,68,13,146,184,131,99,97,172,36,
    234,104,212,185,72,59,219,56,239,26,237,243,58,236,187,33,
    75,232,14,228,104,44,83,98,48,187,77,60,136,21,177,40,
    44,97,138,182,104,97,175,142,143,41,54,141,5,177,19,146,
    140,62,201,77,24,51,11,84,253,3,216,126,104,254,125,3,
    210,77,194,204,16,127,130,140,140,200,233,210,55,131,191,253,
    142,148,163,71,135,38,33,65,15,30,49,206,16,112,56,243,
    49,153,62,6,6,75,29,134,22,104,16,33,246,52,170,210,
    9,181,56,157,200,24,72,188,6,217,223,167,41,196,43,128,
    202,199,184,129,67,215,113,171,63,51,46,187,109,98,124,135,
    161,161,6,97,150,188,142,217,0,212,103,79,234,162,78,94,
    76,190,220,29,74,95,101,91,56,240,85,114,96,251,94,28,
    39,202,246,130,192,246,148,74,195,221,3,37,51,91,37,246,
    195,172,221,32,139,175,22,232,42,233,77,198,5,154,200,242,
    136,38,253,18,132,190,194,151,53,126,97,253,103,82,33,50,
    6,73,144,225,56,145,232,75,229,16,147,106,9,155,167,197,
    118,12,193,182,85,0,38,147,163,61,213,100,236,121,89,230,
    242,118,52,206,48,163,213,135,222,232,64,42,154,159,41,79,
    225,174,212,213,27,205,22,104,55,73,212,66,82,210,158,27,
    39,113,48,65,70,67,255,62,241,112,147,225,182,8,4,184,
    13,4,219,28,182,22,180,16,124,43,134,79,50,213,114,168,
    49,204,174,147,6,128,77,47,242,16,130,144,59,193,64,211,
    54,56,82,176,112,236,134,54,245,104,177,67,136,118,238,80,
    179,73,205,221,66,254,153,41,161,117,86,9,31,210,198,6,
    75,238,155,185,140,165,43,237,76,185,210,173,83,87,194,200,
    216,37,151,48,200,113,78,93,194,36,45,164,79,114,252,147,
    179,33,4,240,115,5,245,172,27,103,133,100,182,10,192,58,
    132,194,42,20,251,21,40,58,100,22,198,161,115,235,50,61,
    110,93,161,30,251,90,143,63,161,141,23,115,4,181,24,57,
    77,225,147,249,141,92,171,172,209,103,216,153,220,32,141,86,
    117,121,3,147,221,203,184,197,89,139,51,31,215,23,58,136,
    104,21,235,78,141,176,182,103,194,245,60,27,101,228,243,227,
    52,249,118,98,39,123,182,130,130,135,199,15,179,237,135,217,
    47,48,42,216,79,56,206,232,184,160,61,63,149,227,20,61,
    188,193,47,218,107,93,246,96,55,79,37,168,115,202,103,108,
    42,214,52,7,169,76,165,20,155,102,171,230,102,169,102,226,
    250,231,180,107,147,117,108,194,13,124,154,130,89,115,19,142,
    146,92,96,240,87,124,62,35,109,147,192,18,168,196,116,186,
    154,113,150,137,164,115,126,56,133,153,89,73,228,188,79,188,
    21,62,103,65,137,16,122,76,226,153,220,224,175,192,53,152,
    128,191,0,161,1,141,158,59,14,187,40,61,100,212,53,59,
    103,249,72,92,148,237,12,237,128,70,30,162,208,63,179,79,
    120,170,78,126,191,133,191,85,162,215,137,9,130,18,149,153,
    87,89,213,68,85,43,93,150,97,244,78,201,168,54,237,219,
    100,165,129,151,209,52,237,197,102,233,197,167,129,176,172,140,
    48,52,205,12,97,243,122,63,151,88,251,226,20,95,148,5,
    238,136,53,163,130,154,31,83,243,65,9,24,81,140,205,130,
    203,173,179,97,187,146,187,92,29,42,127,77,172,212,152,249,
    101,139,83,246,52,153,210,59,234,133,119,124,92,122,135,228,
    8,254,134,171,113,106,13,66,193,137,33,240,168,133,117,11,
    157,114,106,32,235,208,179,200,143,184,208,20,185,155,137,34,
    176,81,64,156,74,15,172,160,29,173,186,18,8,218,198,212,
    124,59,219,64,66,102,126,60,242,162,221,192,123,242,71,218,
    147,54,246,11,199,51,10,41,86,170,82,144,211,136,203,4,
    225,215,15,11,105,14,103,27,68,62,194,45,74,41,216,101,
    130,196,231,200,241,251,129,180,35,25,237,226,49,108,16,142,
    237,189,145,215,103,91,153,185,148,95,22,82,42,54,246,217,
    196,156,81,120,218,73,108,63,137,49,222,31,248,42,73,237,
    64,226,193,68,6,246,7,54,39,11,59,204,108,111,23,191,
    122,190,210,78,48,237,208,92,253,121,105,63,227,66,111,255,
    53,117,103,111,107,23,79,160,33,22,184,223,20,90,210,167,
    162,50,242,179,131,104,143,194,252,137,7,14,53,209,17,238,
    103,212,252,136,154,135,112,37,9,162,131,91,124,77,123,145,
    250,44,12,66,13,161,214,207,121,243,11,90,157,157,247,233,
    248,93,124,90,95,156,224,4,105,193,112,142,219,121,202,15,
    189,70,49,216,228,118,129,7,23,139,24,208,226,193,37,190,
    242,208,151,52,43,20,15,172,255,53,30,176,27,205,222,129,
    130,255,107,24,112,62,190,90,33,28,46,64,223,22,2,12,
    168,84,246,159,232,16,160,109,131,37,198,100,189,82,108,178,
    192,226,37,214,3,88,144,30,113,169,234,26,186,38,61,53,
    36,103,120,190,55,160,2,61,150,175,221,139,16,170,11,79,
    130,136,55,30,203,56,56,45,42,249,203,108,21,70,190,61,
    128,211,28,143,21,228,58,62,231,193,91,211,154,45,68,101,
    144,214,75,184,222,190,18,75,71,101,36,91,157,138,100,14,
    153,82,199,174,50,108,105,187,220,187,36,106,184,227,48,113,
    177,106,75,233,236,242,14,179,176,228,208,183,71,249,128,122,
    240,182,37,35,79,201,216,159,48,237,119,154,72,228,23,114,
    242,249,24,91,74,209,249,46,144,35,169,228,133,208,82,36,
    115,126,96,12,36,38,164,100,130,7,25,62,15,224,251,200,
    117,175,32,120,127,10,250,158,51,91,202,131,183,133,39,193,
    13,209,168,53,4,103,200,51,87,162,154,57,178,152,174,123,
    39,153,195,190,188,92,218,144,245,94,36,40,118,90,58,183,
    237,120,145,190,135,225,171,5,135,76,232,220,47,16,192,222,
    166,79,68,124,218,208,39,61,116,80,78,223,156,173,157,237,
    66,191,209,163,237,66,168,109,45,84,41,15,95,28,70,143,
    216,189,207,79,235,78,50,37,163,115,52,100,124,16,185,207,
    101,148,164,147,231,73,32,25,93,213,239,79,243,202,65,79,
    113,15,37,149,24,202,190,112,139,233,185,151,176,139,31,245,
    29,25,215,200,231,191,127,62,74,252,125,25,228,115,238,94,
    62,231,89,18,121,56,126,241,46,221,176,216,101,245,204,247,
    32,165,85,27,103,70,51,153,134,222,40,252,78,170,205,179,
    10,64,7,114,188,184,47,11,217,201,194,197,87,69,134,63,
    107,6,50,95,249,198,229,1,51,57,13,62,118,131,84,246,
    67,180,74,202,100,206,6,226,79,223,26,18,170,203,103,239,
    55,186,60,215,183,15,79,72,94,190,121,162,123,184,198,114,
    67,88,6,93,249,154,162,41,90,162,38,22,91,13,179,97,
    53,234,38,250,22,141,172,137,166,217,104,46,138,139,255,183,
    208,243,154,198,214,66,67,124,15,238,76,34,238,
};

EmbeddedPython embedded_m5_internal_param_BasicPioDevice(
    "m5/internal/param_BasicPioDevice.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_BasicPioDevice.py",
    "m5.internal.param_BasicPioDevice",
    data_m5_internal_param_BasicPioDevice,
    2205,
    6794);

} // anonymous namespace
