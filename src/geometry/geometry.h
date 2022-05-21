#ifndef _GEOMETRY_H__
#define _GEOMETRY_H__

#include "GOGH/defines.h"

void gogh_draw_circle(
    struct goghApplication *application,
    int x0, int y0,
    int radius);

void gogh_fill_circle(
    struct goghApplication *application,
    int x0, int y0,
    int radius);

#endif // _GEOMETRY_H__
