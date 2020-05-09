//
// Created by twome on 08/05/2020.
//

#include <iostream>
#include "MenuScreen.h"
#include "../components/Panel.h"
#include "../components/Button.h"
#include "../loader/GuiXmlLoader.h"

MenuScreen::MenuScreen() : IScreen("menuScreen") {
    GuiXmlLoader::load(this, "main_menu.xml");

    auto button = find_component<Button>("btnNewGame");
    button->set_click_listener([]() {
       std::cout << "New game clicked!" << std::endl;
    });
}
