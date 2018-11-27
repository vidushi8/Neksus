#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_PciConfigAll[] = {
    120,156,197,88,109,115,219,198,17,222,3,64,74,164,36,235,
    221,175,178,69,39,113,204,122,90,169,77,227,186,51,113,221,
    42,118,218,38,211,40,46,152,214,14,147,41,10,1,71,10,
    20,8,112,128,147,108,102,164,118,38,242,180,249,144,153,126,
    234,79,232,135,254,155,254,154,126,77,118,247,0,16,18,105,
    55,51,109,88,153,60,31,239,246,246,110,119,159,125,185,243,
    32,251,171,224,247,23,13,128,244,223,2,192,199,143,128,16,
    160,47,160,45,64,72,1,254,26,28,84,32,121,27,252,10,
    188,0,104,27,32,13,56,197,142,9,159,26,16,205,243,154,
    42,132,38,143,8,24,214,65,90,208,174,192,147,104,25,44,
    89,133,131,58,36,127,4,33,68,36,224,169,63,3,254,44,
    188,64,238,216,169,49,195,89,160,193,58,15,214,192,159,227,
    193,58,248,243,220,153,131,225,18,200,121,104,47,16,89,251,
    2,178,189,131,108,23,153,237,191,136,173,143,51,235,224,95,
    32,114,60,215,39,68,105,17,37,239,183,200,92,150,242,83,
    46,67,123,37,239,175,150,250,107,165,254,122,169,127,177,212,
    191,84,234,95,46,245,175,148,250,87,75,253,107,165,254,70,
    169,127,189,212,191,81,234,111,150,250,13,238,163,228,43,208,
    187,9,189,215,160,247,58,116,208,24,203,133,148,111,128,52,
    161,119,11,218,183,64,226,231,13,56,69,123,249,43,165,21,
    111,242,138,213,98,197,109,94,209,132,118,19,36,126,110,235,
    21,85,104,53,47,34,6,130,175,241,175,137,24,0,53,143,
    205,145,76,210,32,142,156,32,234,196,129,65,243,85,106,8,
    49,30,53,51,25,116,30,18,116,254,9,140,27,223,200,160,
    115,2,200,88,144,44,161,1,39,220,57,49,96,216,132,99,
    1,61,11,124,19,142,113,155,10,29,160,43,224,212,128,207,
    76,34,56,193,214,66,3,223,0,75,105,220,244,216,192,154,
    211,12,156,84,224,184,2,173,167,199,6,13,28,212,32,249,
    7,124,190,193,76,103,153,169,1,199,216,90,112,106,193,73,
    21,158,32,17,14,245,106,36,190,120,122,140,146,226,72,171,
    105,225,105,119,75,226,146,40,126,144,68,110,95,170,85,236,
    59,3,55,113,251,206,99,47,120,24,71,157,160,187,19,134,
    205,122,78,24,167,91,3,87,237,219,188,210,36,149,244,7,
    138,57,198,145,84,115,216,233,4,145,239,244,99,255,48,148,
    106,150,216,57,157,32,148,142,195,147,239,247,7,113,162,222,
    75,146,56,177,73,171,60,24,198,110,177,130,116,234,133,113,
    42,155,180,27,111,99,19,123,69,212,157,1,115,164,3,240,
    105,105,177,47,83,47,9,6,10,141,165,57,18,53,113,107,
    146,153,184,73,159,98,179,189,31,247,229,246,81,224,31,166,
    251,193,246,175,100,255,81,18,7,190,179,23,199,7,105,208,
    223,238,202,254,221,237,189,195,32,244,183,119,126,243,248,215,
    59,219,131,161,218,143,163,109,28,13,34,37,81,59,225,246,
    184,94,182,144,106,133,118,120,22,116,157,128,101,115,246,101,
    56,144,201,2,141,94,165,221,197,146,152,23,85,97,138,166,
    88,192,94,5,191,166,216,48,230,196,110,64,210,121,36,49,
    97,203,42,163,137,76,44,224,192,128,100,131,176,210,195,143,
    32,227,34,98,90,52,103,240,220,111,73,45,122,180,103,18,
    2,244,224,49,227,11,129,134,148,247,201,228,17,48,72,42,
    208,171,130,6,15,98,78,163,41,25,82,139,228,196,198,64,
    230,22,164,127,7,84,51,194,230,24,50,72,157,154,32,162,
    37,80,117,138,44,56,122,17,55,252,130,81,217,106,210,241,
    119,25,26,106,63,72,227,103,17,27,128,250,236,71,45,212,
    204,227,225,71,123,61,233,169,116,19,7,62,137,15,27,158,
    27,69,177,106,184,190,223,112,149,74,130,189,67,37,211,134,
    138,27,183,210,38,217,212,94,206,209,85,240,27,14,114,52,
    145,229,17,77,250,135,31,120,10,127,48,108,29,182,66,42,
    21,34,99,63,246,83,28,39,22,93,169,108,58,164,34,37,
    199,124,16,6,142,67,164,180,61,210,93,192,223,59,249,73,
    24,157,205,106,142,165,84,134,29,85,103,88,186,105,234,240,
    73,104,156,17,72,140,143,220,240,80,50,247,20,249,225,129,
    168,171,207,48,45,12,94,38,121,114,241,89,166,40,142,252,
    33,30,49,240,110,211,238,151,25,137,243,140,197,117,196,225,
    12,182,85,252,191,42,46,26,158,149,161,175,154,35,144,226,
    161,2,182,191,200,32,128,104,60,197,216,211,52,56,120,176,
    88,236,155,175,81,143,22,219,27,212,92,167,230,6,53,155,
    185,228,83,16,127,225,188,248,247,104,75,131,101,102,233,200,
    76,102,46,157,127,198,191,174,140,252,11,195,100,139,252,196,
    32,111,26,249,137,69,33,53,121,64,45,146,178,7,154,144,
    126,76,1,156,252,137,153,145,235,160,19,80,111,228,26,172,
    43,123,137,116,48,155,163,218,38,168,150,241,218,45,225,213,
    38,51,49,88,237,43,121,112,116,136,66,195,212,190,70,172,
    42,19,148,221,160,230,230,20,53,62,2,92,119,12,112,239,
    208,238,75,25,224,22,24,104,117,252,46,25,158,153,153,161,
    72,156,171,231,128,70,40,179,38,160,236,77,234,153,227,130,
    79,31,96,153,184,191,44,1,140,78,104,148,165,218,197,206,
    240,18,9,83,134,214,37,44,4,158,68,151,48,183,27,156,
    219,127,200,185,157,235,3,174,212,116,208,54,57,110,235,78,
    133,180,210,49,225,98,150,179,211,26,182,131,36,126,62,108,
    196,157,134,98,177,41,198,222,191,149,110,221,74,223,193,232,
    217,120,192,113,75,199,79,29,33,19,57,160,8,71,75,223,
    123,238,73,78,148,252,203,113,116,64,115,56,184,57,89,2,
    70,148,173,147,78,141,92,217,28,218,83,149,80,68,159,150,
    186,235,133,186,233,244,31,208,126,117,214,181,41,46,33,162,
    234,130,15,229,232,96,206,229,24,207,226,247,93,210,63,9,
    46,129,10,120,187,165,143,204,210,144,92,246,247,207,160,230,
    187,151,197,222,70,230,191,203,209,82,29,161,133,190,102,238,
    3,127,5,174,85,5,252,5,8,15,104,246,204,7,10,151,
    33,0,172,18,249,31,128,157,101,66,117,192,177,167,69,21,
    1,83,96,72,74,239,49,169,46,22,62,128,47,75,158,150,
    167,116,51,171,70,203,41,221,42,226,22,3,233,91,165,109,
    235,108,128,35,251,236,187,41,145,233,168,53,114,222,81,118,
    40,106,72,140,218,83,64,213,172,222,201,161,67,125,54,194,
    20,37,197,107,98,213,40,33,229,71,212,188,85,128,68,228,
    99,223,237,249,54,225,229,73,220,209,57,226,83,58,132,197,
    199,94,156,225,250,170,204,164,240,132,74,238,9,111,21,158,
    32,57,157,189,224,123,10,181,6,217,253,212,16,120,105,197,
    154,142,238,136,22,200,10,180,171,228,51,92,132,139,204,165,
    68,30,214,40,8,158,201,149,172,152,93,173,178,194,244,218,
    170,212,60,159,86,184,32,195,222,15,221,254,158,239,62,56,
    162,221,104,75,47,119,50,35,63,255,82,249,252,228,32,226,
    101,34,240,207,187,185,28,71,211,10,21,63,161,205,242,243,
    179,99,248,177,199,241,225,227,125,217,232,203,254,30,94,74,
    247,131,65,163,19,186,93,182,143,153,201,247,81,46,159,98,
    3,159,175,65,210,59,212,198,13,47,142,48,146,31,122,42,
    78,26,190,196,139,154,244,27,63,104,112,26,104,4,105,195,
    221,195,89,215,83,26,240,103,221,150,75,94,55,233,166,92,
    221,30,60,163,238,52,237,235,224,77,60,192,82,255,57,20,
    137,87,223,16,139,168,206,69,188,246,31,204,145,120,5,83,
    67,29,195,168,30,177,183,168,249,30,76,57,248,191,141,204,
    15,105,23,82,90,85,92,51,106,6,223,23,203,116,143,105,
    101,58,238,187,95,125,27,223,213,79,77,153,7,87,137,82,
    206,208,107,0,181,53,74,1,237,122,62,56,199,237,60,15,
    46,228,131,23,184,93,228,193,165,252,137,107,153,7,87,160,
    189,74,111,49,52,178,70,81,97,230,191,141,10,236,82,211,
    116,166,63,255,79,131,129,125,239,255,117,124,251,167,144,21,
    10,47,11,4,162,44,219,130,14,4,61,145,223,87,202,130,
    241,27,201,149,137,24,116,188,68,186,74,106,91,109,76,79,
    88,14,41,122,239,47,70,238,61,94,87,239,20,114,157,114,
    153,52,92,99,19,234,235,26,155,80,60,137,174,98,129,109,
    113,129,125,159,10,236,99,86,130,99,232,26,123,4,207,74,
    161,11,186,236,70,242,153,51,174,15,93,70,211,225,220,193,
    64,70,190,125,7,202,149,49,79,79,11,15,20,196,190,132,
    82,209,98,138,53,44,133,199,253,145,226,116,73,78,182,101,
    165,240,192,41,90,149,33,252,183,28,194,77,142,211,69,176,
    182,239,83,195,225,185,136,204,246,207,11,155,92,157,140,207,
    189,195,148,46,96,175,154,198,210,137,51,39,246,213,181,201,
    100,105,240,185,100,54,175,154,39,62,252,250,131,63,184,50,
    155,64,56,8,93,213,137,147,62,51,251,79,52,196,144,31,
    47,179,1,182,40,59,162,47,67,169,228,4,252,41,210,79,
    246,76,224,75,204,205,241,16,111,107,124,245,193,223,161,227,
    76,53,151,253,12,153,255,137,118,161,4,134,185,76,84,49,
    155,173,227,245,126,221,168,85,107,130,75,133,115,47,229,250,
    104,100,91,93,230,15,83,155,195,217,98,97,104,214,72,158,
    173,9,19,124,53,221,117,251,250,21,142,159,151,236,215,33,
    123,2,176,111,23,128,33,197,241,221,74,223,101,209,129,185,
    140,225,170,197,254,113,142,161,254,221,173,92,170,173,76,170,
    76,253,252,158,220,191,171,174,79,164,122,63,82,9,10,143,
    26,15,249,169,99,156,162,53,76,149,236,51,132,202,147,50,
    58,236,59,31,202,126,156,12,63,140,125,169,110,158,155,223,
    201,74,44,77,226,28,73,170,197,84,99,226,22,103,105,199,
    182,210,68,56,169,31,87,25,128,227,243,15,195,216,59,144,
    126,70,51,89,90,166,121,20,247,93,28,159,188,75,43,200,
    119,89,62,55,239,39,180,106,253,220,104,42,147,192,13,201,
    117,54,206,43,192,247,19,219,141,186,242,213,178,191,235,166,
    129,247,56,136,31,201,163,192,147,47,57,213,104,158,96,148,
    79,170,53,194,212,36,46,84,32,158,29,226,2,109,44,27,
    178,199,37,178,27,160,137,19,102,119,118,85,150,29,200,33,
    94,230,246,101,14,211,244,82,125,23,210,79,57,15,232,249,
    48,253,61,54,244,234,91,91,172,161,199,82,222,48,69,29,
    51,135,101,206,47,213,172,249,185,154,85,155,49,249,137,110,
    1,47,193,117,171,54,55,47,94,245,111,19,125,189,110,108,
    174,212,196,55,105,160,186,146,
};

EmbeddedPython embedded_m5_internal_param_PciConfigAll(
    "m5/internal/param_PciConfigAll.py",
    "/home/vidushi/GemDroid_booksim/gem5/build/ALPHA/python/m5/internal/param_PciConfigAll.py",
    "m5.internal.param_PciConfigAll",
    data_m5_internal_param_PciConfigAll,
    2424,
    7491);

} // anonymous namespace
