//
// Created by twome on 08/05/2020.
//

#include "GuiRenderer.h"
#include "../render/GameWindow.h"

void GuiRenderer::show_screen(IScreen *screen) {
    this->currentScreen = screen;
    this->currentScreen->layout();
}

void GuiRenderer::draw() {
    guiShader.bind();
    guiShader.set_camera_matrix(GameWindow::get_instance()->get_gui_matrix());
    if (currentScreen != nullptr)
        this->currentScreen->draw(glm::vec2(0, 0));
}

void GuiRenderer::on_resize() {
    if (currentScreen != nullptr)
        this->currentScreen->layout();
}
