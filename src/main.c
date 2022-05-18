#include <stdio.h>
#include <SDL2/SDL.h>

#include "window.h"

struct Application {
    SDL_Renderer *gogh_renderer;
    SDL_Window *gogh_window;
};

int main() {

    struct Application app = {
        .gogh_window = NULL,
        .gogh_renderer = NULL
    };

    // fix for MacOs retina display.
    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0"); 

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("- main.c: Cannot initialize SDL, error: %s\n", SDL_GetError());
        return 0;
    }

    if (gogh_initialize_window(app.gogh_window)) {
        printf("- window.c: Cannot initialize SDLWindow, error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Event event;
    int exit = 0;

    while(!exit) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                exit = 1;
        }
    }

    gogh_close_window(app.gogh_window);

    return 0;
}
