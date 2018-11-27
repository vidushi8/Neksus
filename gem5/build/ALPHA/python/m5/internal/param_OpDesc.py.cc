#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_OpDesc[] = {
    120,156,189,88,91,115,219,198,21,62,11,128,148,72,81,22,
    117,183,44,57,98,219,113,195,122,90,177,77,227,186,51,81,
    220,184,73,122,201,100,100,23,76,199,14,147,41,10,17,43,
    17,20,9,112,176,43,203,204,72,47,149,167,237,67,95,251,
    19,250,208,127,211,127,212,158,115,22,0,33,202,234,100,166,
    21,101,98,189,88,236,158,61,151,239,92,118,187,144,254,149,
    240,249,168,1,160,18,1,16,224,79,192,0,96,40,160,35,
    64,72,1,193,26,156,148,32,121,31,130,18,188,1,232,88,
    32,45,184,196,142,13,95,89,16,213,120,77,25,6,54,143,
    8,24,87,65,58,208,41,193,139,104,25,28,89,134,147,42,
    36,127,4,33,68,36,224,101,48,7,193,60,188,65,234,216,
    169,48,193,121,160,193,42,15,86,32,88,224,193,42,4,53,
    238,44,192,184,14,178,6,157,69,154,214,185,131,100,31,34,
    217,37,38,251,47,34,27,224,151,117,8,238,208,116,228,235,
    75,154,233,208,76,222,111,137,169,212,51,46,151,161,179,146,
    245,87,11,253,181,66,127,157,251,184,235,10,244,55,160,191,
    9,253,187,112,132,138,88,206,119,216,2,105,67,255,30,116,
    238,129,196,223,22,92,162,174,130,149,194,138,109,94,177,154,
    175,216,225,21,247,161,115,31,36,254,118,204,138,50,180,155,
    27,168,255,240,223,248,215,68,253,131,174,97,243,74,38,42,
    140,35,47,140,142,226,208,162,239,101,106,200,90,93,106,230,
    82,179,125,76,102,251,39,176,205,2,43,53,219,5,32,97,
    65,178,12,44,184,224,206,133,5,227,38,156,11,232,59,16,
    216,112,142,219,148,136,129,99,1,151,22,124,109,211,132,11,
    108,29,84,238,59,224,104,99,179,62,43,215,80,154,131,139,
    18,156,151,160,253,242,220,162,129,147,10,36,255,128,111,118,
    152,232,60,19,181,224,28,91,7,46,29,184,40,195,11,156,
    132,67,253,10,137,47,94,158,163,164,56,210,110,58,200,237,
    65,65,92,18,37,8,147,200,31,74,189,136,125,111,228,39,
    254,208,123,54,250,68,170,110,179,154,77,137,213,222,200,215,
    61,151,215,216,164,140,225,72,51,173,56,146,122,1,59,71,
    97,20,120,195,56,56,29,72,61,79,132,188,163,112,32,61,
    143,63,254,118,56,138,19,253,105,146,196,137,75,250,228,193,
    65,236,231,43,72,155,221,65,172,100,147,118,227,109,92,34,
    175,105,246,209,136,41,18,3,204,39,45,14,144,189,36,28,
    105,52,147,161,72,179,137,90,147,12,196,141,114,177,105,245,
    226,161,108,189,10,131,83,213,11,91,191,150,195,79,146,56,
    12,188,195,56,62,81,225,176,117,44,135,143,90,135,167,225,
    32,104,61,253,252,249,111,158,182,70,99,221,139,163,22,142,
    134,145,150,168,151,65,171,168,145,61,252,190,66,180,207,194,
    99,47,100,169,188,158,28,140,100,66,202,83,247,104,95,81,
    23,53,81,22,182,104,138,69,236,149,240,177,197,142,181,32,
    14,66,146,171,75,178,18,158,156,34,130,200,172,2,78,44,
    72,118,8,31,125,252,9,50,40,162,164,77,223,44,254,246,
    59,82,136,25,237,219,100,117,51,120,206,152,66,112,225,204,
    125,50,115,4,12,140,18,244,203,96,0,131,56,51,8,74,
    198,212,226,116,34,99,33,113,7,212,223,1,21,140,80,57,
    135,20,70,151,54,136,168,14,186,74,158,140,163,27,184,225,
    159,24,137,237,38,177,127,192,160,208,189,80,197,103,17,171,
    158,250,236,59,109,212,204,243,241,179,195,190,236,106,181,139,
    3,95,198,167,141,174,31,69,177,110,248,65,208,240,181,78,
    194,195,83,45,85,67,199,141,7,170,73,214,116,151,51,92,
    229,244,198,163,12,71,100,115,196,145,121,9,194,174,198,151,
    85,126,97,43,40,169,17,19,189,56,80,56,78,36,142,165,
    118,137,73,77,74,142,153,17,134,140,71,83,105,123,156,119,
    7,223,159,102,156,48,46,155,229,12,69,74,14,142,116,149,
    1,233,43,229,49,39,52,206,216,35,194,175,252,193,169,100,
    234,10,233,33,67,212,53,60,220,62,250,238,146,36,153,224,
    44,77,20,71,193,24,153,11,187,239,210,190,119,25,131,53,
    70,225,58,34,112,14,219,50,254,95,22,27,86,215,73,113,
    87,206,176,71,209,79,3,91,94,164,198,71,28,94,98,164,
    105,90,28,42,88,32,246,199,239,82,143,22,187,59,212,220,
    167,230,29,106,118,51,153,111,85,240,197,105,193,31,211,102,
    22,75,203,114,145,105,236,76,174,224,138,79,109,77,124,10,
    195,97,155,124,195,34,15,154,248,134,67,161,51,121,66,45,
    78,101,175,179,65,125,65,129,154,124,136,137,145,187,32,240,
    169,55,113,7,214,146,91,39,233,231,51,36,187,4,207,34,
    70,143,11,24,117,201,64,12,80,119,43,11,133,30,205,48,
    208,116,183,137,84,233,45,106,110,80,243,157,153,232,122,2,
    178,227,107,32,251,128,246,173,167,32,91,100,112,85,241,169,
    91,93,59,53,64,158,26,87,167,192,69,200,114,222,130,172,
    239,83,207,190,46,242,44,65,149,10,250,171,2,168,136,55,
    171,40,207,1,118,198,155,36,70,17,78,155,152,228,95,68,
    155,152,183,45,206,219,63,230,188,205,185,159,43,32,19,156,
    109,142,207,166,83,34,125,28,217,176,145,230,99,85,193,118,
    148,196,175,199,141,248,168,161,89,96,138,165,251,15,212,222,
    3,245,1,70,201,198,19,142,79,38,78,154,72,152,200,17,
    69,50,90,250,233,235,174,228,84,200,111,158,103,2,151,199,
    65,204,75,83,44,34,107,157,180,105,101,106,230,16,174,116,
    66,145,251,246,21,93,205,21,77,124,127,70,59,85,89,203,
    182,216,68,20,85,5,179,227,153,112,205,69,22,127,197,231,
    151,164,121,18,89,2,149,196,110,219,48,203,114,144,68,238,
    15,175,32,229,54,165,112,91,72,246,247,25,66,202,19,132,
    208,99,103,136,255,11,112,237,41,224,207,64,24,64,83,167,
    136,207,29,132,140,190,74,211,255,0,236,26,111,201,252,28,
    99,218,148,237,121,6,134,30,245,152,167,154,66,224,51,248,
    107,193,175,178,116,109,167,213,101,49,93,59,121,124,98,240,
    124,171,148,236,92,13,100,100,153,158,175,104,154,137,78,19,
    87,157,196,255,188,50,196,232,124,171,72,154,55,123,120,196,
    206,215,19,28,81,194,219,22,171,86,1,29,63,161,230,189,
    28,24,34,27,187,45,206,118,225,230,212,236,153,248,255,21,
    109,239,48,195,75,115,92,55,152,229,57,226,75,25,226,223,
    203,17,47,57,73,189,225,83,6,181,22,89,249,210,18,120,
    220,195,234,140,78,87,14,200,18,116,202,228,27,92,72,139,
    212,117,68,22,184,40,204,93,201,128,172,140,3,163,166,220,
    208,198,134,212,188,190,253,128,64,102,220,31,248,195,195,192,
    127,114,66,251,208,102,221,204,153,172,140,243,122,145,115,114,
    4,113,19,243,252,250,40,147,224,213,237,7,131,159,33,217,
    156,115,134,126,16,119,57,2,124,209,147,141,161,28,30,226,
    49,178,23,142,26,71,3,255,152,109,98,167,146,61,203,36,
    211,108,212,233,106,66,61,164,54,110,116,227,8,227,243,105,
    87,199,73,35,144,120,192,146,65,227,71,13,14,238,141,80,
    53,252,67,252,234,119,181,1,246,85,199,228,130,213,79,142,
    21,99,236,228,140,186,179,177,169,135,167,230,16,75,244,33,
    228,137,212,156,233,242,88,205,197,183,241,19,204,121,120,116,
    210,99,19,159,168,178,112,247,168,249,1,204,44,164,191,15,
    140,46,80,164,168,178,216,182,42,22,159,99,204,140,231,52,
    91,93,247,206,191,125,27,239,52,215,48,169,143,150,105,166,
    156,163,211,58,181,21,10,233,157,106,54,184,192,109,141,7,
    23,179,193,59,220,46,241,96,61,187,254,89,230,193,21,232,
    172,210,93,9,141,172,145,223,207,253,175,126,207,174,51,27,
    167,209,255,87,119,119,31,207,158,113,247,231,144,38,251,155,
    92,93,20,165,90,52,107,251,34,59,91,20,69,226,219,139,
    213,41,196,121,221,68,250,90,26,203,236,204,66,64,14,20,
    102,215,179,137,235,94,175,129,159,230,178,92,114,121,51,94,
    99,131,153,227,20,27,76,188,136,238,97,49,236,112,49,188,
    79,197,240,57,11,238,89,166,30,158,192,176,148,203,79,118,
    143,228,153,87,212,129,41,118,137,45,127,52,146,81,224,62,
    132,98,253,202,159,111,223,238,20,148,46,160,80,102,216,98,
    13,11,214,235,190,70,17,183,32,27,91,174,148,123,215,76,
    108,200,32,125,147,129,180,201,17,55,15,187,238,62,53,28,
    104,243,24,235,254,34,183,192,214,52,2,67,165,78,229,231,
    190,166,147,209,127,249,138,165,14,199,253,108,64,111,76,79,
    141,71,25,149,27,62,17,9,210,20,191,241,217,115,106,210,
    199,124,158,33,10,55,126,36,26,124,81,105,222,217,108,236,
    85,129,28,72,45,175,0,139,209,150,158,204,3,137,73,52,
    30,227,97,137,207,31,248,62,240,188,25,165,158,15,83,75,
    41,186,81,196,212,35,202,152,124,214,241,68,189,110,85,202,
    21,193,217,124,234,250,217,48,69,85,183,169,181,199,204,27,
    184,75,185,29,249,166,52,75,171,100,114,62,19,30,248,67,
    115,205,197,183,56,238,247,32,61,117,187,239,230,120,32,19,
    243,1,199,28,34,209,27,185,210,224,194,194,253,41,141,147,
    242,135,143,246,50,121,246,100,116,74,226,176,194,249,162,118,
    248,72,111,79,205,49,50,183,195,161,185,17,212,203,83,223,
    131,196,199,254,250,212,168,146,73,232,15,194,111,204,21,96,
    54,172,73,202,105,130,196,108,254,198,217,188,16,76,217,198,
    137,60,14,21,82,224,229,249,212,52,198,124,248,86,236,23,
    151,205,6,12,166,30,54,71,245,39,116,37,164,62,194,134,
    238,240,42,75,21,4,6,197,29,27,143,201,139,194,177,107,
    245,138,83,91,168,56,149,57,155,47,95,22,241,216,83,117,
    42,11,53,97,254,237,34,120,170,214,238,74,69,252,7,206,
    181,211,140,
};

EmbeddedPython embedded_m5_internal_param_OpDesc(
    "m5/internal/param_OpDesc.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_OpDesc.py",
    "m5.internal.param_OpDesc",
    data_m5_internal_param_OpDesc,
    2259,
    6757);

} // anonymous namespace
