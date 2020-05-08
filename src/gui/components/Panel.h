//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_PANEL_H
#define GAMEOFLIFE_OPENGL_PANEL_H


#include "../base/IContainer.h"
#include "../../gl/Vao.h"
#include "../../gl/MeshBuilder.h"

class Panel : public IContainer {
private:
    Vao vao = Vao(2);
    MeshBuilder meshBuilder;

public:
    Panel(const std::string &id);

    void draw(glm::vec2 origin) override;

};


#endif //GAMEOFLIFE_OPENGL_PANEL_H