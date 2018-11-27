#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_CowDiskImage[] = {
    120,156,197,88,91,111,27,199,21,62,179,75,82,34,37,90,
    146,101,217,150,173,86,44,2,163,108,208,136,73,90,55,189,
    24,70,211,184,13,82,160,74,186,106,107,135,49,178,93,113,
    135,226,82,228,46,177,59,178,194,64,122,169,140,182,111,253,
    17,69,31,250,63,250,191,218,243,157,225,174,86,23,7,6,
    218,210,18,119,48,59,59,115,230,92,190,115,153,233,209,236,
    175,202,207,207,91,68,89,95,17,133,252,83,52,34,26,43,
    234,42,82,90,81,184,78,135,85,74,127,72,97,149,94,18,
    117,29,210,14,157,113,199,165,47,28,138,151,101,77,141,70,
    174,140,40,154,54,72,87,168,91,165,167,241,26,85,116,141,
    14,27,148,254,145,148,82,177,162,103,225,2,133,139,244,146,
    169,115,167,46,4,23,41,108,72,167,78,225,146,116,26,52,
    93,37,189,68,93,38,190,64,221,38,147,122,155,73,221,16,
    82,255,2,169,144,191,220,162,176,137,233,204,203,231,152,89,
    193,76,217,227,134,80,89,201,57,91,165,238,90,222,191,89,
    234,175,151,250,183,164,191,66,122,141,134,27,52,188,77,195,
    59,196,10,9,87,139,29,238,146,118,105,184,73,221,77,210,
    252,187,75,103,172,159,112,173,180,226,158,172,184,89,172,184,
    47,43,182,168,187,69,154,127,247,237,138,26,237,181,55,88,
    231,209,191,249,175,205,58,39,179,204,205,11,157,102,81,18,
    251,81,220,79,34,7,223,107,104,96,161,30,154,133,153,169,
    62,130,169,254,73,98,167,208,153,153,234,148,152,176,130,44,
    35,135,78,165,115,234,208,180,77,39,138,134,21,10,93,58,
    225,109,170,96,224,64,209,153,67,207,93,76,56,229,182,194,
    202,253,54,85,140,181,211,80,148,107,41,45,208,105,149,78,
    170,180,247,236,196,193,192,97,157,210,127,208,215,91,66,116,
    81,136,58,116,194,109,133,206,42,116,90,163,167,60,137,135,
    134,117,136,175,158,157,176,164,60,178,215,174,48,183,187,37,
    113,33,74,24,165,113,48,214,102,157,251,254,36,72,131,177,
    255,81,114,252,36,202,14,63,25,7,7,186,221,200,39,38,
    217,206,36,48,3,79,86,186,80,201,120,98,132,98,18,107,
    179,196,157,126,20,135,254,56,9,143,70,218,44,130,156,223,
    143,70,218,247,229,227,39,227,73,146,154,95,166,105,146,122,
    208,170,12,142,146,160,88,1,157,246,70,73,166,219,216,77,
    182,241,64,222,96,118,127,34,20,193,128,112,139,197,161,206,
    122,105,52,49,108,44,75,17,179,65,173,13,51,73,147,61,
    231,166,19,6,38,120,175,51,72,198,186,243,34,10,143,178,
    65,212,249,88,143,159,164,73,20,250,251,73,114,152,69,227,
    206,129,30,63,236,236,31,69,163,176,243,161,247,155,206,100,
    106,6,73,220,225,177,40,54,154,53,52,234,92,213,205,14,
    207,186,137,93,142,163,3,63,18,249,252,129,30,77,116,10,
    246,178,123,224,64,173,170,101,85,83,174,106,171,38,247,170,
    252,184,106,203,89,82,187,17,36,236,65,106,224,203,205,17,
    245,119,18,219,177,233,15,29,74,183,128,151,33,255,20,12,
    204,168,217,195,55,71,190,253,22,170,177,163,67,23,40,176,
    131,39,130,49,6,27,207,124,4,179,199,36,64,169,210,176,
    70,22,64,140,59,139,168,116,138,150,167,131,140,195,196,43,
    148,253,237,34,133,120,149,88,245,236,211,60,116,155,183,250,
    147,96,114,175,13,198,119,5,24,102,16,101,201,113,44,234,
    71,95,188,104,143,117,242,217,244,211,253,161,238,153,108,155,
    7,62,79,142,90,189,32,142,19,211,10,194,176,21,24,147,
    70,251,71,70,103,45,147,180,30,100,237,58,236,189,150,99,
    171,160,55,157,228,88,130,221,25,75,246,37,140,122,134,95,
    4,180,190,232,63,211,134,113,49,72,194,140,199,65,226,64,
    27,15,76,154,27,220,124,152,111,39,0,108,215,114,184,100,
    122,212,55,13,65,94,144,101,190,108,135,113,1,25,86,191,
    8,70,71,218,96,126,102,2,195,187,162,107,55,154,39,204,
    238,66,208,92,78,232,206,143,147,56,156,50,155,81,239,45,
    112,112,87,192,182,76,128,219,6,67,109,129,219,26,53,25,
    122,171,78,15,18,85,102,64,19,144,221,134,252,36,134,87,
    179,224,193,128,59,227,16,211,118,36,70,136,104,226,130,45,
    244,176,216,3,158,189,251,104,182,208,124,43,151,126,78,42,
    104,94,86,193,187,216,214,17,185,123,238,76,194,194,141,118,
    47,184,209,230,185,27,113,68,220,131,59,56,112,154,115,119,
    112,161,131,244,241,12,251,112,52,54,63,127,46,33,94,52,
    227,173,66,226,90,14,86,15,8,44,195,240,160,4,67,15,
    70,17,12,122,155,175,210,226,246,27,211,226,129,213,226,15,
    176,237,242,12,61,77,65,77,67,245,96,122,103,166,83,209,
    231,19,238,76,239,64,159,101,77,222,225,20,247,52,110,74,
    174,146,124,39,89,223,134,15,171,96,219,169,0,103,125,151,
    110,207,114,80,6,111,159,164,201,87,211,86,210,111,25,202,
    121,120,244,32,219,121,144,253,140,227,65,235,177,68,24,27,
    17,172,207,167,122,146,178,111,215,229,197,250,171,47,190,235,
    207,82,8,107,28,249,92,12,37,122,150,240,148,153,20,81,
    105,158,74,110,20,74,6,207,63,193,158,13,209,176,75,119,
    248,105,40,97,204,79,36,58,74,81,33,95,249,249,5,116,
    13,113,53,161,236,243,246,44,219,34,17,100,243,190,123,1,
    47,243,145,199,123,27,156,229,222,86,163,2,29,120,92,112,
    12,7,248,11,73,213,165,232,207,4,36,176,193,103,46,35,
    206,137,7,6,93,199,244,47,73,2,207,53,57,206,177,174,
    231,204,66,19,123,102,246,129,76,181,41,239,215,244,215,82,
    212,58,115,73,33,61,185,179,186,170,156,158,42,133,179,10,
    132,94,43,5,85,46,122,53,108,52,8,50,76,179,254,235,
    22,254,123,30,0,139,106,136,131,210,156,208,181,104,119,243,
    193,216,199,231,216,66,236,191,175,214,157,18,98,190,143,230,
    157,2,44,42,31,251,255,243,184,125,57,88,151,242,149,111,
    3,228,175,192,72,69,88,95,169,73,205,80,38,82,120,69,
    53,247,138,247,11,175,208,18,181,95,74,229,141,214,129,253,
    207,28,197,199,30,174,83,112,226,168,144,174,82,183,6,255,
    145,178,82,205,220,75,229,225,12,97,240,66,74,16,229,236,
    90,181,21,16,176,214,69,243,213,60,195,7,12,252,104,20,
    140,247,195,224,241,239,177,35,182,237,229,14,231,228,50,172,
    150,101,128,179,168,87,137,33,175,239,230,178,188,152,103,232,
    120,143,55,40,100,16,71,9,147,158,196,139,223,13,116,107,
    172,199,251,124,220,26,68,147,86,127,20,28,136,157,220,153,
    140,159,230,50,26,49,244,229,68,156,33,40,237,38,173,94,
    18,115,132,63,234,153,36,109,133,154,143,32,58,108,189,211,
    146,244,208,138,178,86,176,207,95,131,158,177,224,191,232,198,
    82,233,5,233,65,38,69,221,225,49,186,243,182,179,207,231,
    204,136,75,217,63,228,58,178,167,159,34,214,75,245,106,61,
    137,243,37,31,45,204,212,70,181,31,161,249,30,154,7,244,
    6,82,66,7,22,196,78,80,93,141,3,79,93,201,89,168,
    60,239,51,172,204,174,122,242,241,235,120,178,189,186,152,249,
    115,13,51,245,2,78,187,104,235,72,12,221,70,62,184,36,
    237,178,12,54,243,219,145,27,50,184,66,221,85,92,43,96,
    100,13,225,96,225,191,13,7,226,71,243,246,160,231,255,211,
    40,224,189,255,38,69,240,164,226,252,166,8,160,202,242,53,
    109,4,24,170,188,46,47,11,39,199,254,205,107,97,231,247,
    82,29,24,109,109,118,111,190,2,75,60,177,251,127,89,88,
    46,151,170,56,162,124,80,72,118,38,21,211,244,86,169,110,
    22,67,170,167,92,222,112,109,125,34,194,251,142,45,175,207,
    225,89,41,116,128,3,93,172,143,253,171,122,176,21,52,24,
    10,38,19,29,135,231,213,177,124,153,39,12,16,178,2,58,
    47,88,184,20,190,197,207,85,119,132,92,37,49,197,132,213,
    194,1,231,108,76,65,111,63,55,99,27,65,238,60,60,123,
    48,162,13,200,69,44,246,126,90,152,229,59,215,67,211,4,
    251,124,90,201,162,175,53,78,97,175,49,139,139,40,57,84,
    156,15,153,173,87,160,126,192,242,9,213,111,156,0,130,82,
    25,225,77,12,35,110,20,234,145,54,250,26,20,25,136,56,
    59,226,134,154,83,106,50,229,195,151,156,98,248,125,228,251,
    115,79,64,63,230,13,190,160,89,0,68,2,170,113,10,218,
    224,255,122,165,174,36,199,95,186,188,181,204,161,104,183,245,
    250,52,243,36,28,173,20,214,146,27,198,60,201,138,119,226,
    172,185,27,140,237,173,145,92,133,120,48,150,247,86,110,112,
    113,44,123,142,147,83,146,61,157,178,39,74,1,34,245,134,
    183,131,113,156,248,199,15,119,114,161,118,172,80,133,68,114,
    201,57,126,248,138,105,123,209,216,222,164,153,181,75,223,195,
    52,224,254,198,165,209,76,167,81,48,2,74,32,82,62,108,
    32,233,229,125,193,111,241,38,89,253,74,60,21,171,167,250,
    32,202,152,142,16,185,28,98,96,11,41,249,175,193,91,121,
    241,188,65,98,43,105,123,57,240,24,146,102,143,185,193,21,
    89,125,165,174,106,14,238,98,93,213,80,77,85,81,203,205,
    186,91,175,213,171,46,3,9,35,235,170,225,214,27,203,202,
    254,111,51,168,26,206,246,114,93,253,7,195,181,210,77,
};

EmbeddedPython embedded_m5_internal_param_CowDiskImage(
    "m5/internal/param_CowDiskImage.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_CowDiskImage.py",
    "m5.internal.param_CowDiskImage",
    data_m5_internal_param_CowDiskImage,
    2143,
    6575);

} // anonymous namespace
