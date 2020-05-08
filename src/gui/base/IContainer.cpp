//
// Created by twome on 08/05/2020.
//

#include "IContainer.h"

void IContainer::add_component(IComponent *component) {
    this->components.push_back(component);
}

void IContainer::layout() {

}

void IContainer::set_cols(int c) {
    this->columns = c;
}

void IContainer::set_rows(int r) {
    this->rows = r;
}

