//
// Created by twome on 06/05/2020.
//

#include <cstdlib>
#include "Field2d.h"
#include "../gl/MeshBuilder.h"

void Field2d::tick() {
    buffer->swap();
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = buffer->get_back()[get_index(i, j)];
            int neighbors = count_neighbors(buffer->get_back(), i, j);

            if (alive && neighbors < 2)
                buffer->get_front()[get_index(i, j)] = false;    // Underpopulation
            else if (alive && neighbors < 4)
                buffer->get_front()[get_index(i, j)] = true;     // Stays alive
            else if (alive && neighbors > 3)
                buffer->get_front()[get_index(i, j)] = false;    // Overpopulation
            else if (!alive && neighbors == 3)
                buffer->get_front()[get_index(i, j)] = true;    // Reproduction
        }
    }
}

void Field2d::randomize() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            buffer->get_front()[get_index(i, j)] = rand() % 2;
        }
    }
}

Field2d::Field2d(int width, int height) {
    this->width = width;
    this->height = height;
    this->vao = new Vao(2);
    buffer = new DoubleBuffer<bool>(width * height);
}

Field2d::~Field2d() {
    delete buffer;
    delete vao;
}

int Field2d::get_index(int x, int y) {
    return (y * width) + x;
}

int Field2d::count_neighbors(bool *buf, int x, int y) {
    int neighbors = 0;

    for (int xo = -1; xo <= 1; xo++) {
        for (int yo = -1; yo <= 1; yo++) {
            if (xo == 0 && yo == 0)
                continue;

            int nx = x + xo;
            int ny = y + yo;
            if (buf[get_index(nx, ny)])
                neighbors++;
        }
    }
    return neighbors;
}

void Field2d::remesh() {
    MeshBuilder builder;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = buffer->get_front()[get_index(i, j)];

            if (alive) {
                builder.push_rectangle(i, j, 1, 1, glm::vec3(1.0f, 1.0f, 1.0f));
            }

        }
    }

    vao->set_data(builder.get_vertices(), builder.get_vertex_count(), builder.get_colors(), builder.get_color_count());
}


