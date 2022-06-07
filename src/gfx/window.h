#ifndef _WINDOW_H__
#define _WINDOW_H__

#include "GOGH/config.h"
#include "gfx.h"

#include <cglm/vec2.h>

struct Window {
    GLFWwindow *handle;
    ivec2 size;
};

void gogh_window_initialize(struct Window *window, int width, int heigth);
void gogh_window_on_resize_event(struct Window *window, int width, int height);
void gogh_window_destroy(struct Window *window);

#endif /* _WINDOW_H__ */
