#include "defines.h"
#include "window.h"
#include "renderer.h"

int main() {

    struct goghApplication application = {
        .gogh_window = NULL,
        .gogh_renderer = NULL
    };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("- main.c: Cannot initialize SDL, error: %s\n", SDL_GetError());
        return 0;
    }

    gogh_initialize_window(&application);

    if (application.gogh_window == NULL) {
        printf("- window.c: Cannot initialize SDLWindow, error: %s\n", SDL_GetError());
        return 0;
    }

    gogh_initialize_renderer(&application);

    if (application.gogh_renderer == NULL) {
        printf("- main.c: Cannot create renderer, error: %s\n", SDL_GetError());
        return 0;
    }
        
    SDL_SetRenderDrawColor(application.gogh_renderer, 0x1C, 0x1C, 0x20, 0xFF);
    SDL_RenderClear(application.gogh_renderer);

    SDL_RenderPresent(application.gogh_renderer);

    SDL_Event event;
    int exit = 0;

    while(!exit) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                exit = 1;
        }
    }

    gogh_destroy_window(&application);
    gogh_destroy_renderer(&application);
    
    SDL_Quit();

    return 0;
}
