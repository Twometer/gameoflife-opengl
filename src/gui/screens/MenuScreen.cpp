//
// Created by twome on 08/05/2020.
//

#include "MenuScreen.h"
#include "../components/Label.h"
#include "../components/Panel.h"

MenuScreen::MenuScreen() : IScreen("menuScreen") {

    auto testPanel = new Panel("panel1");
    testPanel->set_row(0);
    testPanel->set_col(0);
    testPanel->set_vertical_alignment(Alignment::CENTER);
    testPanel->set_horizontal_alignment(Alignment::CENTER);
    testPanel->set_rows(2);
    testPanel->set_cols(1);

    auto titleLabel = new Label("label1");
    titleLabel->set_text("Game of Life");
    titleLabel->set_font_size(0.5f);
    titleLabel->set_vertical_alignment(Alignment::CENTER);
    titleLabel->set_horizontal_alignment(Alignment::CENTER);
    testPanel->add_component(titleLabel);

    auto copyrightLabel = new Label("label2");
    copyrightLabel->set_text("(c) 2020 Twometer Apps");
    copyrightLabel->set_font_size(0.25f);
    copyrightLabel->set_row(1);
    copyrightLabel->set_vertical_alignment(Alignment::CENTER);
    copyrightLabel->set_horizontal_alignment(Alignment::CENTER);
    testPanel->add_component(copyrightLabel);

    add_component(testPanel);

}
