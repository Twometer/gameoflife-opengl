//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FIELD_H
#define GAMEOFLIFE_OPENGL_FIELD_H


#include "../gl/Vao.h"
#include "../gl/MeshBuilder.h"
#include "../util/DoubleBuffer.h"

class Field {
private:
    int width;
    int height;

    Vao *vao;
    MeshBuilder *meshBuilder;
    DoubleBuffer<bool> *buffer;

    int livingCells = 0;
    int generation = 0;
public:
    Field(int width, int height);

    ~Field();

    void tick();

    void randomize(int mod);

    void remesh();

    void render() const;

    void clear();

    void toggle_cell(int x, int y);

    void set_cell(int x, int y, bool alive);

    bool get_cell(int x, int y) const;

    bool *get_front_buffer();

    glm::vec2 get_size() const;

    int get_living_cells() const;

    int get_generation() const;

private:
    inline int get_index(int x, int y) const;

    int count_neighbors(int x, int y) const;
};


#endif //GAMEOFLIFE_OPENGL_FIELD_H
