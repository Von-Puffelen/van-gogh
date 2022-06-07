#include "window.h"

void _gogh_window_initialize_glew()
{
    glewExperimental = GL_TRUE; // MacOS
    glewInit();
}

void gogh_window_initialize(struct Window *window, int width, int heigth)
{
    if (!glfwInit()) 
        GOGH_EXIT_ON_ERROR("Couldn't initialize GFLW3.");

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window->handle = glfwCreateWindow(
        width, heigth, "A vanGogh application", NULL, NULL);

    if (!window) 
        GOGH_EXIT_ON_ERROR("Couldn't assign GLFW to window");

    glfwMakeContextCurrent(window->handle);
    glfwSetFramebufferSizeCallback(window->handle, gogh_window_on_resize_event);

    _gogh_window_initialize_glew();

}

void gogh_window_on_resize_event(struct Window *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void gogh_window_destroy(struct Window *window)
{
    glfwTerminate();
}
