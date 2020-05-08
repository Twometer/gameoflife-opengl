//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GUIRENDERER_H
#define GAMEOFLIFE_OPENGL_GUIRENDERER_H

#include "base/IScreen.h"

class GuiRenderer {
private:
    IScreen* currentScreen;

public:
    void show_screen(IScreen *screen);

    void draw();

    void on_resize();

};


#endif //GAMEOFLIFE_OPENGL_GUIRENDERER_H
