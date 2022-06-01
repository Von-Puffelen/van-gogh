#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * DEBUGGING 
 */
#define _GOGH_PRINT_EMPHASIS_BOLD  "\e[1m"
#define _GOGH_PRINT_COLOUR__RED    "\x1B[31m"
#define _GOGH_PRINT_COLOUR__YELLOW "\x1B[33m"
#define _GOGH_PRINT_COLOUR__BLUE   "\x1B[34m"
#define _GOGH_PRINT_COLOUR__END    "\x1B[0m"

#define _GOGH_PRINT_ERROR _GOGH_PRINT_EMPHASIS_BOLD "" _GOGH_PRINT_COLOUR__RED
#define _GOGH_PRINT_MESSAGE _GOGH_PRINT_EMPHASIS_BOLD "" _GOGH_PRINT_COLOUR__YELLOW
#define _GOGH_PRINT_NOTE _GOGH_PRINT_EMPHASIS_BOLD "" _GOGH_PRINT_COLOUR__BLUE

#define GOGH_PRINT(format, ...)   \
    printf(format, __VA_ARGS__)

#define GOGH_MESSAGE(type, msg)   \
    GOGH_PRINT("%s- %s, %s: %s\n", _GOGH_PRINT_MESSAGE, __FILE__, type, msg)

#define GOGH_NOTE(msg)            \
    GOGH_PRINT("%s- %s, todo: %s\n", _GOGH_PRINT_NOTE, __FILE__, msg)

#define GOGH_ERROR(msg)           \
    GOGH_PRINT("%s- %s, error: %s\n", _GOGH_PRINT_ERROR, __FILE__, msg)

#define GOGH_EXIT_ON_ERROR(msg) { \
        GOGH_ERROR(msg);          \
        exit(0);                  \
}

/*
 * DEBUGGING 
 */
#define GOGH_COLOUR(value) value / 255.0f

#endif /* _CONFIG_H__ */
