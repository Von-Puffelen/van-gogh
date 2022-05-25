#include <GL/glew.h>

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "GOGH/config.h"

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

    /* Rendering */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    /* Closing */
    glfwTerminate();

    return 0;
}
