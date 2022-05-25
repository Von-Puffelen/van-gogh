#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define GOGH_EXIT_ON_ERROR(msg) {                 \
    printf("- %s, error: %s \n", __FILE__, msg);  \
    exit(0);                                      \
}

#define GOGH_ERROR(msg)                           \
    printf("- %s, error: %s \n", __FILE__, msg);  

#define GOGH_COLOUR(value) value / 255.0f

const char* gogh_name = "Van Gogh - Applicatie";
const u_int16_t gogh_screen_width = 1280;
const u_int16_t gogh_screen_height = 720;

#endif /* _CONFIG_H__ */
