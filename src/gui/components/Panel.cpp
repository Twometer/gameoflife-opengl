//
// Created by twome on 08/05/2020.
//

#include "Panel.h"

void Panel::draw(glm::vec2 origin) {
    bind_gui_shader();
    meshBuilder.clear();
    meshBuilder.set_origin(origin);
    meshBuilder.push_rectangle(position.x, position.y, size.x, size.y, glm::vec3(0.1843, 0.2218, 0.2431));
    meshBuilder.push_rectangle(position.x, position.y, size.x, 2, glm::vec3(0.0, 0.6588, 1.0));

    vao.set_data(meshBuilder.get_vertices(), meshBuilder.get_vertex_count(), meshBuilder.get_colors(), meshBuilder.get_color_count());
    vao.render();

    IContainer::draw(origin);
}

Panel::Panel(const std::string &id) : IContainer(id) {

}
