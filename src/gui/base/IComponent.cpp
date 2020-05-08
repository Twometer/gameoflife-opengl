//
// Created by twome on 08/05/2020.
//

#include "IComponent.h"

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

glm::vec2 IComponent::get_preferred_size(glm::vec2 size) {
    return preferredSize;
}