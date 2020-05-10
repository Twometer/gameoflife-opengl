//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ANIMATEDCOLOR_H
#define GAMEOFLIFE_OPENGL_ANIMATEDCOLOR_H

#include "Animated.h"

class AnimatedColor {
private:
    Animated r;
    Animated g;
    Animated b;

public:
    AnimatedColor(glm::vec3 defaultValue) : r(defaultValue.r), g(defaultValue.g), b(defaultValue.b) {

    }

    AnimatedColor &operator=(const glm::vec3 value) {
        r = value.r;
        g = value.g;
        b = value.b;
        return *this;
    }

    glm::vec3 get_value() const {
        return glm::vec3(r.get_value(), g.get_value(), b.get_value());
    }

    void update() {
        r.update();
        g.update();
        b.update();
    }

};

#endif //GAMEOFLIFE_OPENGL_ANIMATEDCOLOR_H
