//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ISCREEN_H
#define GAMEOFLIFE_OPENGL_ISCREEN_H

#include "IContainer.h"

/**
 * The base class for all GUI screens
 */
class IScreen : public IContainer {
public:
    explicit IScreen(const std::string &id);

public:
    void draw(Graphics &graphics) override;

    void layout() override;

};

#endif //GAMEOFLIFE_OPENGL_ISCREEN_H
