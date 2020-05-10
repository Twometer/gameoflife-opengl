//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GUIRENDERER_H
#define GAMEOFLIFE_OPENGL_GUIRENDERER_H

#include "base/IScreen.h"
#include "../render/shaders/BasicShader.h"
#include "../render/shaders/TexturedShader.h"
#include "Graphics.h"
#include "../gl/Vao.h"

class GuiRenderer {
private:
    IScreen *currentScreen = nullptr;

    Vao vao = Vao(2);
    MeshBuilder meshBuilder;
    Graphics graphics = Graphics(&vao, &meshBuilder, &flatShader, &texturedShader, glm::vec2(0, 0));

    // We can reuse the main game shader here
    BasicShader flatShader;
    TexturedShader texturedShader;

public:
    void show_screen(IScreen *screen);

    void draw();

    void on_resize();

    void on_mouse_down(glm::vec2 position);

    void on_mouse_up(glm::vec2 position);

    void on_mouse_move(glm::vec2 position);

    void on_character_typed(uint32_t codepoint);

    void on_key_event(int key, int action);

    bool is_input_blocked() const;

    void focus_component(IComponent *component);

};


#endif //GAMEOFLIFE_OPENGL_GUIRENDERER_H

