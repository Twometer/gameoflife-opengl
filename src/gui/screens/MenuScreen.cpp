//
// Created by twome on 08/05/2020.
//

#include <iostream>
#include "MenuScreen.h"
#include "../components/Label.h"
#include "../components/Panel.h"
#include "../components/Button.h"

MenuScreen::MenuScreen() : IScreen("menuScreen") {

    auto panel = new Panel("panel1");
    panel->set_row(0);
    panel->set_col(0);
    panel->set_vertical_alignment(Alignment::CENTER);
    panel->set_horizontal_alignment(Alignment::CENTER);
    panel->set_rows(5);
    panel->set_cols(1);
    panel->set_padding(glm::vec2(32, 16));

    auto titleLabel = new Label("label1");
    titleLabel->set_text("Game of Life");
    titleLabel->set_font_size(0.8f);
    titleLabel->set_vertical_alignment(Alignment::CENTER);
    titleLabel->set_horizontal_alignment(Alignment::CENTER);
    panel->add_component(titleLabel);

    auto copyrightLabel = new Label("label2");
    copyrightLabel->set_text("(c) 2020 Twometer Apps");
    copyrightLabel->set_font_size(0.25f);
    copyrightLabel->set_row(1);
    copyrightLabel->set_vertical_alignment(Alignment::CENTER);
    copyrightLabel->set_horizontal_alignment(Alignment::CENTER);
    panel->add_component(copyrightLabel);

    auto newGameButton = new Button("btnNewGame");
    newGameButton->set_horizontal_alignment(Alignment::STRETCH);
    newGameButton->set_text("New game");
    newGameButton->set_row(2);
    newGameButton->set_font_size(0.55f);
    newGameButton->set_margin(glm::vec2(32, 8));
    newGameButton->set_padding(glm::vec2(32, 0));
    newGameButton->set_click_listener([]() {
        std::cout << "New game clicked!" << std::endl;
    });
    panel->add_component(newGameButton);

    auto loadGameButton = new Button("btnLoadGame");
    loadGameButton->set_horizontal_alignment(Alignment::STRETCH);
    loadGameButton->set_text("Load game");
    loadGameButton->set_row(3);
    loadGameButton->set_font_size(0.55f);
    loadGameButton->set_margin(glm::vec2(32, 8));
    loadGameButton->set_padding(glm::vec2(32, 0));
    panel->add_component(loadGameButton);

    auto exitButton = new Button("btnExit");
    exitButton->set_horizontal_alignment(Alignment::STRETCH);
    exitButton->set_text("Exit game");
    exitButton->set_row(4);
    exitButton->set_font_size(0.55f);
    exitButton->set_margin(glm::vec2(32, 8));
    exitButton->set_padding(glm::vec2(32, 0));
    panel->add_component(exitButton);

    add_component(panel);

}
