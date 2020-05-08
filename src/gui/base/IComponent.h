//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ICOMPONENT_H
#define GAMEOFLIFE_OPENGL_ICOMPONENT_H

#include <string>
#include <glm/vec2.hpp>
#include "Alignment.h"

class IComponent {
protected:
    std::string id;

    int row = 0;
    int rowSpan = 1;
    int column = 0;
    int columnSpan = 1;

    Alignment verticalAlignment = Alignment::START;
    Alignment horizontalAlignment = Alignment::START;

public:
    virtual void draw() = 0;

    void set_row(int r);

    void set_row_span(int rowSpan);

    void set_col(int c);

    void set_col_span(int colSpan);

    void set_vertical_alignment(Alignment verticalAlignment);

    void set_horizontal_alignment(Alignment horizontalAlignment);

};

#endif //GAMEOFLIFE_OPENGL_ICOMPONENT_H
