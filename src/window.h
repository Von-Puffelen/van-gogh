
#ifndef   _GOGH_WINDOW_H__
#define   _GOGH_WINDOW_H__

#include <SDL2/SDL.h>
#include "defines.h"

int gogh_initialize_window(SDL_Window *application_window);

int gogh_close_window(SDL_Window *application_window);

#endif // _GOGH_WINDOW_H__
