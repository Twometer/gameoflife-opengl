//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_3D_TIMER_H
#define GAMEOFLIFE_3D_TIMER_H

#include <GLFW/glfw3.h>

class Timer {
private:
    double delay;

    double lastTick;

public:
    explicit Timer(int tps)
            : delay(1.0 / tps), lastTick(0) {
    }

    void reset() {
        lastTick = glfwGetTime();
    }

    bool elapsed() {
        return (glfwGetTime() - lastTick) > delay;
    }

    void set_tps(int tps) {
        delay = 1.0 / tps;
    }

};

#endif //GAMEOFLIFE_3D_TIMER_H
