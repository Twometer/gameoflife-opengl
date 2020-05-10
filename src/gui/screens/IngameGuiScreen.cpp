//
// Created by twome on 10/05/2020.
//

#include "IngameGuiScreen.h"
#include "../../io/XmlGuiLoader.h"

IngameGuiScreen::IngameGuiScreen() : IScreen("ingameGui") {
    XmlGuiLoader::load(this, "ingame_gui.xml");
}

bool IngameGuiScreen::blocks_game_inputs() const {
    return false;
}
