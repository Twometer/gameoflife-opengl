//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_CAMERA_H
#define GAMEOFLIFE_3D_CAMERA_H

#include <glm/glm.hpp>
#include "../util/Animated.h"

class Camera {
private:
    glm::mat4 projectionMatrix;

    glm::vec2 midpoint;

    glm::vec2 sizeInWorld;

public:
    Animated zoom = 0.04f;

    Camera();

    void update();

    glm::mat4 get_matrix();

    void set_midpoint(glm::vec2 midpoint);

    void move_midpoint(glm::vec2 offset);

    glm::vec2 get_size();

};


#endif //GAMEOFLIFE_3D_CAMERA_H
