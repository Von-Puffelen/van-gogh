#pragma once

#include "gfx/gfx.hpp"
#include "util/math.hpp"

#include <string>

#define GOGH_FILE_MODE "rb"

#define GOGH_FILE_START SEEK_SET 
#define GOGH_FILE_END SEEK_END

#define GOGH_FILE_ELEMENT_SIZE 1

struct Shader {

    unsigned int shader;

    void create(const char *vertex_shader_path, const char *fragment_shader_path);
    void use();

    void setShaderUniform(const char *name, bool value);
    void setShaderUniform(const char *name, float value);
    void setShaderUniform(const char *name, int value);
    void setShaderUniform(const char *name, glm::mat4 value);

private:

    unsigned int compile(const char *shader_path, uint32_t type);
    
};
