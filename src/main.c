#include "GOGH/defines.h"

#include "window.h"
#include "renderer/renderer.h"
#include "input/keyboard.h"
#include "geometry/geometry.h"

struct goghApplication application = {
    .is_running = 0,
    .gogh_window = NULL,
    .gogh_renderer = NULL
};

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        GOGH_EXIT_ERROR("main.c: Cannot initialize SDL");
    } else {
        application.is_running = 1;
    }

    gogh_initialize_window(&application);
    gogh_initialize_renderer(&application);

    while(application.is_running) {

        u_int64_t start = SDL_GetPerformanceCounter();

        /* Rendering */
        SDL_SetRenderDrawColor(application.gogh_renderer, 0xF2, 0xF2, 0xf7, 0xFF);	
        SDL_RenderClear(application.gogh_renderer);

        /* Controller */
        gogh_input();
        

        SDL_RenderPresent(application.gogh_renderer);

        /* Framerate cap at 60 FPS */
        u_int64_t end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float) SDL_GetPerformanceCounter() * 1000.0f;
        SDL_Delay(floor(16.666f - elapsed));

    }

    gogh_destroy_window(&application);
    gogh_destroy_renderer(&application);
    
    SDL_Quit();

    return 0;
}
