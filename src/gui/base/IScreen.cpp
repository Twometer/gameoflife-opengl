//
// Created by twome on 08/05/2020.
//

#include "IScreen.h"
#include "../../render/GameWindow.h"

void IScreen::draw(Graphics &graphics) {
    for (auto component : components)
        component->draw(graphics);
}

IScreen::IScreen(const std::string &id) : IContainer(id) {
    set_vertical_alignment(Alignment::STRETCH);
    set_horizontal_alignment(Alignment::STRETCH);
}

void IScreen::layout() {
    this->minimumSize = GameWindow::get_instance()->get_viewport_size();
    this->maximumSize = GameWindow::get_instance()->get_viewport_size();
    IContainer::layout();
}

bool IScreen::blocks_game_inputs() const {
    return true;
}

IComponent *IScreen::get_focused_component() const {
    return focusedComponent;
}

void IScreen::set_focused_component(IComponent *focusedComponent) {
    this->focusedComponent = focusedComponent;
}
