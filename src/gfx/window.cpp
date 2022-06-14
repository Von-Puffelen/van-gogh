#include "GOGH/vangogh.hpp"
#include "gfx/window.hpp"

void Window::create()
{
    if (!glfwInit()) {
        GOGH_EXIT_ON_ERROR("Couldn't initialize GFLW3.");
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->handle = glfwCreateWindow(
        1280, 720, "A vanGogh application", NULL, NULL);

    if (!this->handle) 
        GOGH_ERROR("Couldn't assign GLFW to window");

    glfwMakeContextCurrent(this->handle);
}

void Window::destroy()
{
    glfwTerminate();
}
