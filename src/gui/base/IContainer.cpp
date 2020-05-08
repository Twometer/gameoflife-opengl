//
// Created by twome on 08/05/2020.
//

#include <numeric>
#include "IContainer.h"

IContainer::IContainer(const std::string &id) : IComponent(id) {
}

void IContainer::add_component(IComponent *component) {
    this->components.push_back(component);
}

void IContainer::draw() {
    for (auto component : components) {
        component->draw();
    }
}

void IContainer::layout() {
    std::vector<float> rowHeights;
    std::vector<float> colWidths;

    // Layout every component inside this one
    for (auto component : components) {
        component->layout();
    }

    // Compute row heights
    for (int r = 0; r < rows; r++) {
        float maxHeight = 0.0f;
        for (int c = 0; c < columns; c++) {
            IComponent *component = find_component(r, c);
            if (component != nullptr && component->get_size().y > maxHeight)
                maxHeight = component->get_size().y;
        }
        rowHeights.push_back(maxHeight);
    }

    // Compute column widths
    for (int c = 0; c < columns; c++) {
        float maxWidth = 0.0f;
        for (int r = 0; r < rows; r++) {
            IComponent *component = find_component(r, c);
            if (component != nullptr && component->get_size().x > maxWidth)
                maxWidth = component->get_size().x;
        }
        colWidths.push_back(maxWidth);
    }

    // Apply layout constraints
    for (auto component : components) {
        float xCoord = std::accumulate(colWidths.begin(), colWidths.begin() + component->get_col(), 0.f);
        float yCoord = std::accumulate(rowHeights.begin(), rowHeights.begin() + component->get_row(), 0.f);

        float width = colWidths[component->get_col()];
        float height = rowHeights[component->get_row()];

        component->set_position(glm::vec2(xCoord, yCoord));
        component->set_size(glm::vec2(width, height));
    }

    // Finally, calculate size of current component
    float totalWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0.f);
    float totalHeight = std::accumulate(rowHeights.begin(), rowHeights.end(), 0.f);
    this->preferredSize = glm::vec2(totalWidth, totalHeight);
}

void IContainer::set_cols(int c) {
    this->columns = c;
}

void IContainer::set_rows(int r) {
    this->rows = r;
}

IComponent *IContainer::find_component(int row, int col) {
    for (auto component : components)
        if (component->get_row() == row && component->get_col() == col)
            return component;
    return nullptr;
}

