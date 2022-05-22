#ifndef _KEYBOARD_H__
#define _KEYBOARD_H__

#include "GOGH/defines.h"

void gogh_input();

void gogh_on_key_down_event(SDL_KeyboardEvent *event, struct goghMovableObject *obj);

void gogh_on_key_up_event(SDL_KeyboardEvent *event, struct goghMovableObject *obj);

#endif // _KEYBOARD_H__
