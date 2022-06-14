#pragma once

#include "gfx/gfx.hpp"

#include <string>

#define GOGH_FILE_MODE "rb"

#define GOGH_FILE_START SEEK_SET 
#define GOGH_FILE_END SEEK_END

#define GOGH_FILE_ELEMENT_SIZE 1

struct Shader {

    unsigned int shader;
    const char *vertex_shader_path;
    const char *fragment_shader_path;

    Shader(const char *vertex_shader_path, const char *fragment_shader_path)
        : vertex_shader_path(vertex_shader_path),
          fragment_shader_path(fragment_shader_path) {}

    void create();
    void use();

    void setShaderUniform(std::string &name, bool value);
    void setShaderUniform(std::string &name, float value);
    void setShaderUniform(std::string &name, int value);

private:

    unsigned int compile(const char *shader_path, uint32_t type);
    
};
