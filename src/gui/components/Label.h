//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_LABEL_H
#define GAMEOFLIFE_OPENGL_LABEL_H

#include <string>
#include "../base/IComponent.h"

class Label : public IComponent {
protected:
    std::string text;
    float fontSize;

public:
    void draw() override;

    void set_text(std::string text);
    void set_font_size(float fontSize);
};


#endif //GAMEOFLIFE_OPENGL_LABEL_H
