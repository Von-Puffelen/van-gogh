#include "renderer.h"

int gogh_initialize_renderer(struct goghApplication *application)
{
    application->gogh_renderer = SDL_CreateRenderer(
        application->gogh_window,
        -1,
        SDL_RENDERER_ACCELERATED);

    if (application->gogh_renderer == NULL)
        return -1;

    return 0;
    
}

int gogh_destroy_renderer(struct goghApplication *application)
{
    SDL_DestroyRenderer(application->gogh_renderer);
    return 0;
}
