//
// Created by twome on 08/05/2020.
//

#include "IComponent.h"
#include "../../render/GameWindow.h"

IComponent::IComponent(const std::string &id) {
    this->id = id;
}

const std::string &IComponent::get_id() const {
    return id;
}

void IComponent::set_row(int r) {
    this->row = r;
}

int IComponent::get_row() const {
    return row;
}

void IComponent::set_row_span(int rowSpan) {
    this->rowSpan = rowSpan;
}

int IComponent::get_row_span() const {
    return rowSpan;
}

void IComponent::set_col(int c) {
    this->column = c;
}

int IComponent::get_col() const {
    return column;
}

void IComponent::set_col_span(int colSpan) {
    this->columnSpan = colSpan;
}

int IComponent::get_col_span() const {
    return columnSpan;
}

void IComponent::set_position(glm::vec2 position) {
    this->position = position;
}

glm::vec2 IComponent::get_position() const {
    return position;
}

glm::vec2 IComponent::get_minimum_size() const {
    return minimumSize + padding * 2.f;
}

void IComponent::set_maximum_size(glm::vec2 maxSize) {
    this->maximumSize = maxSize;
}

glm::vec2 IComponent::get_maximum_size() const {
    return maximumSize;
}

void IComponent::set_size(glm::vec2 size) {
    this->size = size;
}

glm::vec2 IComponent::get_size() const {
    return size;
}

void IComponent::set_margin(glm::vec2 margin) {
    this->margin = margin;
}

glm::vec2 IComponent::get_margin() const {
    return margin;
}

void IComponent::set_padding(glm::vec2 padding) {
    this->padding = padding;
}

void IComponent::set_vertical_alignment(Alignment verticalAlignment) {
    this->verticalAlignment = verticalAlignment;
}

Alignment IComponent::get_vertical_alignment() const {
    return verticalAlignment;
}

void IComponent::set_horizontal_alignment(Alignment horizontalAlignment) {
    this->horizontalAlignment = horizontalAlignment;
}

Alignment IComponent::get_horizontal_alignment() const {
    return horizontalAlignment;
}

Cursor IComponent::get_cursor() {
    return Cursor::STANDARD;
}

bool IComponent::is_inside(glm::vec2 vec) const {
    return vec.x >= this->position.x && vec.y >= this->position.y
           && vec.x < this->position.x + this->size.x && vec.y < this->position.y + this->size.y;
}

bool IComponent::is_mouse_over() const {
    return isMouseOver;
}

bool IComponent::is_mouse_down() const {
    return isMouseDown;
}

bool IComponent::is_focused() const {
    return isFocused;
}

void IComponent::set_click_listener(std::function<void()> listener) {
    this->clickListener = listener;
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
    GameWindow::get_instance()->get_gui_renderer()->focus_component(this);
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
    GameWindow::get_instance()->set_cursor(get_cursor());
}

void IComponent::on_mouse_leave() {
    GameWindow::get_instance()->set_cursor(Cursor::STANDARD);
}

void IComponent::on_got_focus() {
    isFocused = true;
}

void IComponent::on_lost_focus() {
    isFocused = false;
}

void IComponent::on_character_typed(uint32_t codepoint) {
    // Do nothing by default
}

void IComponent::on_key_event(int key, int action) {
    // Do nothing by default
}

