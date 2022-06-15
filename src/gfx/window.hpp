#pragma once

#include "gfx/gfx.hpp"
#include "util/math.hpp"

using glm::i16vec2;

struct Window {

    GLFWwindow *handle;
    i16vec2 size;

    void create(const char *name, i16vec2 size);
    
    void destroy();
    
};
