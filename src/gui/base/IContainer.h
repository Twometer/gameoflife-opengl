//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ICONTAINER_H
#define GAMEOFLIFE_OPENGL_ICONTAINER_H

#include <vector>
#include "IComponent.h"

class IContainer {
protected:
    std::vector<IComponent *> components;

    int rows = 1;
    int columns = 1;

public:
    void set_rows(int r);
    void set_cols(int c);

    void add_component(IComponent *component);

    void layout();

};

#endif //GAMEOFLIFE_OPENGL_ICONTAINER_H
