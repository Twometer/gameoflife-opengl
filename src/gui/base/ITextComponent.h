//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ITEXTCOMPONENT_H
#define GAMEOFLIFE_OPENGL_ITEXTCOMPONENT_H

#include "IComponent.h"

/**
 * The ITextComponent describes a component
 * that displays text (obviously): It defines
 * default behavior for text content and font size
 */
class ITextComponent : public IComponent {
protected:
    std::string text = "";
    float fontSize = 1.0f;

public:
    ITextComponent(const std::string &id) : IComponent(id) {}

    virtual void on_text_changed() {
    }

    const std::string &get_text() const {
        return text;
    };

    void set_text(std::string text) {
        this->text = text;
        on_text_changed();
    }

    void set_font_size(float fontSize) {
        this->fontSize = fontSize;
    }
};

#endif //GAMEOFLIFE_OPENGL_ITEXTCOMPONENT_H
