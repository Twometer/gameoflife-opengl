//
// Created by twome on 10/05/2020.
//

#include "Field.h"

Field::Field(int width, int height) : width(width), height(height) {
    vao = new Vao(2);
    buffer = new DoubleBuffer<bool>(width * height);
    meshBuilder = new MeshBuilder();
}

Field::~Field() {
    delete vao;
    delete buffer;
    delete meshBuilder;
}

void Field::tick() {
    // The front buffer contains the field that is currently visible on-screen
    // On the back buffer we prepare the new field that contains the next generation

    livingCells = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int index = get_index(i, j);

            bool alive = buffer->get_front()[index];
            int neighbors = count_neighbors(i, j);

            bool newState = alive;
            if (alive && neighbors < 2)         // Underpopulation
                newState = false;
            else if (alive && neighbors < 4)    // Stays alive
                newState = true;
            else if (alive && neighbors > 3)    // Overpopulation
                newState = false;
            else if (!alive && neighbors == 3)  // Reproduction
                newState = true;

            buffer->get_back()[index] = newState;
            if (newState)
                livingCells++;
        }
    }

    // After we built the next generation, we swap the buffers
    buffer->swap();
    generation++;
}

void Field::randomize(int mod) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = (rand() % mod) == 0;
            if (alive) livingCells++;
            buffer->get_front()[get_index(i, j)] = alive;
        }
    }
}

void Field::remesh() {
    meshBuilder->clear();
    meshBuilder->push_rectangle(-0.25, -0.25, (float) width + .5f, (float) height + .5f, glm::vec3(0.3f, 0.3f, 0.3f));
    meshBuilder->push_rectangle(0, 0, (float) width, (float) height, glm::vec3(0.2f, 0.2f, 0.2f));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool alive = buffer->get_front()[get_index(i, j)];

            if (alive) {
                // Some nice color theme
                meshBuilder->push_rectangle(i, j, 1, 1, glm::vec3(i / (float) width, j / (float) height, 1.0f));
            }

        }
    }

    vao->set_data(meshBuilder->get_vertices(), meshBuilder->get_vertex_count(), meshBuilder->get_meta(),
                  meshBuilder->get_meta_count());
}

void Field::render() {
    vao->render();
}

void Field::clear() {
    buffer->clear();
}

void Field::toggle_cell(int x, int y) {
    bool *b = &buffer->get_front()[get_index(x, y)];
    *b = !*b;
}

glm::vec2 Field::get_size() const {
    return glm::vec2(width, height);
}

int Field::get_living_cells() const {
    return livingCells;
}

int Field::get_generation() const {
    return generation;
}

int Field::get_index(int x, int y) const {
    return (y * width) + x;
}

int Field::count_neighbors(int x, int y) const {
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
