//
// Created by twome on 09/05/2020.
//

#include <iostream>
#include "TextBox.h"
#include "../../render/GameWindow.h"

TextBox::TextBox(const std::string &id) : ITextComponent(id) {
}

void TextBox::draw(Graphics &graphics) {
    graphics.begin();
    graphics.push_rectangle(position.x, position.y, size.x, size.y, borderColor.get_value());
    graphics.push_rectangle(position.x + 1, position.y + 1, size.x - 2, size.y - 2, glm::vec3(0.1529, 0.1922, 0.2118));
    graphics.end();

    if (!placeholder.empty() && text.empty())
        graphics.draw_centered_text(placeholder, position + size * .5f, fontSize, glm::vec4(0.498, 0.549, 0.5529, 0.8f));

    if (!text.empty())
        graphics.draw_centered_text(text, position + size * .5f, fontSize, glm::vec4(0.7412, 0.7647, 0.7804, 1.0f));

    borderColor.update();
}

void TextBox::layout() {
    minimumSize = GameWindow::get_instance()->get_font_renderer()->get_bounds("WW", fontSize);
}

void TextBox::on_got_focus() {
    IComponent::on_got_focus();
    borderColor = glm::vec3(0.0, 0.6588, 1.0);
}

void TextBox::on_lost_focus() {
    IComponent::on_lost_focus();
    borderColor = glm::vec3(0.2157, 0.2549, 0.2745);
}

void TextBox::set_placeholder(const std::string &placeholder) {
    this->placeholder = placeholder;
}

Cursor TextBox::get_cursor() {
    return Cursor::IBEAM;
}
