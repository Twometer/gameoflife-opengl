//
// Created by twome on 06/05/2020.
//

#include "GameWindow.h"
#include "../model/Field2d.h"


GameWindow::GameWindow() {
    field = new Field2d(16, 16);
}

GameWindow::~GameWindow() {
    delete field;
}

void GameWindow::draw_frame() {
    camera.update();
}

GameWindow *GameWindow::get_instance() {
    if (instance == nullptr)
        instance = new GameWindow();
    return instance;
}
