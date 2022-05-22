#include "window.h"

void gogh_initialize_window(struct goghApplication *application)
{
    application->gogh_window = SDL_CreateWindow(
        GOGH_APPLICATION_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        GOGH_WINDOW_WIDTH,
        GOGH_WINDOW_HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI);

    if (application->gogh_window == NULL) {
        GOGH_EXIT_ERROR("window.c: Cannot initialize SDLWindow");
    }
}

void gogh_destroy_window(struct goghApplication *window)
{
    SDL_DestroyWindow(window->gogh_window);
}
