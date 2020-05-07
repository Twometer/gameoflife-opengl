//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_IFIELD_H
#define GAMEOFLIFE_3D_IFIELD_H


#include "../gl/Vao.h"

class IField {

protected:
    Vao *vao = nullptr;

public:
    virtual ~IField() = 0;

    virtual void tick() = 0;

    virtual void randomize(int mod) = 0;

    virtual void remesh() = 0;

    void render() {
        vao->render();
    }
};

#endif //GAMEOFLIFE_3D_IFIELD_H
