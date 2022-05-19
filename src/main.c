#include <stdio.h>
#include <SDL2/SDL.h>

#include "window.h"

struct Application {
    SDL_Window *gogh_window;
    SDL_Surface *gogh_window_surface;
};

int main() {

    struct Application app = {
        .gogh_window = NULL,
        .gogh_window_surface = NULL
    };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("- main.c: Cannot initialize SDL, error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); //OpenGL core profile
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3); //OpenGL 3.3

    if (gogh_initialize_window(app.gogh_window)) {
        printf("- window.c: Cannot initialize SDLWindow, error: %s\n",
               SDL_GetError());
        return 0;
    }

    app.gogh_window_surface = SDL_GetWindowSurface(app.gogh_window);

    if (app.gogh_window_surface == NULL) {
        printf("- main.c: Cannot get the window surface, error: %s\n",
               SDL_GetError());
    }
    
    SDL_UpdateWindowSurface(app.gogh_window);

    SDL_Event event;
    int exit = 0;

    while(!exit) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                exit = 1;
        }
    }

    SDL_FreeSurface(app.gogh_window_surface);
    
    gogh_close_window(app.gogh_window);

    SDL_Quit();

    return 0;
}
