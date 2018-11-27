#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_EtherDump[] = {
    120,156,197,88,91,115,219,198,21,62,11,128,148,72,137,22,
    101,89,146,45,171,21,58,25,79,217,76,35,38,105,221,244,
    226,241,52,173,147,76,59,83,37,5,211,177,205,180,69,32,
    96,73,130,194,133,3,172,44,51,35,189,84,158,182,111,253,
    17,157,62,244,127,244,127,181,231,156,5,32,136,182,51,153,
    105,194,72,196,206,98,177,123,246,92,190,115,217,245,161,248,
    107,224,243,75,27,32,31,10,128,0,127,2,34,128,88,0,
    190,11,41,32,216,130,147,6,100,63,134,160,1,47,0,134,
    6,72,3,46,177,99,194,103,6,36,235,188,166,9,145,201,
    35,2,230,109,144,22,12,27,240,56,217,4,75,54,225,164,
    13,217,231,32,132,72,4,60,9,86,32,88,133,23,72,29,
    59,45,38,184,10,65,155,59,45,8,214,184,211,134,121,23,
    228,26,12,145,248,10,12,59,72,234,77,36,117,131,73,253,
    135,72,5,248,229,22,4,29,154,142,188,60,165,153,22,205,
    228,61,110,48,149,141,146,179,46,12,55,203,254,205,90,127,
    139,251,27,32,55,97,122,11,166,219,48,221,129,17,10,220,
    173,168,238,130,52,97,122,27,134,183,65,226,111,23,46,81,
    39,193,102,109,197,29,94,113,179,90,177,199,43,238,194,240,
    46,72,252,237,233,21,77,24,244,182,81,207,225,127,241,175,
    135,122,6,181,142,205,51,153,229,97,154,184,97,50,74,67,
    131,190,55,169,33,171,248,212,172,20,230,249,53,153,231,223,
    192,182,9,140,194,60,23,128,132,5,201,18,25,112,193,157,
    11,3,230,61,56,23,48,181,32,48,225,28,183,105,16,3,
    99,1,151,6,252,209,164,9,23,216,90,168,208,239,130,165,
    180,109,166,172,80,77,105,5,46,26,112,222,128,193,147,115,
    131,6,78,90,144,253,11,190,216,103,162,171,76,212,128,115,
    108,45,184,180,224,162,9,143,113,18,14,77,91,36,190,120,
    114,142,146,226,200,160,103,33,183,71,53,113,73,148,32,204,
    18,47,150,170,139,125,119,230,101,94,236,126,160,38,50,123,
    116,26,207,122,237,114,86,154,31,206,60,53,113,120,153,73,
    250,136,103,138,201,165,137,84,107,216,25,133,73,224,198,105,
    112,26,73,181,74,180,220,81,24,73,215,229,143,191,137,103,
    105,166,62,200,178,52,115,72,165,60,24,165,94,181,130,20,
    234,71,105,46,123,180,27,111,227,16,121,69,179,71,51,166,
    72,12,48,171,180,56,144,185,159,133,51,133,150,210,20,105,
    54,81,235,145,141,184,201,159,98,211,15,60,229,189,211,159,
    164,177,236,63,11,131,211,124,18,246,63,146,241,163,44,13,
    3,247,56,77,79,242,48,238,143,101,124,191,127,124,26,70,
    65,255,125,231,119,253,217,92,77,210,164,143,99,97,162,36,
    170,39,234,47,40,230,16,167,220,164,45,206,194,177,27,178,
    112,238,68,70,51,153,17,111,249,30,109,47,186,98,93,52,
    133,41,122,162,131,189,6,62,166,216,55,214,196,81,72,226,
    249,36,50,33,203,44,177,244,79,96,171,161,209,79,12,200,
    246,9,41,83,252,9,50,45,226,101,64,223,12,254,246,123,
    210,139,30,157,154,100,127,61,120,206,232,66,152,225,204,7,
    100,240,4,24,34,13,152,54,65,67,7,17,167,177,148,205,
    169,197,233,68,198,64,226,22,228,255,184,78,33,233,2,234,
    29,61,24,135,118,112,171,191,48,26,7,61,98,252,136,81,
    161,38,97,158,158,37,172,123,234,179,255,12,80,39,159,204,
    63,62,158,74,95,229,7,56,240,52,61,181,125,47,73,82,
    101,123,65,96,123,74,101,225,241,169,146,185,173,82,251,94,
    222,107,145,177,55,75,96,85,244,230,179,18,72,100,116,4,
    146,126,9,66,95,225,203,22,191,176,254,115,169,16,20,147,
    52,200,113,156,72,140,165,114,136,73,117,3,155,247,203,237,
    24,125,189,102,137,149,92,70,35,213,102,216,121,121,238,242,
    118,52,206,8,163,213,207,188,232,84,42,154,159,43,79,225,
    174,212,213,27,45,13,99,183,73,202,82,72,82,156,155,164,
    73,48,71,30,67,255,13,218,254,54,35,109,29,8,107,219,
    136,179,21,108,155,208,65,220,117,13,159,196,177,10,148,49,
    194,118,72,120,96,171,139,34,102,32,218,46,49,178,244,12,
    14,13,44,23,59,159,77,61,90,236,16,152,157,187,212,236,
    83,243,157,82,244,101,200,223,89,148,255,109,218,211,96,161,
    125,179,16,175,114,160,163,107,14,116,231,202,129,48,10,14,
    200,17,12,114,151,43,71,48,73,1,217,195,2,245,228,98,
    104,120,252,92,195,58,171,197,161,216,200,200,97,152,58,132,
    189,58,0,199,53,0,58,100,17,70,159,115,231,117,42,60,
    248,118,84,56,214,42,252,17,237,185,94,224,166,195,120,105,
    11,159,140,110,20,10,101,101,62,194,206,124,151,148,89,87,
    227,46,230,180,199,73,135,147,19,39,56,78,237,58,106,104,
    237,234,142,69,8,27,153,176,83,36,157,156,156,124,150,165,
    207,231,118,58,178,21,148,60,60,184,151,31,222,203,127,129,
    97,192,126,200,129,69,7,2,237,234,153,156,101,232,210,45,
    126,209,110,234,178,203,186,69,218,64,117,83,2,103,43,177,
    146,57,42,229,42,163,96,180,52,13,183,43,13,19,195,63,
    163,13,219,172,94,19,118,241,105,11,230,202,77,57,34,114,
    9,193,95,241,249,21,41,154,100,149,64,133,157,51,208,60,
    179,56,36,152,243,253,107,72,89,130,48,206,155,196,86,233,
    100,77,168,112,65,143,73,236,18,238,255,6,92,96,9,248,
    43,16,6,208,212,133,167,176,79,210,67,166,220,162,233,127,
    6,14,54,175,72,106,134,246,56,163,8,71,232,144,249,123,
    60,85,231,184,223,194,223,107,145,234,210,4,65,249,200,44,
    74,168,122,62,178,42,31,101,240,124,165,156,99,93,119,102,
    50,208,196,203,105,154,118,91,179,114,219,171,160,87,213,62,
    24,139,150,129,171,85,189,149,75,92,125,116,133,42,10,246,
    119,197,150,81,195,202,15,169,121,171,130,137,40,199,190,97,
    6,15,22,163,115,45,59,185,58,34,126,72,92,88,204,247,
    70,147,61,185,162,80,121,66,163,244,132,119,43,79,144,28,
    163,95,112,109,77,173,65,102,191,52,4,30,102,176,30,161,
    115,132,5,178,1,195,38,249,12,215,142,162,112,41,81,198,
    47,138,123,215,18,0,171,229,72,43,172,178,188,54,42,53,
    207,151,22,47,200,174,15,34,47,62,14,188,135,159,210,118,
    180,167,95,58,153,81,10,208,173,11,64,14,34,94,39,3,
    191,190,93,10,242,108,105,177,226,29,164,94,9,192,158,17,
    164,62,7,136,79,39,210,142,101,124,140,71,169,73,56,179,
    71,145,55,102,11,153,133,128,31,151,2,42,54,241,98,194,
    205,41,10,29,165,182,159,38,24,204,79,125,149,102,118,32,
    241,132,33,3,251,45,155,51,129,29,230,182,119,140,95,61,
    95,105,192,95,247,91,174,229,188,108,156,115,217,118,114,70,
    221,165,90,216,197,3,100,136,149,234,31,74,5,233,147,77,
    21,214,185,56,213,222,131,121,17,79,14,106,174,99,216,79,
    168,249,1,53,247,96,217,209,191,143,212,7,180,13,41,173,
    137,97,166,37,212,70,221,105,63,161,53,249,203,174,123,246,
    85,92,87,223,64,20,14,220,164,153,114,133,14,176,212,182,
    40,1,12,219,229,224,26,183,235,60,216,41,47,57,110,240,
    224,6,12,187,116,83,64,35,155,228,255,43,255,175,255,179,
    239,44,213,107,62,251,90,221,222,121,247,91,227,223,225,106,
    242,203,92,94,212,133,235,104,151,159,138,178,224,174,75,198,
    199,248,157,151,209,230,250,153,244,148,212,166,218,91,162,168,
    28,58,244,230,127,170,12,86,202,83,157,58,222,171,100,186,
    228,106,104,126,171,86,13,179,253,196,99,44,93,176,98,62,
    103,177,93,67,23,205,87,144,180,42,233,73,145,137,60,115,
    23,52,160,139,98,226,198,155,205,100,18,92,21,188,252,101,
    105,166,167,208,244,57,92,85,34,88,221,222,194,231,101,231,
    35,137,106,2,178,229,26,149,187,45,211,134,12,87,89,90,
    175,71,151,54,87,49,216,33,219,233,168,91,5,92,231,231,
    149,53,246,94,129,197,216,123,30,201,132,206,82,95,246,25,
    235,33,125,93,192,175,124,140,95,156,201,183,99,68,230,181,
    31,137,8,41,146,94,88,245,236,28,129,140,164,146,139,8,
    209,215,119,58,157,4,18,211,98,58,199,179,18,159,59,240,
    61,114,221,229,230,145,159,34,245,33,20,209,140,242,72,19,
    51,201,54,254,183,172,150,224,36,189,112,179,170,57,163,90,
    91,87,216,243,220,225,240,178,81,25,131,111,0,203,68,201,
    62,71,213,228,145,23,235,139,29,190,176,112,190,71,205,27,
    165,61,217,4,250,216,197,231,26,125,146,68,255,226,10,130,
    11,6,231,144,198,233,104,30,223,63,44,37,58,212,18,13,
    194,88,223,98,241,37,100,124,95,109,46,76,11,50,15,251,
    219,11,163,185,204,66,47,10,191,208,183,87,229,48,167,209,
    69,186,196,79,245,198,201,247,122,252,99,123,102,114,28,230,
    72,132,41,84,179,139,192,64,138,86,251,175,64,80,125,229,
    82,109,175,203,91,125,62,127,72,2,230,15,176,161,251,169,
    214,70,75,52,13,186,5,53,69,91,116,132,37,214,59,45,
    179,213,108,53,76,196,7,141,108,137,182,217,106,175,11,250,
    63,64,164,180,141,131,245,150,248,31,101,249,159,70,
};

EmbeddedPython embedded_m5_internal_param_EtherDump(
    "m5/internal/param_EtherDump.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/m5/internal/param_EtherDump.py",
    "m5.internal.param_EtherDump",
    data_m5_internal_param_EtherDump,
    2126,
    6421);

} // anonymous namespace
