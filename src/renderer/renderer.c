#include "renderer.h"

void gogh_initialize_renderer(struct goghApplication *application)
{
    application->gogh_renderer = SDL_CreateRenderer(
        application->gogh_window,
        -1,
        SDL_RENDERER_ACCELERATED);

    if (application->gogh_renderer == NULL) {
        GOGH_EXIT_ERROR("renderer.c: Cannot create renderer");
    }
}

void gogh_destroy_renderer(struct goghApplication *application)
{
    SDL_DestroyRenderer(application->gogh_renderer);
}
