//
// Created by twome on 06/05/2020.
//

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "GameWindow.h"
#include "../model/Field2d.h"
#include "../gl/Loader.h"
#include "../gui/screens/MenuScreen.h"

GameWindow *GameWindow::instance = nullptr;

GameWindow::GameWindow() : fontRenderer(FontRenderer(Loader::load_font("nirmala"))), generationTimer(20),
                           updateTimer(60) {
    field = new Field2d(128, 128);
    field->randomize(4);
    field->remesh();

    camera.set_midpoint(glm::vec2(64, 64));

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

    if (generationTimer.elapsed()) {
        field->tick();      // Next generation
        field->remesh();    // Rebuild mesh

        generationTimer.reset();
    }

    if (updateTimer.elapsed()) {
        handle_input();
        updateTimer.reset();
    }

    fontRenderer.draw("Living cells: " + std::to_string(field->get_living_cells()), glm::vec2(10, 10), 0.5f);

    guiRenderer.draw();
}

void GameWindow::handle_input() {
    bool focused = glfwGetWindowAttrib(glfwHandle, GLFW_FOCUSED) == GLFW_TRUE;
    if (!focused) return;

    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);


    static double mouseXLast, mouseYLast;
    if ((mouseXLast != mouseX || mouseYLast != mouseY)) {

        guiRenderer.on_mouse_move(glm::vec2(mouseX, mouseY));

        if (glfwGetMouseButton(glfwHandle, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && !guiRenderer.is_input_blocked()) {
            glm::vec2 offset = glm::vec2(-(mouseX - mouseXLast) / viewportSize.x * camera.get_size().x,
                                         (mouseY - mouseYLast) / viewportSize.y * camera.get_size().y);
            camera.move_midpoint(offset);
        }
    }

    mouseXLast = mouseX;
    mouseYLast = mouseY;
}

void GameWindow::on_startup() {
    guiRenderer.show_screen(new MenuScreen());
}

void GameWindow::on_scroll(glm::vec2 offset) {
    if (guiRenderer.is_input_blocked())
        return;
    camera.zoom += offset.y * glm::sqrt(camera.zoom.get_value() / 1280.0f);
    camera.zoom.clamp_to(0.001, 0.1);
}

void GameWindow::on_viewport_changed(glm::vec2 newSize) {
    this->viewportSize = newSize;
    guiMatrix = glm::ortho(0.0f, viewportSize.x, viewportSize.y, 0.0f);
    guiRenderer.on_resize();
}

void GameWindow::on_mouse_down() {
    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);
    guiRenderer.on_mouse_down(glm::vec2(mouseX, mouseY));
}

void GameWindow::on_mouse_up() {
    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);
    guiRenderer.on_mouse_up(glm::vec2(mouseX, mouseY));
}

void GameWindow::set_glfw_handle(GLFWwindow *glfwHandle) {
    this->glfwHandle = glfwHandle;
}

GameWindow *GameWindow::get_instance() {
    if (instance == nullptr)
        instance = new GameWindow();
    return instance;
}

glm::mat4 GameWindow::get_gui_matrix() {
    return guiMatrix;
}

glm::vec2 GameWindow::get_viewport_size() {
    return viewportSize;
}

GuiRenderer *GameWindow::get_gui_renderer() {
    return &guiRenderer;
}

FontRenderer *GameWindow::get_font_renderer() {
    return &fontRenderer;
}
