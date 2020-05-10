//
// Created by twome on 09/05/2020.
//

#include "NewGameScreen.h"
#include "../../io/XmlGuiLoader.h"
#include "../components/Button.h"
#include "../../render/GameWindow.h"
#include "MenuScreen.h"
#include "../components/CheckBox.h"
#include "../components/TextBox.h"
#include "IngameGuiScreen.h"

NewGameScreen::NewGameScreen() : IScreen("newGameScreen") {
    XmlGuiLoader::load(this, "new_game.xml");

    auto tbWidth = find_component<TextBox>("tbWidth");
    auto tbHeight = find_component<TextBox>("tbHeight");
    auto cbRandomize = find_component<CheckBox>("cbRandomize");
    auto btnCreate = find_component<Button>("btnCreate");
    auto btnBack = find_component<Button>("btnBack");

    btnCreate->set_click_listener([=]() {
        int width = std::stoi(tbWidth->get_text());
        int height = std::stoi(tbHeight->get_text());
        auto *field = new Field(width, height);

        if (cbRandomize->is_checked())
            field->randomize(4);

        field->remesh();

        GameWindow *win = GameWindow::get_instance();
        win->set_field(field);
        win->get_gui_renderer()->show_screen(new IngameGuiScreen());
    });

    btnBack->set_click_listener([]() {
        GameWindow::get_instance()->get_gui_renderer()->show_screen(new MenuScreen());
    });
}
