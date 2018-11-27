#include "sim/init.hh"

namespace {

const uint8_t data_m5_util_region[] = {
    120,156,213,90,205,111,28,73,21,127,213,61,51,246,140,61,
    118,62,157,56,27,146,78,118,147,140,217,96,243,145,101,97,
    149,181,146,16,72,64,108,144,218,17,43,204,134,214,100,186,
    60,110,123,220,61,238,110,111,108,52,22,104,29,137,203,114,
    224,176,135,69,2,113,64,66,226,79,224,194,63,193,63,192,
    74,112,128,3,7,184,47,239,189,170,234,233,182,243,185,158,
    113,18,143,187,166,186,250,245,235,87,175,126,239,171,122,90,
    160,255,42,120,92,115,0,146,211,22,128,15,32,1,150,4,
    248,2,30,2,236,0,252,100,81,128,20,212,91,180,192,183,
    204,101,59,187,108,131,180,249,114,9,252,18,200,50,95,46,
    103,151,43,224,87,204,77,35,217,232,8,200,81,240,71,97,
    213,130,248,164,37,71,192,175,210,53,89,5,191,6,254,24,
    248,227,176,99,195,205,29,1,31,35,231,26,16,69,189,72,
    49,145,167,24,3,137,15,154,4,255,16,236,88,176,56,206,
    167,135,193,63,194,167,117,240,143,210,205,139,19,32,241,223,
    162,127,28,23,250,164,148,157,148,242,87,74,249,43,22,61,
    54,119,114,44,127,114,220,156,32,77,159,1,210,228,78,142,
    23,89,231,184,149,242,220,74,187,184,149,242,220,74,121,110,
    250,164,6,183,110,203,49,106,144,122,12,174,97,103,28,207,
    252,41,192,129,213,138,238,142,235,238,4,143,142,80,119,146,
    71,169,139,223,120,39,19,200,186,233,234,30,93,15,17,23,
    39,96,161,113,18,145,146,142,98,227,133,178,237,5,225,82,
    203,96,72,224,113,131,48,244,30,48,128,16,51,190,2,12,
    195,8,49,130,200,121,168,48,194,200,89,44,19,88,168,83,
    209,96,65,72,32,80,168,51,170,129,178,88,5,119,161,65,
    207,75,190,137,205,221,229,32,113,162,251,43,178,149,58,205,
    206,131,230,86,226,180,162,181,110,51,150,137,211,145,73,226,
    164,203,205,208,105,134,91,78,148,46,203,88,147,182,132,22,
    143,142,239,144,136,37,236,160,88,11,13,132,59,220,73,170,
    216,94,213,243,153,111,208,100,26,68,154,18,89,34,59,75,
    106,136,154,228,26,54,115,203,209,154,156,251,48,240,55,146,
    229,96,238,150,92,187,25,71,129,239,221,143,162,213,36,88,
    155,107,203,181,183,230,146,184,53,215,221,74,151,163,112,14,
    207,54,210,160,51,23,203,118,16,133,179,56,202,250,243,98,
    217,141,61,239,75,196,149,88,183,72,22,58,108,35,229,20,
    201,0,208,67,123,17,220,17,212,89,181,81,110,18,239,78,
    95,200,116,171,43,121,46,46,15,149,177,97,5,12,90,240,
    10,11,222,73,61,239,204,30,177,11,202,69,105,247,8,121,
    55,222,200,9,233,150,140,104,131,151,79,122,222,217,231,147,
    143,52,246,189,102,39,57,24,1,219,168,64,231,185,215,221,
    42,136,236,18,249,193,72,139,234,60,247,202,72,43,215,61,
    239,252,62,109,234,224,164,13,81,183,175,27,105,27,53,48,
    206,213,11,155,107,120,41,173,241,201,90,228,111,16,168,211,
    17,62,245,163,150,231,185,44,30,225,214,165,81,151,124,152,
    75,228,238,24,53,227,5,145,7,39,183,75,156,94,35,110,
    135,176,169,136,138,168,230,62,74,248,110,148,28,104,100,248,
    54,60,57,50,180,99,217,76,49,26,236,35,56,232,41,229,
    130,3,35,99,208,202,181,52,187,103,247,92,238,232,208,161,
    202,32,155,121,249,29,0,219,193,151,95,126,211,103,83,125,
    243,249,86,185,50,124,169,200,119,92,126,5,86,153,220,219,
    87,94,129,85,38,15,60,11,121,215,238,214,169,153,160,102,
    146,154,23,228,193,201,113,95,132,199,121,112,66,154,203,180,
    153,255,38,57,217,127,111,195,211,252,55,150,126,186,44,20,
    228,188,165,113,228,116,58,98,124,249,168,241,229,85,227,203,
    107,84,7,62,228,26,78,21,129,88,189,97,229,67,157,58,
    21,122,170,110,67,127,79,74,73,240,225,112,221,81,19,114,
    26,113,51,108,203,25,39,90,114,126,154,164,205,56,189,236,
    200,208,159,153,173,57,248,199,81,33,8,91,157,13,31,227,
    0,233,33,72,183,156,165,141,176,149,226,189,88,46,68,38,
    74,56,209,135,50,238,52,187,196,71,113,78,102,57,52,216,
    250,184,69,10,72,52,184,24,83,62,195,63,158,167,83,84,
    192,244,182,5,169,128,30,182,92,228,197,115,212,95,72,109,
    250,66,242,109,1,97,254,110,155,64,25,183,40,55,70,29,
    165,92,51,79,125,100,49,145,13,43,21,130,48,145,146,133,
    17,72,238,4,36,78,64,11,18,208,138,36,4,174,31,133,
    29,12,103,33,138,143,225,237,65,228,52,227,246,198,154,12,
    211,4,131,96,39,122,32,253,203,206,5,223,233,198,17,226,
    69,250,13,194,89,74,179,233,32,13,65,45,72,130,16,181,
    22,182,164,123,24,116,30,156,110,116,59,50,37,152,94,79,
    211,56,184,191,145,202,239,198,113,20,115,18,223,164,59,85,
    26,18,202,7,158,215,176,13,203,86,39,81,20,113,59,225,
    1,236,12,26,186,39,144,201,21,226,118,132,120,138,35,162,
    38,38,69,73,76,90,71,132,45,14,89,89,44,47,229,189,
    1,174,19,170,146,86,136,190,108,152,94,178,96,106,161,65,
    52,119,146,137,12,238,141,11,9,42,43,153,81,26,238,71,
    247,161,6,251,235,196,205,226,201,100,194,91,70,120,10,237,
    61,150,127,90,39,35,1,12,93,44,134,0,27,210,205,76,
    54,235,153,100,27,190,202,24,86,104,221,183,115,146,237,9,
    0,11,153,141,166,108,61,241,91,70,208,30,219,236,244,170,
    128,232,74,6,9,101,187,171,101,88,232,83,17,133,75,28,
    52,209,42,69,99,122,64,242,11,208,149,181,19,36,236,97,
    232,79,201,247,142,67,5,174,19,44,57,180,101,128,121,166,
    239,24,74,244,56,29,180,211,86,20,166,205,32,148,190,243,
    32,72,151,131,144,9,103,51,54,152,99,246,121,100,183,106,
    82,60,213,207,201,225,147,3,200,81,106,142,193,176,227,89,
    58,206,70,175,231,144,120,222,15,137,51,69,11,40,77,138,
    139,226,139,44,132,245,136,133,176,158,109,33,194,47,176,16,
    228,230,209,13,134,105,208,106,118,94,21,189,115,50,112,119,
    255,186,182,161,187,71,215,152,20,105,221,10,214,109,215,205,
    81,172,10,163,235,246,147,116,157,106,197,225,245,45,214,112,
    24,165,125,45,63,69,201,76,251,50,40,153,193,253,52,37,
    207,237,86,242,185,188,146,45,246,44,69,240,106,5,114,26,
    72,88,164,100,3,99,171,68,103,208,145,75,41,37,27,74,
    23,141,86,51,36,101,232,44,100,166,31,235,15,86,15,228,
    252,87,50,61,88,147,24,98,159,87,15,226,145,122,224,140,
    101,206,232,65,110,166,232,198,57,255,162,181,223,171,139,190,
    34,14,94,7,35,106,122,251,209,193,222,136,82,50,88,248,
    186,209,65,144,228,225,16,7,237,229,39,225,225,5,217,5,
    213,36,219,251,199,195,94,93,48,30,174,244,241,224,49,30,
    238,203,173,40,115,215,26,28,74,51,69,80,28,188,34,40,
    89,254,85,81,17,13,46,226,118,213,116,148,161,114,102,199,
    91,97,152,120,119,101,156,110,185,180,99,230,158,166,134,246,
    251,251,5,222,163,202,191,161,20,125,148,221,127,141,184,209,
    11,156,138,133,69,95,189,106,79,150,38,75,213,209,234,24,
    126,106,213,106,181,198,137,189,202,134,147,189,187,119,228,31,
    7,184,123,167,43,190,154,169,248,198,168,190,163,249,39,127,
    4,170,239,18,153,230,138,49,93,231,37,51,179,142,115,163,
    153,80,108,65,171,105,154,42,144,162,181,179,28,117,100,162,
    226,250,247,159,88,243,173,201,184,45,51,206,148,32,44,5,
    237,13,42,2,55,48,30,45,49,135,4,21,78,25,64,219,
    225,18,82,21,89,75,185,80,165,235,67,99,13,92,31,158,
    194,78,155,19,99,143,219,21,65,86,241,49,42,209,239,111,
    232,48,58,72,211,154,15,151,220,202,35,230,64,60,61,120,
    16,232,173,229,32,12,82,207,251,13,232,173,38,192,170,191,
    48,19,182,105,71,217,244,14,80,221,138,115,192,153,172,88,
    122,74,88,189,138,158,200,230,67,126,192,165,247,45,46,221,
    228,158,43,24,35,151,132,173,168,187,53,104,64,211,174,249,
    39,153,65,226,28,142,246,103,145,213,235,180,30,61,142,104,
    40,54,150,229,106,49,72,254,220,122,216,70,116,94,136,102,
    183,139,11,193,246,50,220,213,112,223,64,38,191,133,98,253,
    87,144,254,76,94,122,101,109,56,1,122,221,157,205,128,43,
    175,194,157,180,114,201,107,234,206,123,135,105,245,178,45,135,
    31,139,117,27,252,93,59,139,217,68,83,106,102,191,154,210,
    104,115,192,115,85,155,232,109,25,202,205,110,60,255,123,51,
    233,138,86,241,35,112,51,20,141,211,35,126,151,211,184,209,
    89,22,201,232,89,155,231,180,210,111,222,155,130,109,198,76,
    207,162,215,225,113,141,226,219,194,122,13,222,79,173,189,232,
    225,61,90,181,29,111,103,232,231,32,16,37,1,185,30,134,
    151,18,102,208,19,163,160,242,7,208,101,57,136,67,98,92,
    140,62,162,104,175,131,217,27,85,86,156,247,72,238,17,51,
    145,225,149,239,106,223,168,35,67,207,251,211,174,101,32,128,
    148,141,156,255,21,6,248,74,255,212,177,201,177,110,151,200,
    14,182,203,220,86,96,243,175,162,87,230,77,55,54,106,172,
    96,226,127,136,94,133,71,68,110,4,153,148,97,122,123,4,
    122,54,224,229,233,237,81,232,141,168,58,103,212,36,172,241,
    47,137,8,199,222,70,246,235,151,152,64,20,8,206,138,220,
    77,42,219,143,255,7,189,18,57,70,218,229,83,148,154,102,
    199,82,110,50,99,185,235,94,204,146,78,147,168,124,181,2,
    235,167,197,250,103,98,15,175,209,2,175,62,245,37,208,151,
    180,148,36,202,181,189,4,162,79,128,90,93,20,232,140,63,
    18,249,91,245,44,254,146,123,242,200,19,159,188,119,22,159,
    229,230,136,83,160,39,239,230,245,24,141,32,233,251,72,155,
    5,75,149,32,223,201,165,186,229,204,182,24,156,111,24,127,
    165,54,39,147,4,83,43,68,22,111,78,54,170,153,231,224,
    247,39,212,187,206,237,13,110,93,110,3,110,87,220,139,134,
    228,254,144,66,44,230,20,158,247,103,226,122,149,49,78,91,
    235,148,117,85,196,37,81,195,207,49,171,46,142,97,123,198,
    174,89,199,172,67,246,25,187,78,99,214,169,194,216,132,85,
    237,59,169,204,138,251,65,109,71,25,8,219,200,123,170,87,
    240,237,175,23,156,145,82,140,114,66,201,70,39,29,142,117,
    243,204,255,14,89,96,30,199,217,102,1,170,2,185,146,1,
    177,209,134,204,215,158,210,137,134,217,159,80,251,180,63,179,
    96,189,206,59,227,102,195,150,83,103,149,56,53,138,187,181,
    34,115,96,253,236,131,154,65,255,10,134,211,251,127,246,253,
    23,191,148,216,93,7,156,55,250,87,168,165,200,163,82,127,
    122,145,234,82,38,238,126,3,116,169,48,148,132,159,18,178,
    95,19,55,42,142,42,54,38,252,165,106,185,106,227,103,4,
    143,183,171,101,13,213,181,102,128,238,56,91,33,78,215,104,
    133,206,42,148,221,59,174,215,165,199,105,255,9,92,19,149,
    70,152,162,62,80,120,131,76,239,23,168,153,29,252,140,138,
    57,196,191,32,203,33,20,4,40,89,226,247,34,251,152,74,
    233,133,76,229,223,185,169,144,199,11,200,74,2,178,166,128,
    232,2,170,137,178,162,59,139,145,159,128,121,179,209,51,45,
    186,227,37,27,166,110,221,246,173,226,184,109,198,237,226,56,
    152,241,82,113,92,152,241,114,113,188,100,198,43,197,241,178,
    30,191,205,201,229,8,219,41,25,197,133,196,121,247,93,231,
    66,242,14,30,102,224,220,238,129,171,206,238,129,221,20,243,
    187,41,230,13,69,127,173,184,206,160,125,36,126,127,193,123,
    6,131,246,111,236,62,101,146,254,135,56,78,176,233,159,204,
    125,130,79,255,246,249,231,65,251,205,12,71,228,7,216,221,
    170,31,154,240,47,103,216,73,234,95,26,242,139,88,30,208,
    191,46,225,125,12,14,112,170,156,170,27,6,155,92,251,178,
    51,219,228,118,139,219,159,115,27,186,223,26,146,15,97,15,
    113,85,253,248,104,158,127,243,243,3,108,166,170,85,139,143,
    15,166,62,24,23,231,241,51,41,38,173,106,181,46,248,99,
    61,174,45,139,50,6,193,178,53,38,204,231,255,254,190,244,
    86,
};

EmbeddedPython embedded_m5_util_region(
    "m5/util/region.py",
    "/home/vidushi/GemDroid_booksim/gem5/src/python/m5/util/region.py",
    "m5.util.region",
    data_m5_util_region,
    2817,
    11391);

} // anonymous namespace
