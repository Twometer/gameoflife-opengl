//
// Created by twome on 08/05/2020.
//

#include <iostream>
#include "MenuScreen.h"
#include "../components/Button.h"
#include "../../io/XmlGuiLoader.h"
#include "../../render/GameWindow.h"
#include "NewGameScreen.h"

MenuScreen::MenuScreen() : IScreen("menuScreen") {
    XmlGuiLoader::load(this, "main_menu.xml");

    auto btnNewGame = find_component<Button>("btnNewGame");
    auto btnLoadGame = find_component<Button>("btnLoadGame");
    auto btnExitGame = find_component<Button>("btnExitGame");

    btnNewGame->set_click_listener([]() {
        GameWindow::get_instance()->get_gui_renderer()->show_screen(new NewGameScreen());
    });

    btnLoadGame->set_click_listener([]() {
        std::cout << "Load game clicked!" << std::endl;
    });

    btnExitGame->set_click_listener([]() {
        GameWindow::get_instance()->close();
    });
}
