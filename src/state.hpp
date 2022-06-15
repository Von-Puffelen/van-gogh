#pragma once

#include "gfx/gfx.hpp"
#include "gfx/window.hpp"
#include "gfx/camera.hpp"

struct State {

    Window *window;

    Camera *camera;

    ~State() {
        delete this->camera;

        this->window->destroy();
        delete this->window;
    }

};
