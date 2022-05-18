#include "window.h"

int gogh_initialize_window(SDL_Window *window)
{
    window = SDL_CreateWindow(GOGH_APPLICATION_NAME,
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               GOGH_WINDOW_WIDTH,
                               GOGH_WINDOW_HEIGHT,
                               0);

    if (window == NULL) 
        return -1;

    return 0;
    
}

int gogh_close_window(SDL_Window *window)
{
    SDL_DestroyWindow(window);
    return 0;
}
