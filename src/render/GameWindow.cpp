//
// Created by twome on 06/05/2020.
//

#include <iostream>
#include "GameWindow.h"
#include "../model/Field2d.h"

GameWindow *GameWindow::instance;

GameWindow::GameWindow() {
    field = new Field2d(64, 64);
    field->randomize(4);
    field->remesh();

    camera.set_midpoint(glm::vec2(32, 32));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

GameWindow::~GameWindow() {
    delete field;
}

int ctr = 0;
int lastliving = 0;
int stablectr = 0;

void GameWindow::draw_frame() {
    glViewport(0, 0, viewportSize.x, viewportSize.y);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.update();

    basicShader.bind();
    basicShader.set_camera_matrix(camera.get_matrix());
    field->render();

    ctr++;
    if (ctr % 12 == 0) {
        field->tick();
        field->remesh();

        if (field->get_living_cells() != lastliving) {
            std::cout << "Living cells: " << field->get_living_cells() << std::endl;
            stablectr = 0;
        } else {
            stablectr++;
            if (stablectr > 5)
                std::cout << "Reached stable configuration at cell count: " << field->get_living_cells() << std::endl;
            else
                std::cout << "Living cells: " << field->get_living_cells() << std::endl;
        }


        lastliving = field->get_living_cells();
    }


    handle_input();
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

void GameWindow::handle_input() {
    bool focused = glfwGetWindowAttrib(glfwHandle, GLFW_FOCUSED) == GLFW_TRUE;
    if (!focused) return;

    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);


    static double mouseXLast, mouseYLast;
    if ((mouseXLast != mouseX || mouseYLast != mouseY) &&
        glfwGetMouseButton(glfwHandle, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
        glm::vec2 offset = glm::vec2(-(mouseX - mouseXLast) / viewportSize.x * camera.get_size().x,
                                     (mouseY - mouseYLast) / viewportSize.y * camera.get_size().y);
        camera.move_midpoint(offset);
    }

    mouseXLast = mouseX;
    mouseYLast = mouseY;
}

void GameWindow::set_glfw_handle(GLFWwindow *glfwHandle) {
    this->glfwHandle = glfwHandle;
}
