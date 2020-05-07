//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FIELD2D_H
#define GAMEOFLIFE_OPENGL_FIELD2D_H


#include "IField.h"
#include "../util/DoubleBuffer.h"
#include "../gl/MeshBuilder.h"

class Field2d : public IField {
private:
    int width;
    int height;

    MeshBuilder *meshBuilder;
    DoubleBuffer<bool> *buffer;

    inline int get_index(int x, int y);

    int count_neighbors(int x, int y);

public:
    Field2d(int width, int height);

    ~Field2d() override;

    void tick() override;

    void randomize(int mod) override;

    void remesh() override;
};


#endif //GAMEOFLIFE_OPENGL_FIELD2D_H
