//
// Created by twome on 08/05/2020.
//

#include "GuiRenderer.h"

void GuiRenderer::show_screen(IScreen *screen) {
    this->currentScreen = screen;
    this->currentScreen->layout();
}

void GuiRenderer::draw() {
    if (currentScreen != nullptr)
        this->currentScreen->draw();
}

void GuiRenderer::on_resize() {
    if (currentScreen != nullptr)
        this->currentScreen->layout();
}
