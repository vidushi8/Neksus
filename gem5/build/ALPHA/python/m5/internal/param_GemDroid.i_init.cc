#include "sim/init.hh"

extern "C" {
    void init_param_GemDroid();
}

EmbeddedSwig embed_swig_param_GemDroid(init_param_GemDroid);
