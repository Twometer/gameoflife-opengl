//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ISCREEN_H
#define GAMEOFLIFE_OPENGL_ISCREEN_H

#include "IContainer.h"

class IScreen : public IContainer {
public:
    IScreen(const std::string &id);

public:
    void draw() override;

};

#endif //GAMEOFLIFE_OPENGL_ISCREEN_H
