#include "keyboard.h"

void gogh_input()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        
        switch(event.type) {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            break;
        case SDL_KEYUP:
            break;
        default:
            break;
        }
        
    }
}

void gogh_on_key_down_event(SDL_KeyboardEvent *event, struct goghMovableObject *obj)
{
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP)
            obj->up = 1;
            
        if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
            obj->right = 1;

        if (event->keysym.scancode == SDL_SCANCODE_DOWN)
            obj->down = 1;

        if (event->keysym.scancode == SDL_SCANCODE_LEFT)
            obj->left = 1;

        if (event->keysym.scancode == SDL_SCANCODE_ESCAPE)
            exit(0);
    }
}

void gogh_on_key_up_event(SDL_KeyboardEvent *event, struct goghMovableObject *obj)
{
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP)
            obj->up = 0;
            
        if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
            obj->right = 0;

        if (event->keysym.scancode == SDL_SCANCODE_DOWN)
            obj->down = 0;

        if (event->keysym.scancode == SDL_SCANCODE_LEFT)
            obj->left = 0;
    }
}
