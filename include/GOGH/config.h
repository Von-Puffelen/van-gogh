#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define GOGH_EXIT_ON_ERROR(msg) {                 \
    printf("- %s, error: %s \n", __FILE__, msg);  \
    exit(0);                                      \
}

#define GOGH_ERROR(msg) {                         \
    printf("- %s, error: %s \n", __FILE__, msg);  \
}

#define GOGH_COLOUR(value) value / 255.0f

#endif /* _CONFIG_H__ */
