//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_FIELD2D_H
#define GAMEOFLIFE_3D_FIELD2D_H


#include "IField.h"
#include "../util/DoubleBuffer.h"

class Field2d : public IField {
private:
    int width;
    int height;

    DoubleBuffer<bool>* buffer;

    inline int getIndex(int x, int y);

    int countNeighbors(bool* buf, int x, int y);

public:
    Field2d(int width, int height);

    ~Field2d();

    void tick() override;

    void randomize() override;
};


#endif //GAMEOFLIFE_3D_FIELD2D_H
