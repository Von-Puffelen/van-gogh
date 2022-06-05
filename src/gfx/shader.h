#ifndef _SHADER_H__
#define _SHADER_H__

#include <cglm/mat4.h>
#include "gfx.h"

#define GOGH_FILE_MODE "rb"

#define GOGH_FILE_START SEEK_SET 
#define GOGH_FILE_END SEEK_END

#define GOGH_FILE_ELEMENT_SIZE 1

typedef unsigned int goghShader;

goghShader gogh_shader_create(
    const char *vertex_shader_path, const char *fragment_shader_path);

void gogh_shader_set_uniform_mat4(goghShader program, char *name, mat4 value);

void gogh_shader_bind(goghShader *shader);

#endif /* _SHADER_H__ */
