//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_PANEL_H
#define GAMEOFLIFE_OPENGL_PANEL_H


#include "../base/Container.h"
#include "../../gl/Vao.h"
#include "../../gl/MeshBuilder.h"

class Panel : public Container {
public:
    explicit Panel(const std::string &id);

    void draw(Graphics &graphics) override;

};


#endif //GAMEOFLIFE_OPENGL_PANEL_H
