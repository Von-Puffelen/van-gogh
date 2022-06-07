#include "GOGH/config.h"

#include "gfx/gfx.h"
#include "gfx/window.h"
#include "gfx/shader.h"
#include "gfx/texture.h"

#include <cglm/cglm.h>

int main(int argc, char** argv)
{
    /* Initialization */
    struct Window window;
    gogh_window_initialize(&window, 1280, 720);

    /* OpenGL functionality */
    glEnable(GL_DEPTH_TEST);

    /* Vertices location */
    float vertices[] = {
        -0.3f, -0.3f, -0.3f,  0.0f, 0.0f,
        0.3f, -0.3f, -0.3f,  1.0f, 0.0f,
        0.3f,  0.3f, -0.3f,  1.0f, 1.0f,
        0.3f,  0.3f, -0.3f,  1.0f, 1.0f,
        -0.3f,  0.3f, -0.3f,  0.0f, 1.0f,
        -0.3f, -0.3f, -0.3f,  0.0f, 0.0f,
        
        -0.3f, -0.3f,  0.3f,  0.0f, 0.0f,
        0.3f, -0.3f,  0.3f,  1.0f, 0.0f,
        0.3f,  0.3f,  0.3f,  1.0f, 1.0f,
        0.3f,  0.3f,  0.3f,  1.0f, 1.0f,
        -0.3f,  0.3f,  0.3f,  0.0f, 1.0f,
        -0.3f, -0.3f,  0.3f,  0.0f, 0.0f,
        
        -0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        -0.3f,  0.3f, -0.3f,  1.0f, 1.0f,
        -0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        -0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        -0.3f, -0.3f,  0.3f,  0.0f, 0.0f,
        -0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        
        0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        0.3f,  0.3f, -0.3f,  1.0f, 1.0f,
        0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        0.3f, -0.3f,  0.3f,  0.0f, 0.0f,
        0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        
        -0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        0.3f, -0.3f, -0.3f,  1.0f, 1.0f,
        0.3f, -0.3f,  0.3f,  1.0f, 0.0f,
        0.3f, -0.3f,  0.3f,  1.0f, 0.0f,
        -0.3f, -0.3f,  0.3f,  0.0f, 0.0f,
        -0.3f, -0.3f, -0.3f,  0.0f, 1.0f,
        
        -0.3f,  0.3f, -0.3f,  0.0f, 1.0f,
        0.3f,  0.3f, -0.3f,  1.0f, 1.0f,
        0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        0.3f,  0.3f,  0.3f,  1.0f, 0.0f,
        -0.3f,  0.3f,  0.3f,  0.0f, 0.0f,
        -0.3f,  0.3f, -0.3f,  0.0f, 1.0f
    };
    
    vec3 cube_positions[10] = {
        {  0.0f,  0.0f, -6.0f  },
        {  0.6f,  3.2f, -7.0f },
        { -1.2f, -1.2f, -2.5f  },
        { -2.3f, -0.7f, -8.3f },
        {  0.4f, -1.4f, -3.5f  },
        { -1.0f,  2.0f, -4.5f  },
        {  1.3f, -2.0f, -2.5f  },
        {  0.4f,  1.0f, -2.5f  },
        {  1.5f,  0.4f, -1.5f  },
        { -1.3f,  1.0f, -1.5f }
    };

    /* Shaders */
    unsigned int shader_program;
    shader_program = gogh_shader_create(
        "./res/vertex_shaders/vertex_shader.glsl",
        "./res/fragment_shaders/fragment_shader.glsl");
    
    /* Vertices buffers */
    unsigned int vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    // Texture attribute
    glVertexAttribPointer(
        1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3* sizeof(float)));
    glEnableVertexAttribArray(1);

    /* Textures */
    unsigned int texture;
    texture = gogh_texture_create("./res/textures/prototype-dark.png");
        
    /* Rendering */
    while (!glfwWindowShouldClose(window.handle))
    {
        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Textures */
        glBindTexture(GL_TEXTURE_2D, texture);

        /* Shaders */
        gogh_shader_bind(&shader_program);

        /* Transformations */
        mat4 projection, view;
        glm_mat4_identity(view);
        glm_mat4_identity(projection);
        
        glm_translate_to(view, (vec3){ 0.0f, 0.0f, -3.0f}, view);
        glm_perspective(glm_rad(45.0f), 1280 / 720, 0.1f, 100.0f, projection);
        
        gogh_shader_set_uniform_mat4(shader_program, "view", view);
        gogh_shader_set_uniform_mat4(shader_program, "projection", projection);

        for (int i = 0; i < 10; i++) {
            mat4 model;
            glm_mat4_identity(model);

            glm_translate(model, cube_positions[i]);

            float angle = 20.0f * (i + 0.5);
            float speed = (float) glfwGetTime() * glm_rad(angle);
            
            glm_rotate(model, speed, (vec3) { 1.0f, 0.3f, 0.5f });

            gogh_shader_set_uniform_mat4(shader_program, "model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
                
        glfwSwapBuffers(window.handle);
        glfwPollEvents();
        
    }

    /* Freeing */
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    /* Closing */
    gogh_window_destroy(&window);

    return 0;
}
