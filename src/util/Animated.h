//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_ANIMATED_H
#define GAMEOFLIFE_3D_ANIMATED_H

#include <glm/glm.hpp>

class Animated {
private:
    float srcValue;
    float curValue;
    float dstValue;

    float progress;

public:
    Animated(float value) {
        this->srcValue = value;
        this->dstValue = value;
    }

    void set_value(float value) {
        dstValue = value;
    }

    float get_value() {
        return curValue;
    }

    void update() {
        if (progress < 1.0f)
            progress += 0.1f;
        curValue = srcValue + (dstValue - srcValue) * glm::sin(progress * M_PI_2);
    }

    void clamp_to(float min, float max) {
        dstValue = glm::clamp(dstValue, min, max);
    }

private:
    void reset() {
        progress = 0.0f;
        srcValue = curValue;
    }

};

#endif //GAMEOFLIFE_3D_ANIMATED_H