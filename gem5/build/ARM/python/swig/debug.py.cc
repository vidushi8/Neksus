#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_debug[] = {
    120,156,213,93,91,108,28,89,90,254,171,187,237,164,219,118,
    108,199,137,115,79,58,147,73,210,201,76,226,185,45,104,151,
    81,180,51,9,27,178,48,217,217,242,176,153,233,93,182,167,
    220,117,108,151,221,93,213,83,85,118,226,33,1,177,25,118,
    23,52,18,87,1,66,8,132,150,21,66,8,33,132,184,10,
    33,132,86,43,224,129,7,30,120,224,129,7,144,144,64,220,
    239,247,229,255,254,170,83,221,229,118,152,100,170,171,156,25,
    187,207,28,159,170,62,255,247,159,243,95,79,157,58,105,83,
    252,223,24,127,62,90,39,10,190,185,76,100,243,175,65,29,
    162,174,65,77,131,12,101,144,125,137,214,199,200,127,129,236,
    49,122,135,168,89,34,85,162,251,92,41,211,167,75,228,78,
    202,119,198,169,83,150,22,131,182,106,164,42,212,28,163,91,
    238,44,85,212,56,173,215,200,127,147,12,195,112,13,122,221,
    222,67,246,94,122,135,123,231,74,85,58,220,75,118,77,42,
    85,178,39,164,82,163,173,25,82,19,212,228,206,247,80,115,
    138,187,186,200,93,237,147,174,190,130,174,108,190,114,153,236,
    41,220,206,88,222,192,157,21,220,41,52,246,73,47,211,100,
    79,163,151,101,230,97,38,185,145,59,46,211,218,44,53,103,
    73,241,239,12,221,103,54,237,89,249,198,126,185,182,31,21,
    123,191,254,234,92,242,213,57,185,124,128,154,7,72,241,239,
    92,244,85,169,225,198,131,201,141,7,229,198,121,106,206,147,
    226,223,131,209,141,82,195,141,135,146,27,15,201,141,135,169,
    121,152,20,255,30,138,110,60,44,96,142,200,181,35,168,216,
    71,164,229,168,180,28,69,197,62,42,45,199,164,229,24,42,
    246,49,105,57,46,45,199,81,177,143,75,203,9,105,57,129,
    138,125,66,90,78,74,203,73,84,236,147,154,205,83,9,168,
    83,114,185,78,205,58,41,254,61,37,160,208,116,154,154,167,
    73,157,166,181,39,168,249,132,84,206,80,243,12,217,117,233,
    245,73,249,218,147,168,216,167,165,229,172,180,156,69,197,126,
    66,90,206,73,203,57,84,236,51,210,114,94,90,206,163,98,
    63,41,45,13,105,105,160,98,159,149,150,11,210,114,1,21,
    251,156,180,92,148,150,139,168,216,231,165,229,41,105,121,10,
    21,187,33,45,79,75,203,211,168,216,23,52,151,23,19,46,
    47,201,229,203,212,188,76,138,127,47,69,92,50,79,11,212,
    92,16,230,158,161,230,51,82,121,150,154,207,74,229,57,106,
    62,71,246,83,210,253,243,242,253,231,81,177,159,150,150,23,
    164,229,5,84,88,31,22,27,11,172,88,206,215,248,191,134,
    193,181,112,146,139,77,229,7,142,231,182,28,119,217,115,74,
    184,62,142,2,106,216,70,177,39,214,199,171,208,199,159,35,
    81,70,187,20,235,227,61,98,217,48,160,110,157,18,221,147,
    202,189,18,109,53,232,174,65,107,21,178,203,116,151,201,140,
    129,145,21,131,238,151,232,51,101,220,112,143,203,10,107,208,
    73,170,132,145,50,174,137,6,69,61,237,161,123,99,116,119,
    140,22,95,191,91,66,195,122,149,252,47,211,219,199,165,211,
    189,210,105,137,238,114,89,161,251,21,186,55,78,183,248,38,
    110,90,171,98,24,141,215,239,50,167,220,178,216,168,48,218,
    155,3,236,130,21,219,241,93,171,171,66,48,217,178,213,210,
    198,74,163,166,175,121,193,229,158,21,174,154,114,115,25,163,
    208,237,133,210,137,231,170,112,130,43,203,142,107,183,186,158,
    189,209,81,225,94,244,208,90,118,58,170,213,146,139,55,186,
    61,207,15,191,209,247,61,223,196,64,74,99,199,179,146,111,
    96,24,219,29,47,80,13,80,19,50,38,186,15,113,247,114,
    79,122,4,0,1,136,47,219,42,104,251,78,47,228,249,137,
    122,196,221,232,173,129,153,145,34,248,38,46,22,108,43,180,
    158,93,88,245,186,106,97,211,177,55,130,85,103,225,186,234,
    94,243,61,199,110,45,121,222,122,224,116,23,86,84,247,67,
    11,75,27,78,199,94,120,201,124,101,161,183,21,174,122,238,
    66,112,219,89,89,144,113,184,204,45,251,209,35,183,180,28,
    225,165,181,170,58,61,229,3,74,112,20,212,140,25,99,210,
    24,55,202,70,195,152,226,218,24,127,202,198,241,210,132,113,
    211,1,55,109,112,136,145,45,107,129,249,18,201,212,240,204,
    174,151,200,63,14,113,88,227,95,3,243,199,66,177,136,107,
    37,185,246,73,12,67,212,186,86,198,36,71,141,119,69,132,
    88,150,248,206,23,49,171,46,137,28,140,209,218,56,69,242,
    193,98,21,9,140,191,133,146,111,71,55,37,238,188,66,193,
    247,165,123,112,103,136,135,153,237,50,55,205,51,169,207,137,
    200,45,54,0,252,166,8,65,184,234,4,222,109,87,134,26,
    117,81,146,69,30,147,87,183,62,177,180,166,218,97,112,138,
    27,222,240,54,234,109,203,117,189,176,110,217,118,221,10,67,
    223,89,218,8,85,80,15,189,250,217,160,81,197,220,206,106,
    57,74,250,219,234,105,185,193,28,179,220,68,127,216,78,59,
    228,63,230,228,15,25,255,64,133,44,3,171,158,29,112,59,
    186,88,81,161,9,144,225,62,46,94,210,228,68,216,26,227,
    90,52,2,213,89,14,107,34,101,86,16,180,132,28,218,69,
    160,240,237,77,171,179,17,201,126,16,90,33,83,69,53,34,
    148,151,72,29,6,83,154,39,140,83,203,245,92,123,139,33,
    57,237,51,160,118,88,4,107,146,32,90,7,89,172,246,112,
    57,78,83,44,102,51,165,54,208,87,98,161,18,129,154,7,
    175,36,147,108,196,118,128,133,235,62,91,139,70,73,212,93,
    216,16,213,170,163,134,47,155,144,93,243,24,138,227,40,78,
    104,78,115,96,119,106,59,187,207,128,68,73,120,108,151,99,
    110,18,245,184,153,82,143,35,125,245,96,67,182,8,49,47,
    65,25,250,98,94,6,191,254,149,88,166,161,64,60,173,124,
    121,64,146,101,20,204,25,112,55,174,133,208,132,100,13,138,
    215,202,128,120,153,152,0,145,45,243,200,131,70,236,84,33,
    35,182,18,141,216,243,32,49,25,75,197,148,72,67,205,104,
    99,74,75,241,248,201,216,93,227,202,214,33,140,221,224,168,
    29,98,47,116,203,157,18,119,34,46,73,162,175,200,4,68,
    131,25,85,42,144,159,229,50,205,199,110,34,128,198,246,124,
    239,206,86,221,91,174,135,164,49,188,120,54,184,124,54,248,
    6,214,233,250,21,177,18,145,86,71,122,235,171,158,207,250,
    89,149,63,34,157,107,137,254,181,98,147,207,163,123,16,163,
    86,210,99,42,38,38,8,125,88,150,188,6,180,150,12,40,
    240,125,24,253,215,100,52,203,116,136,63,53,67,64,180,60,
    177,102,226,227,229,42,127,94,198,184,130,53,69,8,181,205,
    197,8,162,160,7,31,230,249,148,28,140,30,187,121,17,40,
    180,198,140,83,50,235,248,148,129,14,66,252,5,146,192,201,
    160,207,19,102,152,39,50,22,123,81,48,124,48,81,115,184,
    253,179,36,134,98,7,255,83,138,212,167,20,155,18,214,174,
    224,235,229,214,200,29,125,156,190,56,96,101,238,151,201,128,
    235,40,199,33,205,160,235,168,36,10,39,162,241,80,238,161,
    146,214,76,204,199,170,21,224,182,72,7,203,137,14,246,13,
    86,18,149,176,97,201,65,106,246,70,61,183,0,226,122,95,
    102,96,151,143,25,115,165,1,73,120,26,197,165,68,8,12,
    221,54,90,60,167,182,27,210,1,191,209,138,140,215,199,64,
    180,34,48,167,199,197,49,70,126,250,70,168,124,43,244,252,
    68,182,199,180,108,255,121,34,219,74,108,234,59,18,206,162,
    44,97,102,239,151,12,78,24,57,58,64,236,92,33,53,70,
    205,113,82,123,16,117,34,19,28,139,51,65,14,165,81,153,
    160,126,230,40,89,33,146,71,3,25,95,156,60,238,211,201,
    35,167,125,147,82,153,137,243,67,206,244,226,140,112,63,50,
    66,84,230,226,140,144,51,185,56,245,59,136,140,15,149,249,
    56,227,227,220,140,83,59,84,14,199,169,29,18,177,249,56,
    17,139,114,56,78,187,88,109,97,210,69,119,244,71,44,38,
    44,109,202,195,200,220,221,140,102,53,145,198,72,208,80,220,
    201,203,66,65,214,94,236,88,221,37,219,186,242,73,244,14,
    18,109,173,231,37,141,119,102,16,47,116,212,120,16,100,249,
    243,25,141,123,51,47,235,244,44,119,150,224,21,93,180,189,
    182,152,164,215,86,85,189,171,186,75,156,76,173,58,189,250,
    114,199,90,145,241,47,199,252,124,66,243,19,138,196,109,247,
    215,1,236,222,77,175,222,246,92,118,14,27,109,22,222,186,
    173,56,219,80,118,253,82,93,60,75,221,9,234,214,18,95,
    181,218,97,164,115,105,75,33,129,158,229,175,4,18,211,173,
    223,70,53,207,249,107,113,198,232,112,212,106,38,243,55,36,
    111,64,100,247,197,76,64,143,37,38,227,40,229,231,70,48,
    81,223,58,4,44,17,172,169,104,34,214,12,29,69,13,74,
    149,36,90,7,134,140,73,75,98,231,252,161,195,214,127,74,
    67,143,178,170,196,1,14,42,70,130,63,114,94,195,44,204,
    13,179,224,184,109,127,32,22,193,55,220,188,100,4,147,15,
    122,183,134,244,59,51,27,182,26,100,195,252,112,126,179,33,
    92,128,220,235,41,97,210,92,92,223,137,139,119,119,146,167,
    67,59,112,193,185,165,229,182,213,0,39,47,228,200,9,116,
    86,147,124,35,35,55,59,104,135,122,107,195,234,20,196,10,
    108,136,208,107,102,81,241,29,4,171,237,245,182,114,215,112,
    145,41,80,250,244,136,209,187,234,78,88,12,122,80,250,76,
    22,244,59,168,67,75,240,183,90,249,115,16,47,192,8,181,
    111,27,49,23,61,95,109,58,222,70,80,12,23,154,218,103,
    51,234,243,252,48,35,150,189,89,160,113,66,2,20,83,108,
    101,228,229,224,78,162,165,222,98,193,42,134,21,89,88,22,
    130,111,230,193,137,171,10,230,4,4,173,140,156,236,168,238,
    14,103,198,133,241,18,71,172,66,114,41,23,110,130,141,165,
    162,185,17,146,237,209,235,62,79,120,129,83,35,139,81,17,
    69,59,15,94,138,156,152,136,23,161,168,104,187,103,73,229,
    69,119,251,121,145,96,41,200,235,57,60,46,173,214,178,198,
    214,144,229,165,100,105,79,214,80,162,69,151,158,239,245,148,
    31,110,69,11,91,95,135,226,2,138,179,41,243,100,171,142,
    10,85,43,61,230,225,12,37,11,205,182,226,140,213,219,106,
    181,226,161,225,47,112,202,136,28,199,252,8,138,23,81,92,
    65,241,81,20,88,250,51,177,176,107,98,109,199,196,0,152,
    31,71,241,45,40,176,90,110,190,138,2,73,167,249,26,10,
    164,74,230,173,212,184,229,144,148,225,185,41,8,7,88,231,
    26,55,142,25,85,99,156,63,248,153,228,159,234,3,127,82,
    203,171,50,249,181,68,144,183,175,192,200,168,226,242,146,175,
    172,245,158,231,184,97,174,76,33,130,91,167,228,233,132,68,
    118,31,195,194,133,198,156,44,155,189,69,163,94,54,67,101,
    82,22,207,72,22,204,170,122,193,172,22,47,152,153,139,141,
    137,29,149,231,17,22,177,100,69,40,207,37,6,47,209,241,
    81,172,93,153,207,21,5,215,148,71,44,143,199,186,149,216,
    99,243,67,57,178,14,227,213,163,255,215,26,239,222,42,85,
    48,4,236,17,18,144,106,172,177,242,52,57,127,188,199,35,
    64,35,192,139,141,13,197,164,170,160,180,49,18,204,235,142,
    93,64,90,7,204,160,180,153,5,243,132,198,172,92,107,169,
    147,191,100,72,170,16,209,186,157,5,247,100,34,31,78,80,
    12,240,104,75,144,16,187,163,145,55,36,228,73,130,34,19,
    107,127,15,14,131,162,125,58,18,6,1,186,137,53,41,19,
    75,59,209,163,187,55,81,32,227,48,17,220,154,203,148,115,
    164,130,5,13,23,189,98,141,46,29,169,68,63,18,97,44,
    58,221,94,71,237,236,236,241,237,247,116,246,209,118,202,216,
    229,143,107,31,191,71,251,248,189,164,34,223,191,71,251,254,
    189,177,239,87,147,180,54,37,158,190,218,247,244,53,122,220,
    61,253,61,250,64,121,250,4,238,195,121,250,36,203,250,72,
    95,69,57,197,138,54,243,29,24,216,59,33,15,205,141,91,
    238,12,246,87,220,149,103,231,173,82,180,197,162,63,63,149,
    68,55,144,78,184,234,118,171,47,110,209,238,9,152,11,171,
    215,83,174,189,61,14,152,205,113,96,160,189,223,73,201,147,
    237,105,163,76,7,248,243,126,12,213,108,74,135,90,216,76,
    85,196,154,159,222,184,181,17,220,167,12,102,118,62,141,190,
    133,39,235,111,43,223,43,98,241,21,230,114,128,224,59,148,
    228,31,35,152,135,130,220,157,152,242,239,201,50,3,251,211,
    184,139,114,119,226,126,190,119,8,248,99,18,10,191,75,239,
    233,128,251,190,87,92,113,7,5,252,85,188,186,193,20,177,
    188,144,120,218,190,144,232,133,138,190,33,74,252,116,174,238,
    120,149,196,57,244,221,49,59,227,10,187,225,210,120,57,118,
    199,136,121,174,122,221,158,183,225,218,59,59,100,44,113,140,
    192,33,87,105,173,150,202,190,217,241,238,221,81,12,30,39,
    199,251,3,244,129,114,188,9,220,221,117,188,24,26,56,222,
    65,193,138,198,99,141,134,147,239,188,157,238,15,209,72,156,
    238,220,54,77,41,212,220,255,40,101,48,247,7,182,35,47,
    212,224,255,216,16,244,199,196,224,255,184,6,214,192,16,62,
    140,193,223,102,217,33,17,177,101,79,73,122,49,182,29,208,
    191,31,189,34,204,29,176,237,239,103,217,23,134,216,234,116,
    128,62,200,21,52,178,220,159,162,126,208,165,65,226,207,235,
    67,210,252,238,131,176,226,69,24,128,141,4,37,199,71,42,
    230,22,119,246,165,108,128,37,189,92,181,220,21,85,12,228,
    183,185,179,159,205,6,25,81,65,160,194,107,232,178,24,208,
    223,206,157,253,124,54,208,208,131,118,71,89,126,129,176,17,
    92,253,226,54,216,143,162,120,192,108,111,116,123,9,228,124,
    213,15,137,249,47,247,225,74,70,119,117,139,7,45,24,142,
    251,240,28,236,81,227,190,225,167,46,28,229,129,200,227,29,
    229,253,26,125,160,162,188,4,238,238,70,121,16,109,137,242,
    68,128,118,47,190,251,13,122,112,124,247,152,132,26,191,173,
    103,76,158,42,62,76,168,33,35,12,29,209,1,70,52,200,
    197,132,22,223,193,157,253,170,30,213,126,104,241,126,157,159,
    239,117,95,113,218,190,247,234,213,252,13,242,119,113,103,95,
    165,76,126,4,119,184,158,223,181,58,133,161,254,28,119,246,
    7,217,80,195,101,59,129,89,224,80,99,17,240,15,179,129,
    134,116,4,237,85,101,191,140,61,7,249,67,198,122,223,31,
    101,131,12,143,29,90,235,234,234,170,106,199,187,36,114,135,
    253,221,220,217,31,111,131,173,161,63,76,148,129,203,106,83,
    185,225,91,215,56,214,200,213,116,124,158,59,251,147,12,80,
    97,31,123,91,45,30,86,37,143,236,243,196,250,5,238,236,
    79,51,96,133,221,198,139,209,170,235,133,234,250,181,151,95,
    245,252,124,1,127,145,59,251,179,108,226,11,204,193,118,204,
    185,11,48,86,171,255,162,15,92,114,184,151,226,124,115,56,
    242,228,48,115,4,43,142,241,66,99,85,63,252,171,233,103,
    126,19,122,155,207,164,126,65,110,74,191,32,183,79,191,32,
    55,173,95,144,155,209,47,200,205,234,23,228,246,235,23,228,
    230,244,11,114,7,244,11,114,7,245,11,114,243,250,5,185,
    67,250,5,185,195,250,5,185,35,20,159,102,114,84,31,98,
    114,76,159,93,114,92,31,89,114,66,159,84,114,82,31,80,
    114,10,231,146,160,82,143,207,37,105,158,214,167,140,60,161,
    15,23,57,163,207,20,121,82,31,37,114,86,159,32,114,142,
    212,121,57,65,228,130,62,65,228,34,34,243,115,244,184,71,
    230,127,69,31,168,200,60,129,251,222,145,249,251,120,212,164,
    53,70,182,81,98,171,99,49,219,54,53,181,191,78,230,98,
    72,100,106,201,92,220,223,22,99,191,155,136,74,158,49,54,
    118,96,254,205,16,188,71,92,34,77,134,183,200,39,146,242,
    252,232,111,179,64,159,77,67,143,30,66,229,143,27,155,50,
    255,46,11,238,153,52,238,142,114,139,120,0,28,237,3,22,
    98,127,159,5,253,228,32,250,158,215,203,31,57,178,106,38,
    244,15,41,212,192,242,232,175,117,12,12,59,199,47,65,199,
    105,23,247,90,199,164,76,64,159,236,63,142,150,159,96,119,
    248,233,147,253,167,209,242,195,233,255,110,240,211,39,251,207,
    25,249,57,48,196,15,251,147,110,97,236,76,104,118,34,170,
    255,50,90,110,88,140,119,129,155,132,234,191,142,150,155,96,
    87,184,73,168,254,91,70,110,166,7,185,137,247,119,21,194,
    136,172,122,254,59,101,240,38,251,6,161,171,110,47,44,224,
    61,96,121,141,25,164,254,35,11,242,169,65,228,129,243,118,
    1,155,102,177,148,11,74,255,57,178,17,151,167,70,197,140,
    184,144,250,175,140,146,158,30,244,219,86,175,32,133,149,145,
    103,114,255,157,101,228,231,7,193,175,224,200,159,78,199,107,
    23,147,206,0,93,138,228,255,140,76,134,150,212,138,227,22,
    35,67,66,234,127,179,32,79,69,175,176,147,133,68,175,76,
    232,107,89,80,167,12,188,95,208,128,227,233,101,68,11,112,
    71,99,39,253,66,134,28,218,10,74,70,22,220,169,236,146,
    211,143,214,146,213,94,47,232,120,129,152,90,201,200,102,45,
    211,206,213,183,130,162,142,21,16,15,11,122,229,20,7,121,
    62,147,133,98,227,153,172,230,119,247,158,202,86,140,157,159,
    202,62,250,252,237,79,137,32,163,138,100,176,152,57,148,115,
    25,53,205,189,89,52,41,37,134,203,190,231,22,112,90,10,
    36,80,72,85,71,102,187,138,209,127,72,52,40,213,50,234,
    126,58,39,8,2,103,197,45,240,248,138,136,224,196,40,121,
    240,149,4,217,197,241,16,17,156,28,37,15,142,27,40,63,
    44,144,135,136,224,84,70,30,82,11,150,60,44,202,223,44,
    242,128,154,152,226,190,145,121,243,182,213,179,218,78,17,169,
    38,188,185,166,54,61,132,63,121,138,176,187,123,116,102,53,
    176,198,83,244,158,123,116,240,88,67,158,58,200,250,189,44,
    134,155,216,140,107,254,32,138,31,70,241,35,40,176,249,217,
    196,70,99,243,39,80,252,36,197,222,216,252,105,20,216,88,
    106,126,25,5,246,107,154,56,222,222,196,38,72,243,23,80,
    96,95,161,249,75,40,176,101,207,252,21,20,178,55,232,215,
    81,252,38,138,223,66,129,205,69,230,239,160,248,93,20,95,
    65,241,213,148,230,197,123,136,146,160,160,152,93,68,120,211,
    231,47,209,43,142,208,136,119,17,61,234,79,101,4,103,90,
    32,126,224,164,79,115,255,169,232,95,28,200,149,245,223,227,
    206,142,26,217,118,65,12,64,206,21,235,239,115,103,39,251,
    88,37,78,220,246,47,49,68,164,113,72,66,116,2,240,86,
    128,19,80,200,156,78,0,75,188,174,207,108,129,194,72,224,
    116,211,234,70,103,196,203,97,232,230,105,20,103,180,34,137,
    101,142,78,129,150,115,151,163,115,172,57,120,149,115,27,228,
    152,6,243,50,10,156,126,18,226,48,240,109,103,235,128,13,
    159,19,179,128,27,228,52,17,121,251,88,108,92,244,90,228,
    224,245,85,92,146,163,147,6,222,155,28,188,1,170,31,130,
    104,234,77,137,212,45,216,188,46,27,194,101,139,181,108,89,
    150,13,192,178,173,86,54,205,69,47,137,200,86,189,212,87,
    163,67,247,54,45,95,198,143,167,85,44,250,43,214,157,215,
    156,246,186,236,89,147,45,96,178,165,74,54,41,201,150,31,
    217,76,35,187,84,100,231,135,236,162,16,173,74,63,36,72,
    17,130,15,136,119,128,153,94,247,101,39,212,148,94,178,109,
    95,140,193,13,119,211,234,56,246,107,171,190,178,236,27,215,
    228,27,113,27,54,131,220,184,38,210,43,98,145,167,220,69,
    167,240,70,231,148,95,193,212,7,63,195,5,78,225,175,78,
    87,141,241,18,254,105,135,178,81,51,166,140,138,49,57,85,
    45,87,199,171,99,101,54,33,104,153,51,106,229,106,109,254,
    80,21,255,47,85,141,249,9,174,149,230,103,165,156,136,91,
    119,250,49,230,171,124,53,50,36,15,186,39,125,255,133,228,
    254,228,27,255,7,83,127,99,133,
};

EmbeddedPython embedded_m5_internal_debug(
    "m5/internal/debug.py",
    "/data1/home/vidushi/GemDroid_booksim/gem5/build/ARM/python/swig/debug.py",
    "m5.internal.debug",
    data_m5_internal_debug,
    4585,
    26664);

} // anonymous namespace
