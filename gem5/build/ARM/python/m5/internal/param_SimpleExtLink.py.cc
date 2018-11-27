#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_SimpleExtLink[] = {
    120,156,197,88,91,111,220,198,21,62,67,114,87,218,149,214,
    146,44,217,242,69,182,232,4,70,183,65,163,77,210,58,233,
    197,48,154,216,105,208,160,81,82,110,1,59,155,180,44,69,
    142,118,185,226,101,65,142,108,111,32,189,84,70,219,183,254,
    136,162,15,125,233,175,232,255,74,207,57,67,82,148,180,10,
    2,164,88,75,203,193,112,56,151,115,249,190,51,103,198,135,
    226,175,129,207,175,109,128,252,63,2,32,192,159,128,8,32,
    22,48,16,32,164,128,96,29,14,26,144,253,12,130,6,188,
    2,24,24,32,13,56,193,138,9,95,25,144,44,243,152,38,
    68,38,183,8,152,182,65,90,48,104,192,211,100,13,44,217,
    132,131,54,100,127,6,33,68,34,224,89,176,0,193,34,188,
    194,217,177,210,226,9,23,33,104,115,165,5,193,18,87,218,
    48,93,5,185,4,3,156,124,1,6,29,156,234,45,156,234,
    10,79,245,95,154,42,192,47,27,16,116,168,59,202,242,37,
    245,180,168,39,175,113,133,103,89,41,37,91,133,193,90,89,
    191,90,171,175,215,234,27,181,250,181,90,253,122,173,190,89,
    171,223,168,213,111,214,234,183,184,190,2,114,13,198,183,97,
    188,5,227,59,176,143,70,92,173,36,189,11,210,132,241,54,
    12,182,65,226,239,46,156,160,157,131,181,218,8,155,71,92,
    173,70,220,227,17,111,192,224,13,144,248,187,167,71,52,161,
    223,189,134,190,11,191,197,191,46,250,14,212,50,22,207,101,
    150,135,105,226,134,201,126,26,26,244,189,73,5,121,218,167,
    98,161,112,249,99,114,249,191,129,253,29,24,133,203,143,1,
    39,22,164,75,100,192,49,87,142,13,152,118,225,72,192,216,
    130,192,132,35,92,166,65,2,12,5,156,24,240,181,73,29,
    142,177,180,208,73,119,193,82,218,223,99,118,146,158,105,1,
    142,27,112,212,128,254,179,35,131,26,14,90,144,253,11,190,
    217,226,73,23,121,82,3,142,176,180,224,196,130,227,38,60,
    197,78,216,52,110,145,250,226,217,17,106,138,45,253,174,133,
    210,238,214,212,37,85,130,48,75,188,88,170,13,172,187,19,
    47,243,98,183,31,198,147,72,126,252,82,253,46,76,14,186,
    237,178,103,154,239,76,60,53,114,120,168,73,54,137,39,138,
    167,76,19,169,150,176,178,31,38,129,27,167,193,97,36,213,
    34,205,231,238,135,145,116,93,254,248,219,120,146,102,234,227,
    44,75,51,135,204,202,141,81,234,85,35,200,168,126,148,230,
    178,75,171,241,50,14,77,175,168,247,254,132,103,36,1,88,
    92,26,28,200,220,207,194,137,66,111,233,25,169,55,205,214,
    37,63,113,145,255,17,139,94,224,41,239,221,222,40,141,101,
    239,121,24,28,230,163,176,247,137,140,159,100,105,24,184,123,
    105,122,144,135,113,111,40,227,7,189,189,195,48,10,122,31,
    58,159,245,38,83,53,74,147,30,182,133,137,146,104,162,168,
    55,195,56,59,216,237,42,45,243,34,28,186,33,43,232,142,
    100,52,145,25,201,151,223,34,17,196,170,88,22,77,97,138,
    174,232,96,173,129,143,41,182,140,37,177,27,146,138,62,169,
    77,8,51,75,76,253,19,216,123,232,252,3,3,178,45,66,
    204,24,127,130,92,140,184,233,211,55,131,191,253,158,108,163,
    91,199,38,225,64,55,30,49,202,16,110,216,243,33,57,62,
    1,134,74,3,198,77,208,16,66,228,105,76,101,83,42,177,
    59,77,99,224,228,22,228,255,56,59,67,178,10,104,123,140,
    14,216,116,29,151,250,11,163,178,223,37,193,119,25,25,106,
    20,230,233,139,132,237,79,117,230,81,31,109,242,197,244,243,
    189,177,244,85,190,141,13,95,166,135,182,239,37,73,170,108,
    47,8,108,79,169,44,220,59,84,50,183,85,106,223,207,187,
    45,114,248,90,9,174,106,190,233,164,4,19,57,30,193,164,
    95,130,208,87,248,178,206,47,108,255,92,42,4,198,40,13,
    114,108,167,41,134,82,57,36,164,186,130,197,135,229,114,140,
    192,110,179,196,75,46,163,125,213,102,232,121,121,238,242,114,
    212,206,40,163,209,207,189,232,80,42,234,159,43,79,225,170,
    84,213,11,205,21,103,55,72,211,82,81,50,158,155,164,73,
    48,69,57,67,255,77,18,225,6,163,109,25,8,111,215,16,
    107,11,88,54,161,131,216,91,53,124,82,201,42,144,198,40,
    187,78,6,0,246,188,40,226,7,34,238,4,163,76,215,224,
    48,193,186,49,9,109,170,209,96,135,0,237,220,166,98,139,
    138,59,165,250,243,178,65,231,188,13,222,161,117,13,86,220,
    55,11,21,43,34,237,158,33,210,205,83,34,97,84,236,19,
    33,12,162,205,41,33,76,50,66,246,168,64,63,81,13,1,
    128,159,107,152,103,211,56,171,164,114,179,132,171,67,24,172,
    3,113,88,3,162,67,94,97,20,58,55,47,51,227,246,235,
    51,227,80,155,241,167,180,238,114,129,159,14,227,166,45,124,
    114,190,81,24,149,13,250,4,43,211,77,50,104,221,148,155,
    184,207,61,77,58,188,97,241,166,199,41,132,142,32,218,194,
    186,98,17,210,246,77,184,94,108,68,57,17,126,146,165,47,
    167,118,186,111,43,40,101,120,120,63,223,185,159,255,10,67,
    130,253,136,131,140,14,10,154,246,153,156,100,72,239,22,191,
    104,202,186,76,95,183,216,70,208,228,180,169,179,167,216,208,
    28,161,114,149,81,96,154,171,149,219,149,149,73,232,95,208,
    162,109,54,177,9,155,248,180,5,75,230,166,28,33,57,181,
    224,175,248,124,68,198,38,125,37,80,18,233,244,181,220,172,
    18,41,231,252,232,12,98,230,164,144,243,22,137,86,18,174,
    9,21,62,232,49,73,100,226,192,223,128,147,47,1,127,5,
    194,2,186,188,96,13,243,147,30,114,233,58,117,255,19,112,
    240,153,177,209,25,154,125,70,17,158,144,156,249,7,220,85,
    239,123,159,194,223,107,145,235,196,4,65,123,148,89,164,87,
    245,61,202,170,248,202,32,250,94,251,144,117,150,216,228,164,
    145,151,83,55,77,97,179,162,240,105,16,172,114,34,140,75,
    243,194,215,162,94,206,37,201,62,57,69,23,109,0,183,197,
    186,81,195,204,79,168,120,187,130,139,40,219,230,32,228,246,
    249,136,93,219,181,92,29,37,127,67,146,88,44,251,74,147,
    99,211,153,89,42,102,52,74,102,188,87,49,67,114,236,126,
    197,57,56,149,6,65,224,196,16,120,144,194,124,133,206,48,
    22,200,6,12,154,196,33,206,47,69,65,49,81,198,52,90,
    239,204,198,192,230,217,213,134,171,80,160,29,76,197,203,185,
    198,16,242,241,195,200,139,247,2,239,209,87,180,36,173,235,
    151,164,51,74,37,86,235,74,16,97,196,101,122,240,235,59,
    165,50,207,231,26,63,222,197,21,42,37,152,45,65,234,115,
    208,248,195,72,218,177,140,247,240,232,53,10,39,246,126,228,
    13,217,83,102,161,228,231,165,146,138,93,125,126,67,206,41,
    50,237,166,182,159,38,24,232,15,125,149,102,118,32,241,52,
    34,3,251,109,155,119,9,59,204,109,111,15,191,122,190,210,
    4,56,203,101,206,249,188,108,152,115,122,119,240,130,170,115,
    247,180,139,135,206,16,179,218,175,75,35,233,147,80,21,242,
    57,145,213,108,194,125,19,79,25,106,170,99,219,251,84,252,
    152,138,251,240,58,118,134,30,174,48,160,165,200,120,77,12,
    63,45,193,9,209,153,142,95,208,216,252,34,157,63,251,62,
    116,214,55,34,5,169,155,229,85,202,2,200,69,58,230,14,
    218,116,119,64,45,75,196,244,133,31,202,116,102,200,220,185,
    177,247,127,37,184,243,222,107,213,193,225,156,242,187,200,45,
    234,10,118,52,185,199,162,76,189,235,218,241,225,254,214,108,
    60,185,126,38,61,37,181,219,110,205,89,101,14,22,90,128,
    160,114,94,169,87,117,14,249,160,210,237,132,115,162,233,70,
    45,55,102,95,138,167,152,192,96,254,124,196,234,187,134,78,
    161,79,33,106,85,86,216,196,34,145,47,220,25,150,208,105,
    50,73,228,77,38,50,9,78,83,96,254,50,87,40,188,175,
    57,93,229,36,152,239,110,224,115,145,148,164,89,77,81,246,
    98,163,162,225,188,253,201,16,30,151,158,236,210,105,228,52,
    250,58,228,71,29,111,171,80,235,252,18,202,240,91,129,52,
    144,145,84,114,150,135,20,13,46,14,137,129,196,205,40,157,
    226,233,133,79,1,248,30,185,238,252,35,247,207,9,46,80,
    156,188,40,114,55,49,118,183,172,150,224,173,241,220,253,167,
    150,140,46,27,116,174,59,205,29,166,250,74,165,63,223,209,
    149,91,19,227,158,78,106,187,94,172,175,93,248,42,193,185,
    71,197,155,165,29,25,177,250,16,196,39,12,125,182,67,140,
    243,190,205,219,180,179,67,237,119,177,136,31,236,148,26,237,
    104,141,62,242,242,208,47,20,226,155,194,248,129,178,103,246,
    116,14,247,166,143,211,4,173,30,69,40,223,214,165,157,250,
    211,92,201,152,83,215,139,29,30,71,169,127,32,3,125,175,
    165,238,92,222,231,73,26,123,216,126,123,102,15,244,67,49,
    195,218,185,239,65,70,163,174,157,107,205,101,22,122,81,248,
    141,188,100,69,182,130,147,226,41,38,187,100,69,238,193,70,
    34,31,149,31,249,246,114,134,33,9,13,245,6,222,225,47,
    134,96,134,114,38,135,97,78,11,95,61,55,168,8,75,4,
    49,118,201,172,232,93,159,96,238,232,215,233,181,190,55,120,
    68,176,203,63,197,130,238,207,90,43,45,209,52,232,166,214,
    20,109,209,17,150,88,238,180,204,86,179,213,48,145,33,212,
    178,46,218,102,171,189,44,46,254,111,35,123,218,198,118,187,
    37,254,7,27,147,249,63,
};

EmbeddedPython embedded_m5_internal_param_SimpleExtLink(
    "m5/internal/param_SimpleExtLink.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_SimpleExtLink.py",
    "m5.internal.param_SimpleExtLink",
    data_m5_internal_param_SimpleExtLink,
    2167,
    6691);

} // anonymous namespace
