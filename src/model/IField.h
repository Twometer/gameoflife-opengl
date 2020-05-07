//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_IFIELD_H
#define GAMEOFLIFE_OPENGL_IFIELD_H


#include "../gl/Vao.h"

class IField {

protected:
    Vao *vao = nullptr;

    int living_cells = 0;

public:
    virtual ~IField() = 0;

    virtual void tick() = 0;

    virtual void randomize(int mod) = 0;

    virtual void remesh() = 0;

    int get_living_cells() {
        return living_cells;
    }

    void render() {
        vao->render();
    }
};

#endif //GAMEOFLIFE_OPENGL_IFIELD_H
