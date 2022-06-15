#pragma once

#include "gfx/gfx.hpp"
#include "util/math.hpp"

struct Camera {

    glm::mat4 view;
    glm::mat4 projection;

    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 target;

    Camera() {
        this->view = glm::mat4(1.0f);
        this->projection = glm::mat4(1.0f);

        this->position = glm::vec3(0.0f, 0.0f, 1.0f);

        this->projection =
            glm::perspective(
                glm::radians(75.0f), (float) 1280 / (float) 720, 0.1f, 100.0f ); 
    }

    void update(float x, float y, float z);
    
};
