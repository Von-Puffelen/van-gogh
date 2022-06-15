#pragma once

#include <iostream>
#include <stdlib.h>

#define UNUSED
#define DEBUG

#define _GOGH_WARNING_COLOUR "\x1B[33m"
#define _GOGH_ERROR_COLOUR "\x1B[31m"
#define _GOGH_NOTE_COLOUR "\x1B[34m"
#define _GOGH_END_COLOUR "\x1B[0m"

#define _GOGH_PRINT_PREFIX  "[DEBUG] " 
#define _GOGH_PRINT_POSTFIX "\n"

#define GOGH_COLOUR(value) value / 255.0f

#ifdef DEBUG

#define GOGH_ERROR(msg)                                              \
    (std::cerr << _GOGH_ERROR_COLOUR << _GOGH_PRINT_PREFIX << (msg)  \
     << _GOGH_END_COLOUR << _GOGH_PRINT_POSTFIX);

#define GOGH_WARN(msg)                                                  \
    (std::cout << _GOGH_WARNING_COLOUR << _GOGH_PRINT_PREFIX << (msg)   \
     << _GOGH_END_COLOUR << _GOGH_PRINT_POSTFIX);

#define GOGH_NOTE(msg)                                              \
    (std::cout << _GOGH_NOTE_COLOUR << _GOGH_PRINT_PREFIX << (msg)  \
     << _GOGH_END_COLOUR << _GOGH_PRINT_POSTFIX);

#define GOGH_EXIT_ON_ERROR(msg)                                         \
    {                                                                   \
        GOGH_ERROR(msg);                                                \
        (std::cerr                                                      \
         << _GOGH_ERROR_COLOUR                                          \
         << "Exiting application..."                                    \
         << _GOGH_END_COLOUR << _GOGH_PRINT_POSTFIX);                   \
        exit(0);                                                        \
    }

#else

#define GOGH_ERROR(msg)  
#define GOGH_WARN(msg)
#define GOGH_NOTE(msg) 
#define GOGH_GOGH_EXIT_ON_ERROR(msg) 

#endif
