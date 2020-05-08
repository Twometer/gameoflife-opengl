//
// Created by twome on 09/05/2020.
//

#include "Button.h"
#include "../../render/GameWindow.h"

Button::Button(const std::string &id) : IComponent(id) {
}

void Button::draw(glm::vec2 origin) {
    bind_gui_shader();
    meshBuilder.clear();
    meshBuilder.set_origin(origin);
    meshBuilder.push_rectangle(position.x, position.y, size.x, size.y, glm::vec3(0.1804, 0.8, 0.4431));

    vao.set_data(meshBuilder.get_vertices(), meshBuilder.get_vertex_count(), meshBuilder.get_colors(),
                 meshBuilder.get_color_count());
    vao.render();

    GameWindow::get_instance()->get_font_renderer()->draw_centered(text, position + origin + (size * 0.5f), fontSize);
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
