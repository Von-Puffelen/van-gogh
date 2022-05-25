#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <stdio.h>
#include <stdlib.h>

#define GOGH_EXIT_ON_ERROR(msg)                   \
{                                                 \
    printf("- %s, error: %s \n", __FILE__, msg);  \
    exit(0);                                      \
}

const char* gogh_name = "Van Gogh - Applicatie";
const int gogh_screen_width = 1280;
const int gogh_screen_height = 720;

#endif /* _CONFIG_H__ */
