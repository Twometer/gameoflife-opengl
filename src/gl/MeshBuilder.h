//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_MESHBUILDER_H
#define GAMEOFLIFE_OPENGL_MESHBUILDER_H


#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class MeshBuilder {
private:
    std::vector<float> vertices;

    std::vector<float> colors;

    void push_vertex(float x, float y);

    void push_color(float r, float g, float b);

public:
    void push_rectangle(float x, float y, float width, float height, glm::vec3 color);

    float *get_vertices();

    int get_vertex_count() const;

    float *get_colors();

    int get_color_count() const;

    void clear();

};


#endif //GAMEOFLIFE_OPENGL_MESHBUILDER_H
