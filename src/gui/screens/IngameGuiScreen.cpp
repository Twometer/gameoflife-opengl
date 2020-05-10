//
// Created by twome on 10/05/2020.
//

#include "IngameGuiScreen.h"
#include "../../io/XmlGuiLoader.h"

IngameGuiScreen::IngameGuiScreen() : IScreen("ingameGui") {
    XmlGuiLoader::load(this, "ingame_gui.xml");

    lbLivingCells = find_component<Label>("lbLivingCells");
    lbGeneration = find_component<Label>("lbGeneration");

    btnPlayPause = find_component<ToolButton>("btnPlayPause");
    btnNextGen = find_component<ToolButton>("btnNextGen");

    btnBack = find_component<ToolButton>("btnBack");
    btnNew = find_component<ToolButton>("btnNew");
    btnOpen = find_component<ToolButton>("btnOpen");
    btnSave = find_component<ToolButton>("btnSave");
    btnSettings = find_component<ToolButton>("btnSettings");
}

bool IngameGuiScreen::blocks_game_inputs() const {
    return false;
}
