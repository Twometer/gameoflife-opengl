//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TIMER_H
#define GAMEOFLIFE_OPENGL_TIMER_H

#include <GLFW/glfw3.h>

class Timer {
private:
    double delay;

    double lastTick = 0;

    bool paused = false;

public:
    explicit Timer(int tps) : delay(1.0 / tps) {
    }

    void reset() {
        lastTick = glfwGetTime();
    }

    bool elapsed() const {
        return !paused && (glfwGetTime() - lastTick) > delay;
    }

    void set_tps(int tps) {
        delay = 1.0 / tps;
    }

    void pause() {
        paused = true;
    }

    void resume() {
        paused = false;
    }

};

#endif //GAMEOFLIFE_OPENGL_TIMER_H
