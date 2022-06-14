#include "GOGH/vangogh.hpp"
#include "state.hpp"

#include "gfx/gfx.hpp"
#include "gfx/shader.hpp"

int main(UNUSED int argc, UNUSED char *argv[])
{
    State *state = new State();
    state->window = new Window(); 
    state->window->create("A vanGogh application", { 1280, 720 } );

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    /* Shader */
    Shader *shader_program = new Shader(
        "./resources/vertex_shaders/vertex_shader.glsl",
        "./resources/fragment_shaders/fragment_shader.glsl");

    shader_program->create();

    unsigned int vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    /* Rendering */
    while(!glfwWindowShouldClose(state->window->handle)) {

        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Shaders */
        shader_program->use();
        
        /* Triangle */
        glUseProgram(shader_program->shader);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(state->window->handle);
        glfwPollEvents();
    }

    state->window->destroy();

    delete state->window;
    delete state;

    return 0;
}
