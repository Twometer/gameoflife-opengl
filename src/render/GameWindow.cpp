//
// Created by twome on 06/05/2020.
//

#include "GameWindow.h"
#include "../model/Field2d.h"

GameWindow *GameWindow::instance;

GameWindow::GameWindow() {
    field = new Field2d(64, 64);
    field->randomize(4);
    field->remesh();

    camera.set_midpoint(glm::vec2(32,32));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

GameWindow::~GameWindow() {
    delete field;
}

void GameWindow::draw_frame() {
    glViewport(0, 0, viewportSize.x, viewportSize.y);
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

glm::vec2 GameWindow::get_viewport_size() {
    return viewportSize;
}

void GameWindow::on_scroll(glm::vec2 offset) {

    camera.zoom += offset.y * glm::sqrt(camera.zoom.get_value() / 1280.0f);
    camera.zoom.clamp_to(0.001, 0.1);
}

void GameWindow::on_viewport_changed(glm::vec2 newSize) {
    this->viewportSize = newSize;
}
