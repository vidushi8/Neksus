#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GarnetExtLink[] = {
    120,156,197,88,109,111,219,214,21,62,151,164,100,75,182,99,
    249,61,137,157,152,73,235,85,11,54,107,235,154,101,64,189,
    108,105,154,182,43,10,55,163,58,36,113,139,113,52,121,109,
    81,166,72,129,164,237,168,147,49,96,14,182,97,223,247,19,
    246,97,255,102,216,31,218,206,57,151,164,104,91,6,2,108,
    83,29,233,230,234,242,240,220,243,242,156,151,123,93,200,254,
    42,248,253,165,9,144,252,75,0,120,248,17,16,0,244,4,
    236,9,16,82,128,183,12,71,21,136,63,0,175,2,111,0,
    246,52,144,26,156,227,68,135,175,53,8,103,249,157,42,4,
    58,175,8,24,212,65,26,176,87,129,23,225,2,24,178,10,
    71,117,136,127,7,66,136,80,192,75,111,10,188,105,120,131,
    220,113,82,99,134,211,64,139,117,94,172,129,55,195,139,117,
    240,102,121,50,3,131,6,200,89,216,155,35,178,189,27,200,
    246,1,178,157,103,182,255,36,182,30,62,89,1,239,6,145,
    163,92,175,136,210,32,74,222,111,158,185,52,114,41,23,96,
    111,49,159,47,149,230,203,165,249,74,105,190,90,154,175,149,
    230,55,75,243,91,165,249,237,210,124,189,52,223,40,205,239,
    240,28,181,90,132,238,93,232,110,66,215,132,3,52,244,66,
    161,193,61,144,58,116,239,195,222,125,144,248,185,7,231,232,
    11,111,177,244,198,59,252,198,82,241,198,187,252,198,22,236,
    109,129,196,207,187,234,141,42,180,155,171,232,95,255,223,248,
    215,68,255,66,58,139,195,137,140,19,63,10,109,63,60,136,
    124,141,158,87,105,32,52,184,52,76,101,176,120,74,176,248,
    7,48,38,60,45,131,197,25,32,99,65,186,4,26,156,241,
    228,76,131,65,19,134,2,186,6,120,58,12,113,155,10,9,
    112,40,224,92,131,111,116,34,56,195,209,64,231,221,5,35,
    85,152,232,178,243,20,167,41,56,171,192,176,2,237,151,67,
    141,22,142,106,16,255,29,190,221,96,166,211,204,84,131,33,
    142,6,156,27,112,86,133,23,72,132,75,221,26,169,47,94,
    14,81,83,92,105,55,13,148,118,183,164,46,169,226,249,113,
    232,244,100,186,140,115,187,239,196,78,207,254,212,137,67,153,
    62,123,157,126,225,135,71,205,122,78,25,37,219,125,39,237,
    88,252,170,78,54,233,245,83,102,25,33,249,12,78,14,252,
    208,179,123,145,119,28,200,116,154,248,217,7,126,32,109,155,
    31,254,170,215,143,226,244,89,28,71,177,69,102,229,197,32,
    114,138,55,200,168,110,16,37,178,73,187,241,54,22,177,79,
    137,250,160,207,28,73,0,22,151,94,246,100,226,198,126,63,
    69,111,41,142,68,77,220,154,228,39,30,146,87,56,180,58,
    81,79,182,78,124,239,56,233,248,173,79,101,239,227,56,242,
    61,123,63,138,142,18,191,215,58,148,189,135,173,253,99,63,
    240,90,79,190,120,254,217,147,86,127,144,118,162,176,133,171,
    126,152,74,52,79,208,26,99,152,109,36,91,164,45,78,253,
    67,219,103,229,236,142,12,250,50,158,163,213,219,180,189,104,
    136,89,81,21,186,104,138,57,156,85,240,171,139,13,109,70,
    236,250,164,158,75,42,19,186,140,50,158,200,201,2,142,52,
    136,55,8,45,93,252,8,114,47,98,166,77,207,52,126,246,
    107,178,139,90,237,234,132,1,181,56,100,132,33,212,144,114,
    135,156,30,2,195,164,2,221,42,40,248,32,234,20,158,226,
    1,141,72,78,108,52,100,110,64,242,55,64,59,35,112,134,
    144,129,234,92,7,17,54,32,173,83,222,192,213,85,220,240,
    143,140,203,118,147,196,223,101,108,164,29,63,137,78,67,246,
    0,205,57,146,218,104,153,231,131,47,247,187,210,77,147,77,
    92,120,21,29,155,174,19,134,81,106,58,158,103,58,105,26,
    251,251,199,169,76,204,52,50,183,146,38,57,213,90,200,225,
    85,240,27,244,115,56,145,235,17,78,234,135,231,187,41,254,
    88,226,31,236,133,68,166,8,141,78,228,37,184,78,44,14,
    101,106,145,144,41,25,57,98,65,24,57,54,145,210,246,72,
    119,3,127,63,201,37,97,120,54,171,57,152,18,25,28,164,
    117,198,165,147,36,54,75,66,235,12,65,98,124,226,4,199,
    146,185,39,200,15,5,162,169,146,97,98,32,188,73,10,229,
    250,179,82,97,20,122,3,148,209,119,223,163,237,111,50,20,
    103,25,140,43,8,196,41,28,171,248,127,85,172,106,174,145,
    193,175,154,67,144,82,98,10,12,0,145,97,0,225,120,142,
    233,167,169,113,254,96,189,56,58,239,211,140,94,182,54,104,
    184,67,195,93,26,54,115,213,39,161,255,220,101,253,31,209,
    158,26,43,205,234,145,163,244,92,61,239,66,132,221,26,69,
    24,166,202,54,69,138,70,241,52,138,20,131,210,106,252,152,
    70,36,229,24,212,33,249,138,146,56,69,20,51,163,224,193,
    48,160,217,40,56,216,88,86,131,140,48,157,227,218,34,176,
    150,17,123,88,66,172,69,126,98,184,90,183,242,252,104,19,
    133,2,170,181,78,172,42,99,172,109,210,112,111,146,38,31,
    65,238,240,10,228,62,164,237,27,25,228,230,24,106,117,252,
    54,52,87,207,252,80,84,207,165,75,80,35,156,25,99,112,
    246,61,154,233,87,53,255,14,32,150,233,251,73,9,98,36,
    162,86,86,107,23,39,131,53,210,166,12,174,53,108,7,94,
    132,107,88,225,53,174,240,63,226,10,207,93,2,247,98,42,
    113,235,156,187,213,164,66,102,57,208,97,53,171,220,73,13,
    199,126,28,189,30,152,209,129,153,178,222,148,103,119,182,146,
    237,173,228,67,204,160,230,99,206,93,42,135,170,44,25,203,
    62,101,57,122,245,217,107,87,114,181,228,95,182,173,146,154,
    205,9,206,206,170,48,226,108,133,140,170,229,214,230,244,158,
    164,49,101,245,137,217,187,94,216,155,196,255,156,54,172,179,
    177,117,177,134,152,170,11,150,202,86,25,157,187,50,126,138,
    223,143,200,1,164,185,4,234,209,173,182,146,153,213,33,197,
    172,31,92,192,205,4,148,177,90,200,253,55,57,94,170,35,
    188,208,87,207,195,224,207,192,61,171,128,63,1,33,2,29,
    159,133,65,17,53,4,129,37,34,255,45,112,188,140,233,17,
    56,255,180,169,47,96,10,76,75,201,35,38,85,45,195,231,
    240,151,82,176,229,133,93,207,186,210,114,97,55,138,220,197,
    80,122,171,226,109,92,76,114,228,160,142,147,16,153,202,92,
    163,248,29,149,136,162,149,196,204,61,9,92,77,171,173,108,
    146,234,155,17,170,168,52,174,139,37,173,132,149,31,211,240,
    126,1,19,145,175,253,159,5,220,132,235,107,185,173,42,197,
    215,36,133,193,114,207,79,113,102,186,192,165,136,134,74,30,
    13,239,23,209,32,185,170,189,225,35,11,141,26,185,254,92,
    19,120,54,197,230,142,142,130,6,200,10,236,85,41,110,184,
    29,23,89,88,137,60,183,209,126,23,74,38,155,102,87,25,
    173,240,190,114,44,13,175,39,150,51,200,183,59,129,211,219,
    247,156,199,9,109,71,123,186,121,160,105,185,2,141,178,2,
    20,36,226,58,29,248,231,195,92,145,147,137,229,139,159,102,
    194,179,2,28,29,94,228,114,146,248,170,35,205,158,236,237,
    227,9,181,227,247,205,131,192,57,100,15,233,153,130,95,230,
    10,166,236,226,203,205,72,242,128,198,200,116,163,16,19,250,
    177,155,70,177,233,73,60,180,73,207,252,161,201,213,192,244,
    19,211,217,199,167,142,155,42,208,95,140,93,238,126,157,248,
    48,225,70,247,232,148,166,19,245,176,141,231,114,31,219,254,
    99,40,10,176,58,46,22,201,157,27,122,21,67,88,43,241,
    56,150,14,84,38,163,198,196,218,166,225,251,48,233,26,240,
    1,114,143,105,27,50,91,85,172,107,53,141,219,192,11,132,
    207,233,221,228,106,0,239,191,77,0,171,107,165,44,140,171,
    68,41,167,232,118,128,198,26,149,2,186,53,170,100,183,70,
    180,168,110,141,170,188,114,131,2,126,234,191,13,120,14,150,
    137,134,201,240,127,26,231,214,163,239,76,126,235,103,144,53,
    2,215,197,184,40,43,55,167,98,188,43,242,51,73,89,51,
    190,10,185,61,30,92,182,27,75,39,149,202,93,27,19,84,
    151,243,133,218,252,15,163,208,189,218,59,63,41,52,59,231,
    70,104,176,204,94,84,135,50,246,162,120,17,222,198,38,218,
    224,38,122,135,154,232,33,155,193,214,84,31,61,130,104,165,
    176,198,26,14,161,60,181,199,88,68,245,202,36,157,211,239,
    203,208,179,30,64,185,253,229,199,19,195,4,165,168,115,40,
    245,37,186,88,198,126,247,106,84,82,26,46,105,202,238,172,
    20,113,56,73,199,50,142,255,154,227,184,57,15,229,92,108,
    237,208,192,217,183,72,188,214,47,10,183,108,93,3,82,92,
    56,141,226,35,59,192,165,132,142,92,111,73,137,61,19,55,
    68,23,86,217,168,28,15,158,12,100,42,199,129,32,37,17,
    179,35,185,39,177,252,69,3,60,23,241,25,3,127,7,182,
    61,217,106,241,115,228,254,123,218,134,74,25,86,11,81,197,
    122,177,162,213,170,53,193,165,248,210,181,180,146,139,14,201,
    170,151,30,36,22,231,148,249,194,208,124,117,154,23,67,242,
    9,159,0,119,157,158,186,240,226,139,28,235,29,200,142,218,
    214,123,133,195,232,34,130,15,48,234,200,136,49,196,109,2,
    119,5,214,79,104,157,154,249,222,195,237,92,165,237,93,101,
    123,82,197,62,145,212,99,240,253,109,239,97,122,231,18,165,
    82,190,68,207,221,239,85,138,167,65,228,30,73,79,221,35,
    94,195,133,105,62,142,122,14,174,175,143,165,104,251,189,140,
    195,194,165,231,94,76,111,173,92,90,77,100,236,59,129,255,
    173,188,162,161,226,247,145,147,248,110,230,179,212,28,75,98,
    29,239,15,158,226,105,59,142,130,0,45,191,113,45,81,123,
    144,164,178,119,141,106,188,145,21,225,73,43,190,70,53,166,
    96,57,200,207,249,67,190,156,30,35,43,221,24,148,23,184,
    55,185,90,47,56,24,98,121,232,39,180,241,226,165,151,178,
    220,73,64,101,229,199,197,102,153,193,68,227,71,29,5,212,
    125,198,99,186,69,75,158,227,64,183,159,181,249,26,198,18,
    165,85,93,212,49,177,26,250,108,163,102,204,206,212,140,218,
    148,206,23,85,115,120,12,172,27,181,153,89,49,254,223,38,
    198,96,93,219,108,212,196,127,0,42,252,115,153,
};

EmbeddedPython embedded_m5_internal_param_GarnetExtLink(
    "m5/internal/param_GarnetExtLink.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_GarnetExtLink.py",
    "m5.internal.param_GarnetExtLink",
    data_m5_internal_param_GarnetExtLink,
    2333,
    7204);

} // anonymous namespace
