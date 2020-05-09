//
// Created by twome on 09/05/2020.
//

#include <iostream>
#include "Button.h"
#include "../../render/GameWindow.h"

Button::Button(const std::string &id) : IComponent(id) {
}

void Button::draw(Graphics &graphics) {
    graphics.begin();
    graphics.push_rectangle(position.x, position.y, size.x, size.y, glm::vec3(0.1804, 0.8, 0.4431));
    graphics.end();

    graphics.draw_centered_text(text, position + (size * 0.5f), fontSize);
}

void Button::layout() {
    minimumSize = GameWindow::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
}

void Button::set_text(std::string text) {
    this->text = text;
}

void Button::set_font_size(float fontSize) {
    this->fontSize = fontSize;
}

void Button::on_click(glm::vec2 position) {
    std::cout << "Button " << id << " was clicked!" << std::endl;
}
