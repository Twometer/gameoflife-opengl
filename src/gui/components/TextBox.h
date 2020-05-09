//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TEXTBOX_H
#define GAMEOFLIFE_OPENGL_TEXTBOX_H


#include "../base/ITextComponent.h"
#include "../../util/AnimatedColor.h"

class TextBox : public ITextComponent {
private:
    AnimatedColor borderColor = glm::vec3(0.2157, 0.2549, 0.2745);

    std::string placeholder;

public:
    explicit TextBox(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void on_got_focus() override;

    void on_lost_focus() override;

    Cursor get_cursor() override;

    void set_placeholder(const std::string &placeholder);
};


#endif //GAMEOFLIFE_OPENGL_TEXTBOX_H
