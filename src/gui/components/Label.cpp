//
// Created by twome on 08/05/2020.
//

#include "Label.h"

#include "../../render/GameWindow.h"

Label::Label(const std::string &id) : IComponent(id) {
}

void Label::draw(glm::vec2 origin) {
    GameWindow::get_instance()->get_font_renderer()->draw(text, position + origin, fontSize);
}

void Label::layout() {
    minimumSize = GameWindow::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
}

void Label::set_text(std::string text) {
    this->text = std::move(text);
}

void Label::set_font_size(float fontSize) {
    this->fontSize = fontSize;
}
