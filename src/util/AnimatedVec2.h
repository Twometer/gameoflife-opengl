//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ANIMATEDVEC2_H
#define GAMEOFLIFE_OPENGL_ANIMATEDVEC2_H

#include "Animated.h"

class AnimatedVec2 {
private:
    Animated x;
    Animated y;

public:
    AnimatedVec2(glm::vec2 defaultValue) : x(defaultValue.x), y(defaultValue.y) {
    }

    AnimatedVec2 &operator=(const glm::vec2 value) {
        x = value.x;
        y = value.y;
        return *this;
    }

    AnimatedVec2 &operator+=(const glm::vec2 value) {
        x += value.x;
        y += value.y;
        return *this;
    }

    glm::vec2 get_value() {
        return glm::vec2(x.get_value(), y.get_value());
    }

    void update() {
        x.update();
        y.update();
    }

};

#endif //GAMEOFLIFE_OPENGL_ANIMATEDVEC2_H
