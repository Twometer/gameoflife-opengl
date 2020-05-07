//
// Created by twome on 06/05/2020.
//

#include "MeshBuilder.h"

void MeshBuilder::push_rectangle(float x, float y, float width, float height, glm::vec3 color) {
    vertices.push_back(x);
    vertices.push_back(y);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);
    vertices.push_back(x + width);
    vertices.push_back(y);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);
    vertices.push_back(x);
    vertices.push_back(y + height);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);

    vertices.push_back(x);
    vertices.push_back(y + height);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);
    vertices.push_back(x + width);
    vertices.push_back(y + height);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);
    vertices.push_back(x + width);
    vertices.push_back(y);
    colors.push_back(color.x);
    colors.push_back(color.y);
    colors.push_back(color.z);
}

float *MeshBuilder::get_vertices() {
    return &vertices[0];
}

int MeshBuilder::get_vertex_count() {
    return vertices.size();
}

float *MeshBuilder::get_colors() {
    return &colors[0];
}

int MeshBuilder::get_color_count() {
    return colors.size();
}
