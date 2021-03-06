#include "GOGH/vangogh.hpp"
#include "gfx/shader.hpp"

#include <fstream>
#include <sstream>
#include <cassert>

void Shader::create(const char *vx_path, const char *fg_path)
{
    unsigned int shader_program;
    unsigned int vertex_shader =
        this->compile(vx_path, GL_VERTEX_SHADER);
    unsigned int fragment_shader =
        this->compile(fg_path, GL_FRAGMENT_SHADER);

    shader_program = glCreateProgram();

    /* Linking */
    int linked_succesfully = 0;
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &linked_succesfully);

    if (!linked_succesfully)
        GOGH_ERROR("Cannot link the vertex and fragment shader together.");

    this->shader = shader_program; 
}

void Shader::use()
{
    glUseProgram(this->shader);
}

unsigned int Shader::compile(const char *shader_path, uint32_t type)
{
    std::ifstream shader_file;
    std::string shader_contents;

    shader_file.open(shader_path);

    /* Reading */
    if (shader_file.is_open()) {
        std::stringstream shader_contents_stream;

        while(shader_file.peek() != EOF) {
            shader_contents_stream << (char) shader_file.get();
        }

        shader_file.close();
        shader_contents = shader_contents_stream.str();
    }

    const char *shader_code = shader_contents.c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(
        shader, GOGH_FILE_ELEMENT_SIZE,
        (const GLchar *const *) &shader_code, NULL);
    
    /* Compiling */
    int linked_succesfully = 0;
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &linked_succesfully);

    if (!linked_succesfully)
        GOGH_ERROR("*Compilation of shader failed*");

    return shader;
}

void Shader::setShaderUniform(const char *name, bool value)
{
    glUniform1i(glGetUniformLocation(this->shader, name), (int) value);
}
void Shader::setShaderUniform(const char *name, float value)
{
    glUniform1i(glGetUniformLocation(this->shader, name), value);
}
void Shader::setShaderUniform(const char *name, int value)
{
    glUniform1i(glGetUniformLocation(this->shader, name), value);
}
void Shader::setShaderUniform(const char *name, glm::mat4 value)
{
    glUniformMatrix4fv(
        glGetUniformLocation(
            this->shader, name), 1, GL_FALSE, glm::value_ptr(value));
}
