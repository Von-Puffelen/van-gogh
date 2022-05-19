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
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + x, y0 - y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + x, y0 + y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - x, y0 - y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + y, y0 - x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 + y, y0 + x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - y, y0 - x);
        SDL_RenderDrawPoint(app->gogh_renderer, x0 - y, y0 + x); 


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

void gogh_fill_circle(struct goghApplication *app, int x0, int y0, int radius)
{
    int x_offset = 0;
    int y_offset = radius;
    int delta = radius - 1;
    
    while (y_offset >= x_offset) {

        SDL_RenderDrawLine(
            app->gogh_renderer,
            x0 - y_offset, y0 + x_offset,
            x0 + y_offset, y0 + x_offset);

        SDL_RenderDrawLine(
            app->gogh_renderer,
            x0 - x_offset, y0 + y_offset,
            x0 + x_offset, y0 + y_offset);
        
        SDL_RenderDrawLine(
            app->gogh_renderer,
            x0 - x_offset, y0 - y_offset,
            x0 + x_offset, y0 - y_offset);

        SDL_RenderDrawLine(
            app->gogh_renderer,
            x0 - y_offset, y0 - x_offset,
            x0 + y_offset, y0 - x_offset);

        if (delta >= 2 * x_offset) {
            delta -= 2 * x_offset + 1;
            x_offset += 1;

        } else if (delta < 2 * (radius - y_offset)) {
            delta += 2 * y_offset - 1;
            y_offset += 1;

        } else {
            delta += 2 * (y_offset - x_offset - 1);
            y_offset -= 1;
            x_offset += 1;
        }
        
    }
    
}
