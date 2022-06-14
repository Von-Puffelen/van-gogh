#pragma once

#include "gfx/gfx.hpp"
#include <memory>

struct Window {

    GLFWwindow *handle;

    void create();

    void destroy();
    
};
