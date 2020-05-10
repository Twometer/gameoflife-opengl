//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_CAMERA_H
#define GAMEOFLIFE_OPENGL_CAMERA_H

#include <glm/glm.hpp>
#include "../util/AnimatedVec2.h"

class Camera {
private:
    glm::mat4 projectionMatrix;

    AnimatedVec2 midpoint = glm::vec2(0, 0);

    glm::vec2 sizeInWorld;

public:
    Animated zoom = 0.01f;

    Camera();

    void update();

    glm::mat4 get_matrix();

    void set_midpoint(glm::vec2 midpoint);

    void move_midpoint(glm::vec2 offset);

    glm::vec2 get_size();

};


#endif //GAMEOFLIFE_OPENGL_CAMERA_H
