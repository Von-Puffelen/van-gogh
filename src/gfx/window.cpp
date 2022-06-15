#include "GOGH/vangogh.hpp"
#include "gfx/window.hpp"

void Window::create(const char *name, i16vec2 size)
{
    if (!glfwInit()) {
        GOGH_EXIT_ON_ERROR("Couldn't initialize GFLW3.");
    }

    /* GLFW configurations */
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->handle = glfwCreateWindow(
        size.x, size.y, "A vanGogh application", NULL, NULL);

    if (!this->handle) 
        GOGH_ERROR("Couldn't assign GLFW to window");

    glfwMakeContextCurrent(this->handle);
    glewExperimental = GL_TRUE;
    glewInit();

    /* OpenGL features */
    glEnable(GL_DEPTH_TEST); // Must be after glfwMakeContextCurrent.
}

void Window::destroy()
{
    glfwTerminate();
}
