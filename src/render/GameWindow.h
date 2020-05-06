//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_GAMEWINDOW_H
#define GAMEOFLIFE_3D_GAMEWINDOW_H


#include <glm/glm.hpp>
#include "../model/IField.h"
#include "Camera.h"
#include "shaders/BasicShader.h"

class GameWindow {
private:
    static GameWindow *instance;

    IField *field;

    Camera camera;

    BasicShader basicShader;

    GameWindow();
public:
    glm::vec2 viewportSize;

    static GameWindow *get_instance();

    ~GameWindow();

    void draw_frame();
};


#endif //GAMEOFLIFE_3D_GAMEWINDOW_H
