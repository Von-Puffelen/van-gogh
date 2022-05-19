#include "defines.h"
#include "window.h"
#include "renderer.h"
#include "keyboard.h"

#include "geometry.h"

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
        printf("- main.c: Cannot initialize SDLWindow, error: %s\n", SDL_GetError());
        return 0;
    }

    gogh_initialize_renderer(&application);

    if (application.gogh_renderer == NULL) {
        printf("- main.c: Cannot create renderer, error: %s\n", SDL_GetError());
        return 0;
    }

    struct goghMovableObject player = {0, 0, 0, 0};

    int circle_size = 70;
    int x = GOGH_WINDOW_WIDTH;
    int y = GOGH_WINDOW_HEIGHT - (circle_size / 2);

    while(1) {

        SDL_SetRenderDrawColor(application.gogh_renderer, 0xF2, 0xF2, 0xf7, 0xFF);		
        SDL_RenderClear(application.gogh_renderer);

        gogh_input(&player);

        if (player.up)
            y -= 20;
            
        if (player.right)
            x += 20;

        if (player.down)
            y += 20;

        if (player.left)
            x -= 20;

        SDL_SetRenderDrawColor(application.gogh_renderer, 0x1C, 0x1C, 0x20, 0xFF);
        gogh_draw_circle(&application, x, y, circle_size);
        gogh_fill_circle(&application, x, y, circle_size);
        
        SDL_RenderPresent(application.gogh_renderer);

        SDL_Delay(16);
    }

    gogh_destroy_window(&application);
    gogh_destroy_renderer(&application);
    
    SDL_Quit();

    return 0;
}
