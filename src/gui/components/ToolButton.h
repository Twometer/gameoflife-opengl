//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TOOLBUTTON_H
#define GAMEOFLIFE_OPENGL_TOOLBUTTON_H


#include "../../gl/Texture.h"
#include "../base/IImageComponent.h"
#include "../../util/Animated.h"

class ToolButton : public IImageComponent {
private:
    Animated expansion = 0.0f;

public:
    explicit ToolButton(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void on_mouse_enter() override;

    void on_mouse_leave() override;

};


#endif //GAMEOFLIFE_OPENGL_TOOLBUTTON_H
