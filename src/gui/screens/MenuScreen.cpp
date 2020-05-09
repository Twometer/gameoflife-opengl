//
// Created by twome on 08/05/2020.
//

#include <iostream>
#include "MenuScreen.h"
#include "../components/Button.h"
#include "../loader/GuiXmlLoader.h"
#include "../../render/GameWindow.h"

MenuScreen::MenuScreen() : IScreen("menuScreen") {
    GuiXmlLoader::load(this, "main_menu.xml");

    auto btnNewGame = find_component<Button>("btnNewGame");
    auto btnLoadGame = find_component<Button>("btnLoadGame");
    auto btnExitGame = find_component<Button>("btnExitGame");

    btnNewGame->set_click_listener([]() {
        std::cout << "New game clicked!" << std::endl;
    });

    btnLoadGame->set_click_listener([]() {
        std::cout << "Load game clicked!" << std::endl;
    });

    btnExitGame->set_click_listener([]() {
        GameWindow::get_instance()->close();
    });
}
