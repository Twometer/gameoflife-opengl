//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_LABEL_H
#define GAMEOFLIFE_OPENGL_LABEL_H

#include <string>
#include "../base/ITextComponent.h"

class Label : public ITextComponent {
public:
    explicit Label(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;
};


#endif //GAMEOFLIFE_OPENGL_LABEL_H
