#ifndef _DEFINES_H__
#define _DEFINES_H__

#include <stdio.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#define GOGH_APPLICATION_NAME "Application"

#define GOGH_WINDOW_WIDTH 1280
#define GOGH_WINDOW_HEIGHT 720

#define GOGH_EXIT_ERROR(msg)                        \
    printf("- %s, error: %s", msg, SDL_GetError()); \
    exit(0);

struct goghApplication {
    uint8_t is_running;
    SDL_Window *gogh_window;
    SDL_Renderer *gogh_renderer;
};

struct goghMovableObject {
    int up, right, down, left;
};

#endif // _DEFINES_h__
