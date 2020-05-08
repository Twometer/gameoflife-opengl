//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_BUTTON_H
#define GAMEOFLIFE_OPENGL_BUTTON_H


#include "../base/IComponent.h"
#include "../../gl/Vao.h"
#include "../../gl/MeshBuilder.h"

class Button : public IComponent {
private:
    Vao vao = Vao(2);
    MeshBuilder meshBuilder;

    std::string text = "";
    float fontSize = 1.0f;

public:
    Button(const std::string &id);

    void draw(glm::vec2 origin) override;

    void layout() override;

    void set_text(std::string text);
    void set_font_size(float fontSize);
};


#endif //GAMEOFLIFE_OPENGL_BUTTON_H
