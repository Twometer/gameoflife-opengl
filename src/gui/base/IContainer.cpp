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

void IContainer::draw(glm::vec2 origin) {
    for (auto component : components) {
        component->draw(origin + position + padding);
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
    build_rows(rowHeights);

    // Compute column widths
    build_cols(colWidths);

    // Apply layout constraints
    for (auto component : components) {
        // Cell boundaries
        float xCoord = std::accumulate(colWidths.begin(), colWidths.begin() + component->get_col(), 0.f) +
                       component->get_margin().x;
        float yCoord = std::accumulate(rowHeights.begin(), rowHeights.begin() + component->get_row(), 0.f) +
                       component->get_margin().y;

        float cellWidth = std::accumulate(
                colWidths.begin() + component->get_col(),
                colWidths.begin() + component->get_col() + component->get_col_span(), 0.f);

        float cellHeight = std::accumulate(
                rowHeights.begin() + component->get_row(),
                rowHeights.begin() + component->get_row() + component->get_row_span(), 0.f);

        // Calculate component size based on alignment, margin and calculated minimum component size
        float width =
                component->get_horizontal_alignment() == Alignment::STRETCH ? cellWidth - component->get_margin().x * 2
                                                                            : component->get_minimum_size().x;

        float height =
                component->get_horizontal_alignment() == Alignment::STRETCH ? cellHeight - component->get_margin().y * 2
                                                                            : component->get_minimum_size().y;

        // Align the component correctly
        if (component->get_horizontal_alignment() == Alignment::CENTER) {
            xCoord += cellWidth / 2 - (component->get_minimum_size().x + component->get_margin().x * 2) / 2;
        } else if (component->get_horizontal_alignment() == Alignment::END) {
            xCoord += cellWidth - (component->get_minimum_size().x + component->get_margin().x * 2);
        }

        if (component->get_vertical_alignment() == Alignment::CENTER) {
            yCoord += cellHeight / 2 - (component->get_minimum_size().y + component->get_margin().y * 2) / 2;
        } else if (component->get_vertical_alignment() == Alignment::END){
            yCoord += cellHeight - (component->get_minimum_size().y + component->get_margin().y * 2);
        }

        // Apply to the component
        component->set_position(glm::vec2(xCoord, yCoord));
        component->set_size(glm::vec2(width, height));
    }

    // Finally, calculate size of current component
    bool fillX = this->get_horizontal_alignment() == Alignment::STRETCH;
    bool fillY = this->get_vertical_alignment() == Alignment::STRETCH;

    float totalWidth = fillX ? maximumSize.x : std::accumulate(colWidths.begin(), colWidths.end(), 0.f);
    float totalHeight = fillY ? maximumSize.y : std::accumulate(rowHeights.begin(), rowHeights.end(), 0.f);
    this->minimumSize = glm::vec2(totalWidth, totalHeight);
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

void IContainer::build_rows(std::vector<float> &rowHeights) {
    for (int r = 0; r < rows; r++) {
        float maxHeight = 0.0f;
        for (int c = 0; c < columns; c++) {
            IComponent *component = find_component(r, c);
            if (component == nullptr)
                continue;

            float virtualComponentHeight = component->get_minimum_size().y + component->get_margin().y * 2;
            if (virtualComponentHeight > maxHeight)
                maxHeight = virtualComponentHeight;
        }
        rowHeights.push_back(maxHeight);
    }

    if (verticalAlignment == Alignment::STRETCH) {
        float totalHeight = std::accumulate(rowHeights.begin(), rowHeights.end(), 0.f);

        for (float &rowHeight : rowHeights) {
            rowHeight = (rowHeight / totalHeight * maximumSize.y);
        }
    }
}

void IContainer::build_cols(std::vector<float> &colWidths) {
    for (int c = 0; c < columns; c++) {
        float maxWidth = 0.0f;
        for (int r = 0; r < rows; r++) {
            IComponent *component = find_component(r, c);
            if (component == nullptr)
                continue;

            float virtualComponentWidth = component->get_minimum_size().x + component->get_margin().x * 2;
            if (virtualComponentWidth > maxWidth)
                maxWidth = virtualComponentWidth;
        }
        colWidths.push_back(maxWidth);
    }

    if (horizontalAlignment == Alignment::STRETCH) {
        float totalWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0.f);

        for (float &colWidth : colWidths) {
            colWidth = (colWidth / totalWidth * maximumSize.x);
        }
    }
}

