#include "GOGH/config.h"

#include "gfx/gfx.h"
#include "gfx/shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb-image.h"

#include <cglm/cglm.h>

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

int main(int argc, char** argv)
{
    /* Initalization */
    if (!glfwInit()) 
        GOGH_EXIT_ON_ERROR("Couldn't initialize GFLW3.");

    // Window properties
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow *window = glfwCreateWindow(
        1280, 720, "A vanGogh application", NULL, NULL);

    if (!window) 
        GOGH_EXIT_ON_ERROR("Couldn't assign GLFW to window")

    glfwMakeContextCurrent(window);
        
    // Initialize GLEW to experimental (macOS)
    glewExperimental = GL_TRUE;
    glewInit();

    /* OpenGL functionality */
    glEnable(GL_DEPTH_TEST);

    /* Shaders */
    unsigned int shader_program;
    shader_program = gogh_shader_create(
        "./res/vertex_shaders/vertex_shader.glsl",
        "./res/fragment_shaders/fragment_shader.glsl");
    
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
    int width, height, channels;
    unsigned char *data = stbi_load(
        "./res/textures/prototype-dark.png", &width, &height, &channels, 0);

    if (!data)
        GOGH_EXIT_ON_ERROR("Couldn't load the texture image.");

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Texture settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

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
        
    /* Rendering */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Textures */
        glBindTexture(GL_TEXTURE_2D, texture);

        /* Shaders */
        gogh_shader_bind(&shader_program);

        /* Transformations */
        mat4 view;
        glm_mat4_identity(view);
        
        glm_translate_to(view, (vec3){ 0.0f, 0.0f, -3.0f}, view);

        mat4 projection;
        glm_mat4_identity(projection);

        glm_perspective(glm_rad(45.0f), 1280 / 720, 0.1f, 100.0f, projection);
        
        unsigned int view_location = glGetUniformLocation(shader_program, "view");
        glUniformMatrix4fv(view_location, 1, GL_FALSE, (float*) view);

        unsigned int projection_location = glGetUniformLocation(shader_program, "projection");
        glUniformMatrix4fv(projection_location, 1, GL_FALSE, (float*) projection);
                
        // Wireframe mode
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Use if using EBO
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        for (int i = 0; i < 10; i++) {
            mat4 model;
            glm_mat4_identity(model);
            glm_translate(model, cube_positions[i]);

            float angle = 20.0f * (i + 0.5);
            glm_rotate(model, (float) glfwGetTime() * glm_rad(angle), (vec3) { 1.0f, 0.3f, 0.5f });
            unsigned int model_location = glGetUniformLocation(shader_program, "model");
            glUniformMatrix4fv(model_location, 1, GL_FALSE, (float*) model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
                
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Freeing */
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    /* Closing */
    glfwTerminate();

    return 0;
}
