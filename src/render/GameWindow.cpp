//
// Created by twome on 06/05/2020.
//

#include "GameWindow.h"
#include "../model/Field2d.h"

GameWindow *GameWindow::instance;

GameWindow::GameWindow() {
    field = new Field2d(16, 16);
    field->randomize();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

GameWindow::~GameWindow() {
    delete field;
}

void GameWindow::draw_frame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.update();

    basicShader.bind();
    basicShader.set_camera_matrix(camera.get_matrix());
    field->render();
}

GameWindow *GameWindow::get_instance() {
    if (instance == nullptr)
        instance = new GameWindow();
    return instance;
}
