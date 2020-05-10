//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_IFIELD_H
#define GAMEOFLIFE_OPENGL_IFIELD_H


#include <glm/vec4.hpp>
#include "../gl/Vao.h"

/**
 * The base class for all Game of Life fields
 * At the moment this is only the 2D field
 * but maybe I have time to implement 3D and 4D as well
 */
class IField {

protected:
    Vao *vao = nullptr;

    int living_cells = 0;

public:
    virtual ~IField() = 0;

    virtual void tick() = 0;

    virtual void randomize(int mod) = 0;

    virtual void remesh() = 0;

    virtual glm::vec4 get_size() = 0;

    int get_living_cells() const {
        return living_cells;
    }

    void render() {
        vao->render();
    }
};

#endif //GAMEOFLIFE_OPENGL_IFIELD_H
