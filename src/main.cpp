#include "GOGH/vangogh.hpp"
#include "state.hpp"

#include <memory>

int main(UNUSED int argc, UNUSED char **argv)
{
    State *state = new State();
    state->window = new Window();
    state->window->create();

    while(!glfwWindowShouldClose(state->window->handle)) {
        glfwSwapBuffers(state->window->handle);
        glfwPollEvents();
    }

    state->window->destroy();

    return 0;
}
