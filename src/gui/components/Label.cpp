//
// Created by twome on 08/05/2020.
//

#include "Label.h"

#include <utility>
#include "../../render/GameWindow.h"

void Label::draw() {
    GameWindow::get_instance()->get_font_renderer()->draw(text, glm::vec2(), fontSize);
}

void Label::set_text(std::string text) {
    this->text = std::move(text);
}

void Label::set_font_size(float fontSize) {
    this->fontSize = fontSize;
}
