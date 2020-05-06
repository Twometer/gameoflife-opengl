//
// Created by twome on 06/05/2020.
//

#include <cstdlib>
#include "Field2d.h"

void Field2d::tick() {
    buffer->swap();
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = buffer->get_back()[getIndex(i, j)];
            int neighbors = countNeighbors(buffer->get_back(), i, j);

            if (alive && neighbors < 2)
                buffer->get_front()[getIndex(i, j)] = false;    // Underpopulation
            else if (alive && neighbors < 4)
                buffer->get_front()[getIndex(i, j)] = true;     // Stays alive
            else if (alive && neighbors > 3)
                buffer->get_front()[getIndex(i, j)] = false;    // Overpopulation
            else if (!alive && neighbors == 3)
                buffer->get_front()[getIndex(i, j)] = true;    // Reproduction
        }
    }
}

void Field2d::randomize() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            buffer->get_front()[getIndex(i, j)] = rand() % 2;
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

int Field2d::getIndex(int x, int y) {
    return (y * width) + x;
}

int Field2d::countNeighbors(bool *buf, int x, int y) {
    int neighbors = 0;

    for (int xo = -1; xo <= 1; xo++) {
        for (int yo = -1; yo <= 1; yo++) {
            if (xo == 0 && yo == 0)
                continue;

            int nx = x + xo;
            int ny = y + yo;
            if (buf[getIndex(nx, ny)])
                neighbors++;
        }
    }
    return neighbors;
}


