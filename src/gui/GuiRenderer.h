//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GUIRENDERER_H
#define GAMEOFLIFE_OPENGL_GUIRENDERER_H

#include "base/IScreen.h"
#include "../render/shaders/BasicShader.h"
#include "Graphics.h"
#include "../gl/Vao.h"

class GuiRenderer {
private:
    IScreen *currentScreen = nullptr;

    Vao vao = Vao(2);
    MeshBuilder meshBuilder;
    Graphics graphics = Graphics(&vao, &meshBuilder, &guiShader, glm::vec2(0, 0));

    // We can reuse the main game shader here
    BasicShader guiShader;

public:
    void show_screen(IScreen *screen);

    void draw();

    void on_resize();

    void on_mouse_down(glm::vec2 position);

    void on_mouse_up(glm::vec2 position);

};


#endif //GAMEOFLIFE_OPENGL_GUIRENDERER_H

