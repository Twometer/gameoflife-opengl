//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_LABEL_H
#define GAMEOFLIFE_OPENGL_LABEL_H

#include <string>
#include "../base/TextComponent.h"

class Label : public TextComponent {
public:
    explicit Label(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;
};


#endif //GAMEOFLIFE_OPENGL_LABEL_H
