#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_trace[] = {
    120,156,189,87,109,111,27,69,16,158,189,59,59,177,19,55,
    111,234,27,13,212,8,85,152,10,226,86,20,33,68,85,81,
    40,20,144,8,244,44,212,54,32,142,203,221,197,62,199,190,
    179,110,215,41,70,201,23,82,1,31,144,248,17,136,15,252,
    15,254,87,153,103,214,231,184,21,72,8,53,36,185,213,220,
    236,222,236,204,51,207,204,110,34,154,254,84,248,121,175,73,
    164,159,176,16,243,159,162,1,209,80,209,142,34,149,40,138,
    215,104,191,66,197,13,138,43,244,152,104,199,161,196,161,99,
    22,92,250,202,161,108,89,190,169,210,192,21,141,162,73,157,
    18,143,118,42,116,63,91,35,47,169,210,126,157,138,111,73,
    41,149,41,122,16,47,80,188,72,143,217,58,11,53,49,184,
    72,113,93,132,26,197,75,34,212,105,178,74,201,18,237,176,
    241,5,218,105,176,169,171,108,234,140,152,250,19,166,98,158,
    89,167,184,129,229,236,203,67,172,244,176,82,246,56,35,86,
    86,40,94,17,129,109,185,212,95,133,16,175,138,102,77,52,
    107,165,176,78,59,235,136,161,211,218,96,12,210,39,252,211,
    82,44,153,101,30,14,146,66,167,121,22,164,217,94,158,58,
    152,175,98,0,116,17,134,133,41,134,31,0,195,63,72,0,
    140,157,41,134,71,68,10,239,68,3,135,142,68,56,114,104,
    210,162,67,69,125,143,98,151,14,121,155,10,29,43,234,42,
    58,118,232,107,23,11,142,120,244,56,234,151,200,51,22,192,
    190,68,109,45,45,208,81,133,14,43,212,121,112,232,64,177,
    95,163,226,119,250,126,83,140,46,138,81,135,14,121,244,232,
    216,163,163,42,221,231,69,172,234,215,128,149,122,112,200,145,
    178,166,211,242,216,219,237,185,112,17,74,156,22,89,56,76,
    12,130,12,76,17,70,73,171,94,206,229,122,107,20,154,158,
    47,139,93,160,48,28,25,49,146,103,137,89,98,97,47,205,
    226,96,152,199,227,65,98,22,97,33,216,75,7,73,16,200,
    228,39,195,81,94,152,15,139,34,47,124,0,41,202,65,30,
    206,190,0,140,209,32,215,73,11,187,201,54,62,204,27,172,
    222,27,137,69,56,32,14,226,227,56,209,81,145,142,12,231,
    199,90,196,106,88,107,33,51,50,232,143,121,104,199,161,9,
    175,183,123,249,48,105,31,164,241,88,247,210,246,221,100,120,
    167,200,211,56,216,205,243,125,157,14,219,221,100,248,86,123,
    119,156,14,226,246,109,255,179,246,104,98,122,121,214,214,143,
    210,110,91,112,216,98,205,58,44,178,38,72,37,150,160,151,
    12,70,73,1,87,244,11,216,77,173,170,101,85,85,174,106,
    169,6,75,21,126,92,181,233,44,169,237,20,209,68,136,16,
    200,186,37,97,126,35,73,13,103,118,223,161,98,19,116,232,
    243,159,66,254,152,20,29,204,57,50,119,15,48,88,109,223,
    69,146,173,242,80,40,196,92,226,149,55,145,213,140,132,7,
    21,234,87,201,242,131,105,101,9,83,76,48,242,114,152,113,
    216,184,71,250,215,167,45,100,171,196,48,115,45,177,234,28,
    111,245,131,80,174,211,130,227,219,66,2,211,75,117,254,40,
    19,168,33,75,145,116,24,147,47,38,159,239,246,147,200,232,
    203,172,120,152,143,155,81,152,101,185,105,134,113,220,12,141,
    41,210,221,177,73,116,211,228,205,43,186,85,67,110,215,74,
    30,205,236,77,70,37,111,144,99,230,141,125,137,211,200,240,
    203,134,188,8,254,58,49,204,129,94,30,107,214,195,68,55,
    49,62,156,52,103,120,184,93,110,39,100,107,85,75,106,232,
    100,176,103,234,194,178,80,235,64,182,131,94,8,133,175,15,
    194,193,216,114,95,155,208,240,174,16,237,70,167,69,169,11,
    8,170,140,9,56,5,89,158,197,19,118,41,141,94,193,110,
    23,132,88,203,4,106,157,101,90,45,240,88,165,6,211,108,
    213,137,224,189,55,37,149,16,234,28,98,37,73,178,154,246,
    1,38,215,49,119,139,150,35,229,46,97,72,105,53,33,225,
    99,31,220,245,47,97,216,196,240,98,25,233,41,132,219,120,
    54,220,107,216,194,145,24,35,119,26,205,172,60,182,159,42,
    143,139,39,229,193,141,172,3,154,59,40,134,19,154,187,136,
    183,184,53,229,52,10,136,211,202,211,115,76,22,20,252,85,
    68,87,45,73,232,131,89,243,244,234,206,209,203,71,2,132,
    91,254,197,127,66,236,242,255,130,88,215,34,246,38,182,88,
    158,178,162,33,108,168,171,8,41,117,166,248,9,118,119,88,
    152,156,7,118,243,168,157,231,83,232,126,214,144,227,68,142,
    36,57,49,109,11,176,96,90,193,3,127,246,92,58,55,61,
    38,52,42,118,84,228,223,77,154,249,94,211,80,233,195,205,
    43,122,235,138,126,151,107,186,121,75,186,132,173,106,91,183,
    69,50,42,184,62,107,242,98,107,46,144,250,11,166,45,159,
    209,61,11,212,156,18,83,105,49,218,20,232,44,167,5,104,
    125,6,40,252,123,7,246,235,130,166,75,231,249,169,43,113,
    34,200,165,155,201,25,47,179,252,188,15,92,17,90,66,184,
    30,249,29,235,162,120,143,56,252,87,159,226,193,243,247,221,
    191,10,47,202,138,169,210,44,235,120,92,120,7,18,255,196,
    167,165,66,226,127,36,100,152,19,57,165,189,20,24,30,36,
    106,3,203,191,33,105,20,127,115,254,56,182,124,156,105,43,
    225,234,210,111,203,82,123,28,125,74,63,207,117,153,99,151,
    20,142,14,119,122,165,153,63,58,188,89,193,9,53,254,213,
    241,224,61,93,153,200,71,47,212,88,102,107,208,157,213,224,
    73,195,154,221,74,184,177,156,2,107,22,173,229,0,78,220,
    61,225,12,250,242,37,181,225,204,49,225,117,12,111,204,72,
    160,74,221,243,245,231,242,179,141,116,238,220,8,108,243,250,
    8,155,122,226,230,74,53,42,73,12,31,239,34,247,104,44,
    198,38,155,232,23,164,10,211,219,54,8,185,78,161,65,230,
    99,51,26,27,139,46,108,133,69,247,180,42,211,111,179,177,
    123,116,114,30,252,71,151,211,110,150,23,137,5,254,218,41,
    22,227,117,54,246,229,137,187,194,202,103,254,69,176,91,111,
    204,168,57,209,62,52,254,202,204,97,185,212,22,57,95,35,
    205,68,46,47,54,169,51,21,154,231,54,223,79,236,189,185,
    137,239,94,198,128,187,129,255,218,44,75,210,172,164,61,216,
    118,155,37,143,164,225,74,189,248,91,24,128,174,248,44,121,
    140,14,194,226,52,91,149,4,118,211,182,249,91,112,73,223,
    224,1,151,152,218,74,77,85,29,220,140,93,85,231,11,141,
    167,150,27,53,183,86,173,85,92,190,212,64,179,161,234,110,
    109,169,230,216,223,191,0,84,136,15,190,
};

EmbeddedPython embedded_m5_internal_trace(
    "m5/internal/trace.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/swig/trace.py",
    "m5.internal.trace",
    data_m5_internal_trace,
    1499,
    3755);

} // anonymous namespace
