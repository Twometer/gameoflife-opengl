//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TEXTCOMPONENT_H
#define GAMEOFLIFE_OPENGL_TEXTCOMPONENT_H

#include "Component.h"

/**
 * The TextComponent describes a component
 * that displays text (obviously): It defines
 * default behavior for text content and font size
 */
class TextComponent : public Component {
protected:
    std::string text = "";
    float fontSize = 1.0f;

public:
    TextComponent(const std::string &id) : Component(id) {}

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

#endif //GAMEOFLIFE_OPENGL_TEXTCOMPONENT_H
