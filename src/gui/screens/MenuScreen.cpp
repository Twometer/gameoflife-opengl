//
// Created by twome on 08/05/2020.
//

#include "MenuScreen.h"
#include "../components/Label.h"

MenuScreen::MenuScreen() {
    auto testLabel = new Label();
    testLabel->set_text("Hello world!");
    testLabel->set_font_size(0.25f);
    testLabel->set_vertical_alignment(Alignment::CENTER);
    testLabel->set_horizontal_alignment(Alignment::START);

    add_component(testLabel);
}
