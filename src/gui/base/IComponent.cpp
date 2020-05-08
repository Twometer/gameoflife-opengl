//
// Created by twome on 08/05/2020.
//

#include "IComponent.h"

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

void IComponent::set_vertical_alignment(Alignment verticalAlignment) {
    this->verticalAlignment = verticalAlignment;
}

void IComponent::set_horizontal_alignment(Alignment horizontalAlignment) {
    this->horizontalAlignment = horizontalAlignment;
}

