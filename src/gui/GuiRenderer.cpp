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
        this->currentScreen->draw(graphics);
}

void GuiRenderer::on_resize() {
    if (currentScreen != nullptr)
        this->currentScreen->layout();

}

void GuiRenderer::on_mouse_down(glm::vec2 position) {
    if (currentScreen != nullptr)
        currentScreen->on_mouse_down(position);
}

void GuiRenderer::on_mouse_up(glm::vec2 position) {
    if (currentScreen != nullptr)
        currentScreen->on_mouse_up(position);
}

void GuiRenderer::on_mouse_move(glm::vec2 position) {
    if (currentScreen != nullptr)
        currentScreen->on_mouse_move(position);
}

bool GuiRenderer::is_input_blocked() {
    return currentScreen != nullptr && currentScreen->blocks_game_inputs();
}
