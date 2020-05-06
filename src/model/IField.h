//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_IFIELD_H
#define GAMEOFLIFE_3D_IFIELD_H


class IField {
public:
    virtual void tick() = 0;

    virtual void randomize() = 0;
};


#endif //GAMEOFLIFE_3D_IFIELD_H
