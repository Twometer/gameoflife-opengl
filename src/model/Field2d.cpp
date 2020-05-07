//
// Created by twome on 06/05/2020.
//

#include <cstdlib>
#include <iostream>
#include "Field2d.h"
#include "../gl/MeshBuilder.h"
#include "../util/Logger.h"

void Field2d::tick() {
    // Our front buffer contains the field that is currently visible on-screen
    // On the back buffer we prepare the new field that contains the next generation

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int index = get_index(i ,j);

            bool alive = buffer->get_front()[index];
            int neighbors = count_neighbors(i, j);

            if (alive && neighbors < 2)
                buffer->get_back()[index] = false;   // Underpopulation
            else if (alive && neighbors < 4)
                buffer->get_back()[index] = true;    // Stays alive
            else if (alive && neighbors > 3)
                buffer->get_back()[index] = false;   // Overpopulation
            else if (!alive && neighbors == 3)
                buffer->get_back()[index] = true;    // Reproduction
            else
                buffer->get_back()[index] = alive;   // Stays the same
        }
    }

    // After we built the next generation, we swap the buffers
    buffer->swap();
}

void Field2d::randomize(int mod) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            buffer->get_front()[get_index(i, j)] = (rand() % mod) == 0;
        }
    }
}

Field2d::Field2d(int width, int height) {
    this->width = width;
    this->height = height;
    this->vao = new Vao(2);
    buffer = new DoubleBuffer<bool>(width * height);
    meshBuilder = new MeshBuilder();
}

Field2d::~Field2d() {
    delete meshBuilder;
    delete buffer;
    delete vao;
}

int Field2d::get_index(int x, int y) {
    return (y * width) + x;
}

int Field2d::count_neighbors(int x, int y) {
    int neighbors = 0;

    // Iterate all Moore neighbors of the current cell on the front buffer
    for (int xo = -1; xo <= 1; xo++) {
        for (int yo = -1; yo <= 1; yo++) {
            if (xo == 0 && yo == 0)
                continue;

            int nx = x + xo;
            int ny = y + yo;

            // Ignore out-of-bounds neighbors
            if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;

            if (buffer->get_front()[get_index(nx, ny)])
                neighbors++;
        }
    }
    return neighbors;
}

void Field2d::remesh() {
    meshBuilder->clear();

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = buffer->get_front()[get_index(i, j)];

            if (alive) {
                // Some nice color theme
                meshBuilder->push_rectangle(i, j, 1, 1, glm::vec3(i / (float)width, j / (float)height, 1.0f));
            }

        }
    }

    vao->set_data(meshBuilder->get_vertices(), meshBuilder->get_vertex_count(), meshBuilder->get_colors(),
                  meshBuilder->get_color_count());
}


