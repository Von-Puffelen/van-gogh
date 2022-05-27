#include "GOGH/config.h"
#include "shader.h"

#include <string.h>
#include <assert.h>

static unsigned int _gogh_shader_compile(const char *shader_path, GLenum type)
{
    FILE *shader_file = fopen(shader_path, GOGH_FILE_MODE);
    char *shader_content;
    long shader_content_length;

    if (shader_file == NULL) 
        GOGH_EXIT_ON_ERROR("Cannot open the shader file.");

    /* Get shader file contents */
    fseek(shader_file, GOGH_FILE_START, GOGH_FILE_END);
    shader_content_length = ftell(shader_file);

    assert(shader_content_length > 0); // Check if file is longer than 0 characters.

    fseek(shader_file, GOGH_FILE_START, GOGH_FILE_START);
    shader_content = calloc(GOGH_FILE_ELEMENT_SIZE, shader_content_length);

    assert(shader_content != NULL); // Check if memory is allocated correctly.

    fread(
        shader_content, GOGH_FILE_ELEMENT_SIZE, shader_content_length, shader_file);

    assert(strlen(shader_content) > 0); // Check if shader has content.

    fclose(shader_file);

    unsigned int shader = glCreateShader(type); 
    glShaderSource(
        shader, GOGH_FILE_ELEMENT_SIZE,
        (const GLchar *const *) &shader_content, NULL);

    /* Compile shader */
    int succes; 
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &succes);

    if (!succes) {
        GOGH_ERROR("Shader compilation failed.");
    } 

    free(shader_content);
    return shader;
    
}

unsigned int gogh_shader_create(const char *vx_path, const char *fm_path)
{
    unsigned int shader_program;
    unsigned int vertex_shader = _gogh_shader_compile(vx_path, GL_VERTEX_SHADER);
    unsigned int fragment_shader = _gogh_shader_compile(fm_path, GL_FRAGMENT_SHADER);

    shader_program = glCreateProgram();
    
    /* Linking */
    int succes;
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &succes);

    if (!succes)
        GOGH_ERROR("Cannot link the vertex and fragment shader together.");

    return shader_program;

}
