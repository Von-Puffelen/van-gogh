#ifndef _GOGH_WINDOW_H__
#define _GOGH_WINDOW_H__

#include <SDL2/SDL.h>
#include "defines.h"

int gogh_initialize_window(struct goghApplication *application);

int gogh_destroy_window(struct goghApplication *application);

#endif // _GOGH_WINDOW_H__
