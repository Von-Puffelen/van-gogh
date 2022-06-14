#include "GOGH/vangogh.hpp"
#include "state.hpp"

#include "gfx/gfx.hpp"
#include "gfx/shader.hpp"
#include "gfx/texture.hpp"

int main(UNUSED int argc, UNUSED char *argv[])
{
    State *state = new State();
    state->window = new Window(); 
    state->window->create("A vanGogh application", { 1280, 720 } );

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.7f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.7f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.7f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.7f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    
    /* Shader */
    Shader *shader_program = new Shader(
        "./resources/vertex_shaders/vertex_shader.glsl",
        "./resources/fragment_shaders/fragment_shader.glsl");

    shader_program->create();

    /* Texture */
    Texture *texture = new Texture();
    texture->create("./resources/textures/prototype-dark.png");

    unsigned int vbo, vao, ebo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Colour attribute
    glVertexAttribPointer(
        1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture attribute
    glVertexAttribPointer(
        2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
    glEnableVertexAttribArray(2);    
    /* Rendering */
    while(!glfwWindowShouldClose(state->window->handle)) {

        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Shaders */
        shader_program->use();

        /* Texture */
        texture->use();
        
        /* Triangle */
        glUseProgram(shader_program->shader);
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(state->window->handle);
        glfwPollEvents();
    }

    state->window->destroy();

    delete state->window;
    delete state;

    return 0;
}
