//
// Created by twome on 09/05/2020.
//

#include "NewGameScreen.h"
#include "../loader/GuiXmlLoader.h"
#include "../components/Button.h"
#include "../../render/GameWindow.h"
#include "MenuScreen.h"

NewGameScreen::NewGameScreen() : IScreen("newGameScreen") {
    GuiXmlLoader::load(this, "new_game.xml");

    auto btnCreate = find_component<Button>("btnCreate");
    auto btnBack = find_component<Button>("btnBack");

    btnBack->set_click_listener([](){
       GameWindow::get_instance()->get_gui_renderer()->show_screen(new MenuScreen());
    });
}
