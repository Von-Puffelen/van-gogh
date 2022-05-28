#include <GL/glew.h>

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "GOGH/config.h"
#include "gfx/shader.h"

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
        gogh_screen_width, gogh_screen_height, gogh_name, NULL, NULL);

    if (!window) 
        GOGH_EXIT_ON_ERROR("Couldn't assign GLFW to window")

    glfwMakeContextCurrent(window);
        
    // Initialize GLEW to experimental (macOS)
    glewExperimental = GL_TRUE;
    glewInit();

    /* Graphics pipelining */
    unsigned int shader_program;
    shader_program = gogh_shader_create(
        "./res/vertex_shaders/vertex_shader.glsl",
        "./res/fragment_shaders/fragment_shader.glsl");
    
    // Adding the vertex data
    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        0.0f,  0.8f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
    };   
    
    unsigned int vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Colour attribute
    glVertexAttribPointer(
        1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    /* Rendering */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Triangle */
        glUseProgram(shader_program);
        glBindVertexArray(vao);
        
        // Wireframe mode
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Use if using EBO
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Closing */
    glfwTerminate();

    return 0;
}
