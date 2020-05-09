//
// Created by twome on 06/05/2020.
//

#include "MeshBuilder.h"

void MeshBuilder::push_rectangle(float x, float y, float width, float height, glm::vec3 color) {
    push_vertex(x, y);
    push_vertex(x + width, y);
    push_vertex(x, y + height);

    push_vertex(x, y + height);
    push_vertex(x + width, y + height);
    push_vertex(x + width, y);

    push_color(color.r, color.g, color.b);
    push_color(color.r, color.g, color.b);
    push_color(color.r, color.g, color.b);
    push_color(color.r, color.g, color.b);
    push_color(color.r, color.g, color.b);
    push_color(color.r, color.g, color.b);
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

void MeshBuilder::clear() {
    vertices.clear();
    colors.clear();
}

void MeshBuilder::push_vertex(float x, float y) {
    vertices.push_back(x);
    vertices.push_back(y);
}

void MeshBuilder::push_color(float r, float g, float b) {
    colors.push_back(r);
    colors.push_back(g);
    colors.push_back(b);
}