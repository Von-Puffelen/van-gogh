#include "window.h"

int gogh_initialize_window(struct goghApplication *application)
{
    application->gogh_window = SDL_CreateWindow(
        GOGH_APPLICATION_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        GOGH_WINDOW_WIDTH,
        GOGH_WINDOW_HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI);

    if (application->gogh_window == NULL) 
        return -1;

    return 0;
    
}

int gogh_destroy_window(struct goghApplication *window)
{
    SDL_DestroyWindow(window->gogh_window);
    return 0;
}
