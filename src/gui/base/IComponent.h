//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ICOMPONENT_H
#define GAMEOFLIFE_OPENGL_ICOMPONENT_H

#include <string>
#include <glm/vec2.hpp>
#include <functional>
#include "Alignment.h"
#include "../Graphics.h"

/**
 * The base class for all GUI components
 */
class IComponent {
protected:
    std::string id;

    int row = 0;
    int rowSpan = 1;
    int column = 0;
    int columnSpan = 1;

    glm::vec2 position = glm::vec2(0, 0);

    glm::vec2 minimumSize = glm::vec2(0, 0);
    glm::vec2 maximumSize = glm::vec2(0, 0);
    glm::vec2 size = glm::vec2(0, 0);

    glm::vec2 margin = glm::vec2(8, 8);
    glm::vec2 padding = glm::vec2(0, 0);

    Alignment verticalAlignment = Alignment::START;
    Alignment horizontalAlignment = Alignment::START;

private:
    bool isMouseDown = false;
    bool isMouseOver = false;

    std::function<void()> clickListener;

public:
    explicit IComponent(const std::string &id);

    virtual void draw(Graphics &graphics) = 0;

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

    Alignment get_vertical_alignment();

    Alignment get_horizontal_alignment();

    void set_position(glm::vec2 position);

    void set_maximum_size(glm::vec2 maxSize);

    void set_size(glm::vec2 size);

    glm::vec2 get_position();

    glm::vec2 get_size();

    glm::vec2 get_minimum_size();

    glm::vec2 get_maximum_size();

    void set_margin(glm::vec2 margin);

    glm::vec2 get_margin();

    void set_padding(glm::vec2 padding);

    void set_click_listener(std::function<void()> listener);

    bool is_inside(glm::vec2 position);

    const std::string &get_id();

    virtual void on_mouse_down(glm::vec2 position);

    virtual void on_mouse_up(glm::vec2 position);

    virtual void on_click(glm::vec2 position);

    virtual void on_mouse_move(glm::vec2 position);

    virtual void on_mouse_enter();

    virtual void on_mouse_leave();

};

#endif //GAMEOFLIFE_OPENGL_ICOMPONENT_H
