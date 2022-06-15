#include "GOGH/vangogh.hpp"
#include "state.hpp"

#include "gfx/gfx.hpp"
#include "gfx/shader.hpp"
#include "gfx/texture.hpp"

int main(UNUSED int argc, UNUSED char *argv[])
{
    std::unique_ptr<State> state(new State());
    state->window = new Window(); 
    state->camera = new Camera();
    
    state->window->create(
        "A vanGogh application", { 1280, 720 } );

    float vertices[] = {
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        
       -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    glm::vec3 mesh_positions[] = {
        glm::vec3(  0.0f,  0.0f,  0.0f ), // Middle
        glm::vec3(  0.0f,  1.7f,  0.0f ), // Top
        glm::vec3(  0.0f, -1.7f,  0.0f ), // Bottom 
        glm::vec3(  1.7f,  0.0f,  0.0f ), // Right
        glm::vec3( -1.7f,  0.0f,  0.0f ), // Left
        glm::vec3( -1.7f,  1.7f,  0.0f ), // Top Left
        glm::vec3(  1.7f,  1.7f,  0.0f ), // Top Right
        glm::vec3(  1.7f, -1.7f,  0.0f ), // Bottom Right
        glm::vec3( -1.7f, -1.7f,  0.0f ), // Bottom Left 

        glm::vec3(  0.0f,  0.0f, -1.7f ), // Middle
        glm::vec3(  0.0f,  1.7f, -1.7f ), // Top
        glm::vec3(  0.0f, -1.7f, -1.7f ), // Bottom 
        glm::vec3(  1.7f,  0.0f, -1.7f ), // Right
        glm::vec3( -1.7f,  0.0f, -1.7f ), // Left
        glm::vec3( -1.7f,  1.7f, -1.7f ), // Top Left
        glm::vec3(  1.7f,  1.7f, -1.7f ), // Top Right
        glm::vec3(  1.7f, -1.7f, -1.7f ), // Bottom Right
        glm::vec3( -1.7f, -1.7f, -1.7f ), // Bottom Left 

        glm::vec3(  0.0f,  0.0f,  1.7f ), // Middle
        glm::vec3(  0.0f,  1.7f,  1.7f ), // Top
        glm::vec3(  0.0f, -1.7f,  1.7f ), // Bottom 
        glm::vec3(  1.7f,  0.0f,  1.7f ), // Right
        glm::vec3( -1.7f,  0.0f,  1.7f ), // Left
        glm::vec3( -1.7f,  1.7f,  1.7f ), // Top Left
        glm::vec3(  1.7f,  1.7f,  1.7f ), // Top Right
        glm::vec3(  1.7f, -1.7f,  1.7f ), // Bottom Right
        glm::vec3( -1.7f, -1.7f,  1.7f ), // Bottom Left 
    };    

    /* Shader */
    std::unique_ptr<Shader> shader_program(new Shader);
    shader_program->create(
        "./resources/vertex_shaders/vertex_shader.glsl",
        "./resources/fragment_shaders/fragment_shader.glsl");    

    /* Texture */
    std::unique_ptr<Texture> texture(new Texture);
    texture->create(
        "./resources/textures/prototype-dark.png");

    /* Vertex information storage */
    unsigned int vbo, vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    // Texture attribute
    glVertexAttribPointer(
        1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    /* Rendering */
    while(!glfwWindowShouldClose(state->window->handle)) {

        glClearColor(GOGH_COLOUR(242), GOGH_COLOUR(242), GOGH_COLOUR(247), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Texture */
        texture->use();

        /* Shaders */
        shader_program->use();

        shader_program->setShaderUniform("view", state->camera->view);
        shader_program->setShaderUniform("projection", state->camera->projection);

        /* Rendering */
        glBindVertexArray(vao);

        // Meshes
        for (unsigned int i = 0; i < 27; i++) {
            glm::mat4 model_space = glm::mat4(1.0f);
            model_space = glm::translate(model_space, mesh_positions[i]);

            float angle = 20.0f * (i + 2.5);
            model_space =
                glm::rotate(model_space, glm::radians(angle), { 1.0f, 0.3f, 0.5f });

            shader_program->setShaderUniform("model", model_space);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        /* Camera */
        const float radius = 10.0f;
        float camera_pos_x = sin(glfwGetTime()) * radius;
        float camera_pos_y = (cos(glfwGetTime()) * radius) / 2;
        float camera_pos_z = cos(glfwGetTime()) * radius;
        state->camera->update(camera_pos_x, camera_pos_y, camera_pos_z);

        glfwSwapBuffers(state->window->handle);
        glfwPollEvents();
    }

    return 0;
}
