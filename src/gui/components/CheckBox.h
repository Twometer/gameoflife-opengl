//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_CHECKBOX_H
#define GAMEOFLIFE_OPENGL_CHECKBOX_H


#include "../base/TextComponent.h"
#include "../../util/AnimatedColor.h"

class CheckBox : public TextComponent {
private:
    AnimatedColor checkContentColor = glm::vec3(0.1529, 0.1922, 0.2118);
    bool checked = false;

public:
    explicit CheckBox(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void on_click(glm::vec2 position) override;

    bool is_checked() const;

};


#endif //GAMEOFLIFE_OPENGL_CHECKBOX_H
