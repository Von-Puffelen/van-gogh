#include "geometry.h"

/// Midpoint Circle Algorithm
/// wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
void gogh_draw_circle(struct goghApplication *app, int x0, int y0, int radius)
{
    const int diameter = (radius * 2); 
    
    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y) {

        /* Draw octants */
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + x, y0 - y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + x, y0 + y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - x, y0 - y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + y, y0 - x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + y, y0 + x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - y, y0 - x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - y, y0 + x); 

        /* Draw fillings */
        SDL_RenderDrawLine(app->gogh_renderer, x0 - y, y0 - x, x0 + y, y0 - x);
        SDL_RenderDrawLine(app->gogh_renderer, x0 - x, y0 - y, x0 + x, y0 - y);
        SDL_RenderDrawLine(app->gogh_renderer, x0 - x, y0 + y, x0 + x, y0 + y);
        SDL_RenderDrawLine(app->gogh_renderer, x0 - y, y0 + x, x0 + y, y0 + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}
