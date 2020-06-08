//
// Created by twome on 08/05/2020.
//

#include <iostream>

#include <nfd.h>

#include "MenuScreen.h"
#include "../components/Button.h"
#include "../../io/XmlGuiLoader.h"
#include "../../render/GameWindow.h"
#include "NewGameScreen.h"
#include "../../io/FieldIO.h"

MenuScreen::MenuScreen() : Screen("menuScreen") {
    XmlGuiLoader::load(this, "main_menu.xml");

    auto btnNewGame = find_component<Button>("btnNewGame");
    auto btnLoadGame = find_component<Button>("btnLoadGame");
    auto btnExitGame = find_component<Button>("btnExitGame");

    btnNewGame->set_click_listener([]() {
        GameWindow::get_instance()->get_gui_renderer()->show_screen(new NewGameScreen());
    });

    btnLoadGame->set_click_listener([]() {
        nfdchar_t *outPath = nullptr;
        nfdresult_t result = NFD_OpenDialog("bin,nk", nullptr, &outPath);

        if (result == NFD_OKAY) {
            std::string path = std::string(outPath);

            Field *field = FieldIO::read_field(path);
            GameWindow::get_instance()->set_field(field);
            GameWindow::get_instance()->show_ingame_gui();

            delete outPath;
        }
    });

    btnExitGame->set_click_listener([]() {
        GameWindow::get_instance()->close();
    });
}
