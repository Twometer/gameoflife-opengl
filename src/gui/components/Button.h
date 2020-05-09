//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_BUTTON_H
#define GAMEOFLIFE_OPENGL_BUTTON_H


#include "../base/IComponent.h"
#include "../../gl/Vao.h"
#include "../../gl/MeshBuilder.h"
#include "../../util/AnimatedColor.h"

class Button : public IComponent {
private:
    AnimatedColor color = glm::vec3(0.1804, 0.8, 0.4431);

    std::string text = "";
    float fontSize = 1.0f;

public:
    explicit Button(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void set_text(std::string text);

    void set_font_size(float fontSize);

    void on_mouse_enter() override;

    void on_mouse_leave() override;
};


#endif //GAMEOFLIFE_OPENGL_BUTTON_H
