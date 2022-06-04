#include "GOGH/config.h"

#include "gfx/gfx.h"
#include "gfx/shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb-image.h"

#include <cglm/cglm.h>

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

    /* Shaders */
    unsigned int shader_program;
    shader_program = gogh_shader_create(
        "./res/vertex_shaders/vertex_shader.glsl",
        "./res/fragment_shaders/fragment_shader.glsl");
    
    // Adding the vertex data
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
    
    unsigned int vbo, vao, ebo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    
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
        
    /* Rendering */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Triangle */
        glBindTexture(GL_TEXTURE_2D, texture);
        gogh_shader_bind(&shader_program);
        glBindVertexArray(vao);

        /* Transformation */
        mat4 trans = {{1.0f, 0.0f, 0.0f, 0.0f},
                      {0.0f, 1.0f, 0.0f, 0.0f},
                      {0.0f, 0.0f, 1.0f, 0.0f},
                      {0.0f, 0.0f, 0.0f, 1.0f}};

        glm_translate_to(trans, (vec3){ 0.5f, -0.5f, 0.0f}, trans);
        glm_rotate(trans, (float)glfwGetTime(), (vec3){0.0f, 0.0f, 1.0f});

        unsigned int location = glGetUniformLocation(shader_program, "transform");
        glUniformMatrix4fv(location, 1, GL_FALSE, (float*) trans);
        
        // Wireframe mode
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Use if using EBO
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Freeing */
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    /* Closing */
    glfwTerminate();

    return 0;
}
