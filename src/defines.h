#ifndef _DEFINES_H__
#define _DEFINES_H__

#include <stdio.h>
#include <SDL2/SDL.h>

#define GOGH_APPLICATION_NAME "Application"

#define GOGH_WINDOW_WIDTH 1280
#define GOGH_WINDOW_HEIGHT 720

struct goghApplication {
    SDL_Window *gogh_window;
    SDL_Renderer *gogh_renderer;
};

#endif // _DEFINES_h__
