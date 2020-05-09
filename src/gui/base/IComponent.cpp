//
// Created by twome on 08/05/2020.
//

#include "IComponent.h"
#include "../../render/GameWindow.h"

IComponent::IComponent(const std::string &id) {
    this->id = id;
}

void IComponent::set_row(int r) {
    this->row = r;
}

void IComponent::set_row_span(int rowSpan) {
    this->rowSpan = rowSpan;
}

void IComponent::set_col(int c) {
    this->column = c;
}

void IComponent::set_col_span(int colSpan) {
    this->columnSpan = colSpan;
}

int IComponent::get_row() {
    return row;
}

int IComponent::get_row_span() {
    return rowSpan;
}

int IComponent::get_col() {
    return column;
}

int IComponent::get_col_span() {
    return columnSpan;
}

void IComponent::set_vertical_alignment(Alignment verticalAlignment) {
    this->verticalAlignment = verticalAlignment;
}

void IComponent::set_horizontal_alignment(Alignment horizontalAlignment) {
    this->horizontalAlignment = horizontalAlignment;
}

Alignment IComponent::get_vertical_alignment() {
    return verticalAlignment;
}

Alignment IComponent::get_horizontal_alignment() {
    return horizontalAlignment;
}

void IComponent::set_size(glm::vec2 size) {
    this->size = size;
}

void IComponent::set_position(glm::vec2 position) {
    this->position = position;
}

glm::vec2 IComponent::get_position() {
    return position;
}

glm::vec2 IComponent::get_size() {
    return size;
}

void IComponent::set_maximum_size(glm::vec2 maxSize) {
    this->maximumSize = maxSize;
}

glm::vec2 IComponent::get_minimum_size() {
    return minimumSize + padding * 2.f;
}

glm::vec2 IComponent::get_maximum_size() {
    return maximumSize;
}

void IComponent::set_margin(glm::vec2 margin) {
    this->margin = margin;
}

glm::vec2 IComponent::get_margin() {
    return margin;
}

void IComponent::set_padding(glm::vec2 padding) {
    this->padding = padding;
}

void IComponent::on_mouse_down(glm::vec2 vec) {
    if (is_inside(vec))
        isMouseDown = true;
}

void IComponent::on_mouse_up(glm::vec2 vec) {
    isMouseDown = false;
    if (is_inside(vec))
        on_click(vec);
}

void IComponent::on_click(glm::vec2 position) {
    if (clickListener)
        clickListener();
}

bool IComponent::is_inside(glm::vec2 vec) {
    return vec.x >= this->position.x && vec.y >= this->position.y
           && vec.x < this->position.x + this->size.x && vec.y < this->position.y + this->size.y;
}

void IComponent::set_click_listener(std::function<void()> listener) {
    this->clickListener = listener;
}

void IComponent::on_mouse_move(glm::vec2 position) {
    bool isInside = is_inside(position);

    if (isInside && !isMouseOver) {
        isMouseOver = true;
        on_mouse_enter();
    } else if (!isInside && isMouseOver) {
        isMouseOver = false;
        on_mouse_leave();
    }
}

void IComponent::on_mouse_enter() {
    // Do nothing by default
}

void IComponent::on_mouse_leave() {
    // Do nothing by default
}
