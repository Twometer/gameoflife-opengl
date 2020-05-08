//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GUIRENDERER_H
#define GAMEOFLIFE_OPENGL_GUIRENDERER_H

#include "base/IScreen.h"
#include "../render/shaders/BasicShader.h"

class GuiRenderer {
private:
    IScreen* currentScreen = nullptr;

    // We can reuse the main game shader here
    BasicShader guiShader;

public:
    void show_screen(IScreen *screen);

    void draw();

    void on_resize();

    void bind_gui_shader();

};


#endif //GAMEOFLIFE_OPENGL_GUIRENDERER_H
