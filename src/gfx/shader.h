#ifndef _SHADER_H__
#define _SHADER_H__

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb-image.h"

#define GOGH_FILE_MODE "rb"

#define GOGH_FILE_START SEEK_SET 
#define GOGH_FILE_END SEEK_END

#define GOGH_FILE_ELEMENT_SIZE 1

unsigned int gogh_shader_create(
    const char *vertex_shader_path, const char *fragment_shader_path);

#endif /* _SHADER_H__ */
