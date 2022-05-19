#ifndef _RENDERER_H__
#define _RENDERER_H__

#include <SDL2/SDL.h>
#include "defines.h"


int gogh_initialize_renderer(struct goghApplication *application);

int gogh_destroy_renderer(struct goghApplication *application);
    

#endif // _RENDERER_H__
