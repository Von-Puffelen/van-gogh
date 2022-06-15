#include "camera.hpp"

void Camera::update(float x, float y, float z)
{
    this->view =
        glm::lookAt(
            glm::vec3(   x,    y,    z), 
  		    glm::vec3(0.0f, 0.0f, 0.0f), 
  		    glm::vec3(0.0f, 1.0f, 0.0f));
}
