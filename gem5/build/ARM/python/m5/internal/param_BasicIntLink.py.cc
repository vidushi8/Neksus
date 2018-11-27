#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BasicIntLink[] = {
    120,156,197,88,235,111,227,198,17,159,37,41,217,146,165,179,
    124,62,223,203,190,51,139,224,16,53,104,172,188,174,233,227,
    112,104,146,75,131,20,141,147,80,5,124,167,6,101,105,114,
    37,81,166,72,129,92,159,163,192,254,82,31,218,162,95,250,
    71,20,253,208,255,163,255,87,59,51,75,210,244,227,146,0,
    105,117,182,184,88,46,103,103,231,241,155,217,217,245,33,255,
    171,225,243,43,27,32,251,155,0,8,240,39,32,2,152,10,
    24,8,16,82,64,176,14,7,53,72,223,131,160,6,47,0,
    6,6,72,3,78,177,99,194,239,13,136,91,60,167,14,145,
    201,35,2,230,77,144,22,12,106,176,23,175,129,37,235,112,
    208,132,244,143,32,132,136,5,60,13,150,32,88,134,23,200,
    29,59,13,102,184,12,65,147,59,13,8,86,184,211,132,121,
    7,228,10,12,144,249,18,12,218,200,234,13,100,117,141,89,
    253,155,88,5,248,229,6,4,109,34,71,89,158,17,165,69,
    148,188,198,53,230,178,90,72,214,129,193,90,209,191,94,233,
    175,87,250,55,42,253,141,74,255,102,165,127,139,251,171,32,
    215,96,114,27,38,119,96,114,23,134,104,160,78,41,197,38,
    72,19,38,91,48,216,2,137,191,77,56,69,27,6,107,149,
    25,247,120,198,245,114,198,125,158,177,13,131,109,144,248,187,
    175,103,212,161,223,221,64,191,132,255,193,191,46,250,5,84,
    11,155,231,50,205,194,36,118,195,120,152,132,6,125,175,83,
    67,94,244,169,89,202,221,249,17,185,243,95,192,190,12,140,
    220,157,39,128,140,5,233,18,25,112,194,157,19,3,230,93,
    56,22,48,177,32,48,225,24,151,169,145,0,35,1,167,6,
    124,101,18,193,9,182,22,58,224,62,88,74,251,114,194,14,
    208,156,150,224,164,6,199,53,232,63,61,54,104,224,160,1,
    233,63,225,155,45,102,186,204,76,13,56,198,214,130,83,11,
    78,234,176,135,68,56,52,105,144,250,226,233,49,106,138,35,
    253,174,133,210,238,86,212,37,85,130,48,141,189,169,84,235,
    216,119,103,94,234,77,221,15,189,44,244,63,141,213,111,195,
    248,160,219,44,8,147,108,103,230,169,177,195,51,77,50,201,
    116,166,152,99,18,75,181,130,157,97,24,7,238,52,9,14,
    35,169,150,137,157,59,12,35,233,186,252,241,211,233,44,73,
    213,199,105,154,164,14,89,149,7,163,196,43,103,144,77,253,
    40,201,100,151,86,227,101,28,98,175,136,122,56,99,142,36,
    0,75,75,147,3,153,249,105,56,83,232,44,205,145,168,137,
    91,151,220,196,77,246,21,54,189,192,83,222,219,189,113,50,
    149,189,231,97,112,152,141,195,222,39,114,250,36,77,194,192,
    221,79,146,131,44,156,246,70,114,250,176,183,127,24,70,65,
    239,3,231,179,222,108,174,198,73,220,195,177,48,86,18,45,
    20,245,46,219,102,7,169,174,211,42,71,225,200,13,89,63,
    119,44,163,153,76,73,188,236,46,73,32,58,162,37,234,194,
    20,93,209,198,94,13,31,83,108,25,43,98,55,36,13,125,
    210,154,240,101,22,136,250,7,176,239,208,245,7,6,164,91,
    132,151,9,254,4,57,24,81,211,167,111,6,127,251,146,76,
    163,71,39,38,161,64,15,30,51,198,16,108,72,249,136,220,
    30,3,3,165,6,147,58,104,0,33,238,52,162,210,57,181,
    72,78,108,12,100,110,65,246,247,243,28,226,14,160,233,49,
    238,113,232,38,46,245,39,198,100,191,75,130,239,50,48,212,
    56,204,146,163,152,205,79,125,142,162,62,218,228,139,249,231,
    251,19,233,171,108,27,7,158,37,135,182,239,197,113,162,108,
    47,8,108,79,169,52,220,63,84,50,179,85,98,63,200,186,
    13,242,247,90,129,173,146,223,124,86,96,137,252,142,88,210,
    47,65,232,43,124,97,208,186,108,255,76,42,196,197,56,9,
    50,28,39,22,35,169,28,18,82,93,195,230,131,98,57,6,
    96,183,94,192,37,147,209,80,53,25,121,94,150,185,188,28,
    141,51,200,104,246,115,47,58,148,138,232,51,229,41,92,149,
    186,122,161,69,194,236,54,41,90,232,73,182,115,227,36,14,
    230,40,102,232,191,70,18,220,102,176,181,128,224,182,129,80,
    91,194,182,14,109,132,94,199,240,73,35,43,7,26,131,236,
    38,233,15,236,120,145,39,15,4,220,41,166,152,174,193,57,
    130,85,227,16,180,169,71,147,29,194,179,179,73,205,22,53,
    247,10,237,23,100,130,246,69,19,188,69,203,26,172,183,111,
    230,26,150,97,180,123,46,140,238,156,133,17,102,196,62,133,
    131,65,65,115,22,14,38,217,32,125,156,99,159,2,13,221,
    143,159,43,136,103,203,56,29,210,184,94,128,213,33,4,86,
    97,56,170,192,208,33,167,48,6,157,59,47,179,226,246,43,
    179,226,72,91,241,93,90,182,149,163,167,205,168,105,10,159,
    92,111,228,54,101,123,62,193,206,252,22,217,179,106,201,91,
    184,197,237,197,109,222,171,120,191,227,202,64,167,15,109,96,
    221,177,8,103,67,19,110,230,123,80,70,209,62,75,147,175,
    231,118,50,180,21,20,50,60,122,144,237,60,200,126,137,249,
    192,126,204,25,70,103,4,29,243,169,156,165,24,219,13,126,
    209,241,234,114,236,186,249,22,130,22,167,253,156,29,197,118,
    230,244,148,169,148,178,210,34,141,220,44,141,76,50,255,156,
    214,108,178,133,77,184,133,79,83,176,96,110,194,217,145,139,
    10,254,138,207,135,100,107,82,87,2,149,134,78,95,139,205,
    26,145,110,206,235,231,240,178,24,125,156,55,72,178,34,218,
    234,80,162,131,30,147,36,166,0,248,11,112,213,37,224,207,
    64,72,64,135,231,33,195,193,73,15,57,116,157,200,255,0,
    156,120,174,216,227,12,29,122,70,158,154,48,50,179,247,153,
    84,111,121,191,129,191,86,178,214,169,9,130,182,39,51,175,
    171,170,219,147,85,6,43,67,232,123,109,65,214,249,168,38,
    31,141,189,140,200,116,252,154,101,252,158,37,192,178,26,194,
    164,180,32,116,45,235,213,92,18,236,147,51,108,81,238,223,
    20,235,70,5,49,63,161,230,205,18,44,162,24,251,255,203,
    184,125,49,89,87,246,43,87,39,200,95,147,32,22,139,190,
    90,231,154,161,202,164,140,138,90,17,21,239,148,81,33,57,
    107,191,224,202,155,90,131,252,127,106,8,60,26,97,157,66,
    167,18,11,100,13,6,117,138,31,46,43,69,30,94,162,72,
    103,148,6,207,109,9,108,156,93,109,182,18,2,218,187,212,
    124,189,200,244,65,14,126,20,121,211,253,192,123,252,148,86,
    164,101,253,34,224,140,66,135,78,85,7,10,22,241,50,53,
    248,245,173,66,151,231,139,76,29,111,227,2,165,14,28,40,
    65,226,115,190,248,221,88,218,83,57,221,199,227,214,56,156,
    217,195,200,27,177,159,204,92,199,207,11,29,21,59,250,226,
    70,156,81,82,218,77,108,63,137,49,195,31,250,42,73,237,
    64,226,17,68,6,246,155,54,111,15,118,152,217,222,62,126,
    245,124,165,193,127,62,140,185,210,243,210,81,198,69,221,193,
    17,117,23,237,103,23,207,153,33,150,178,207,10,27,233,211,
    79,153,235,185,122,213,145,132,251,37,30,45,212,92,103,181,
    159,82,243,99,106,30,192,43,216,18,122,184,192,30,173,68,
    166,171,99,226,105,8,62,11,85,233,190,160,153,217,229,72,
    62,250,62,145,172,175,55,242,120,174,19,165,92,162,211,46,
    181,13,218,24,6,205,98,112,133,219,22,15,182,139,27,148,
    107,60,184,10,131,14,93,43,208,200,26,165,131,165,31,154,
    14,56,142,22,29,65,238,255,52,11,56,239,188,74,21,28,
    174,56,191,45,3,136,170,126,109,157,1,38,162,168,203,171,
    202,241,177,255,206,149,176,115,253,84,122,74,106,159,221,93,
    172,194,156,79,244,250,94,233,185,66,171,242,136,242,126,169,
    217,41,87,76,243,27,149,186,153,29,41,246,176,188,193,218,
    250,152,149,119,13,93,94,159,193,211,42,109,64,7,186,88,
    30,185,151,237,160,43,104,18,200,155,205,100,28,156,85,199,
    252,101,145,48,160,148,21,192,89,193,130,165,240,13,124,46,
    135,163,165,9,11,53,217,133,181,50,0,23,236,76,70,111,
    88,184,177,75,73,238,44,61,59,228,68,157,144,203,92,236,
    252,162,116,203,189,171,161,25,39,129,116,247,233,4,246,29,
    20,88,60,177,235,244,235,183,18,123,223,201,206,59,207,206,
    99,127,112,244,4,50,146,74,94,1,30,69,154,229,39,219,
    64,226,78,154,204,241,204,197,135,23,124,143,92,119,225,251,
    206,207,112,1,58,62,112,222,163,125,167,142,59,207,6,254,
    55,172,134,224,173,253,194,157,173,22,206,134,162,76,159,103,
    14,103,161,213,210,73,124,177,88,236,173,28,148,116,196,220,
    245,166,250,178,136,111,64,156,31,81,243,90,225,103,182,162,
    62,190,241,225,72,31,74,49,0,185,238,224,50,195,217,41,
    0,48,125,184,83,40,181,83,81,202,73,240,232,145,242,237,
    230,244,33,23,204,151,9,63,138,18,255,64,6,250,26,237,
    37,204,152,230,73,50,245,112,124,243,74,138,126,56,205,57,
    172,93,248,30,164,52,107,227,194,104,38,211,208,139,194,111,
    228,75,248,177,248,228,16,54,93,241,81,145,69,47,18,52,
    10,60,210,27,23,13,151,210,53,163,43,149,163,48,35,115,
    172,86,39,228,25,140,124,206,6,186,2,217,213,201,139,6,
    163,46,212,245,221,195,99,210,148,111,73,232,6,174,177,218,
    16,117,131,174,122,77,209,20,109,97,137,86,187,97,54,234,
    141,154,137,128,165,145,117,209,52,27,205,150,168,254,111,35,
    132,155,198,118,171,33,254,11,69,242,248,89,
};

EmbeddedPython embedded_m5_internal_param_BasicIntLink(
    "m5/internal/param_BasicIntLink.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_BasicIntLink.py",
    "m5.internal.param_BasicIntLink",
    data_m5_internal_param_BasicIntLink,
    2172,
    6712);

} // anonymous namespace
