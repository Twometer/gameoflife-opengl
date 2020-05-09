//
// Created by twome on 09/05/2020.
//

#include "Graphics.h"
#include "../render/GameWindow.h"

Graphics::Graphics(Vao *vao, MeshBuilder *builder, BasicShader *guiShader, const glm::vec2 &origin) : vao(vao),
                                                                                                  builder(builder),
                                                                                                  guiShader(guiShader),
                                                                                                  origin(origin) {
}

void Graphics::push_rectangle(float x, float y, float width, float height, glm::vec3 color) {
    builder->push_rectangle(x + origin.x, y + origin.y, width, height, color);
}

Graphics Graphics::create_offset(glm::vec2 offset) {
    return {vao, builder, guiShader, origin + offset};
}

void Graphics::draw_text(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
    GameWindow::get_instance()->get_font_renderer()->draw(text, position + origin, size, color);
}

void Graphics::draw_centered_text(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
    GameWindow::get_instance()->get_font_renderer()->draw_centered(text, position + origin, size, color);
}

void Graphics::begin() {
    builder->clear();
}

void Graphics::end() {
    guiShader->bind();
    guiShader->set_camera_matrix(GameWindow::get_instance()->get_gui_matrix());
    vao->set_data(builder->get_vertices(), builder->get_vertex_count(), builder->get_colors(),
                  builder->get_color_count());
    vao->render();
}


