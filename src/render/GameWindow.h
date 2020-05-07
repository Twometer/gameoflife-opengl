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

    glm::vec2 viewportSize;

    GameWindow();
public:

    static GameWindow *get_instance();

    ~GameWindow();

    void draw_frame();

    glm::vec2 get_viewport_size();

    void on_scroll(glm::vec2 offset);

    void on_viewport_changed(glm::vec2 newSize);
};


#endif //GAMEOFLIFE_3D_GAMEWINDOW_H
