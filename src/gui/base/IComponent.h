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

    glm::vec2 position = glm::vec2(0, 0);
    glm::vec2 size = glm::vec2(0, 0);
    glm::vec2 preferredSize = glm::vec2(0, 0);

    Alignment verticalAlignment = Alignment::START;
    Alignment horizontalAlignment = Alignment::START;

public:
    explicit IComponent(const std::string &id);

    virtual void draw() = 0;

    virtual void layout() = 0;

    void set_row(int r);

    void set_row_span(int rowSpan);

    void set_col(int c);

    void set_col_span(int colSpan);

    int get_row();

    int get_row_span();

    int get_col();

    int get_col_span();

    void set_vertical_alignment(Alignment verticalAlignment);

    void set_horizontal_alignment(Alignment horizontalAlignment);

    void set_position(glm::vec2 position);

    void set_size(glm::vec2 size);

    glm::vec2 get_position();

    glm::vec2 get_size();

    glm::vec2 get_preferred_size(glm::vec2 size);

};

#endif //GAMEOFLIFE_OPENGL_ICOMPONENT_H
