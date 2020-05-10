//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_INGAMEGUISCREEN_H
#define GAMEOFLIFE_OPENGL_INGAMEGUISCREEN_H


#include "../base/IScreen.h"
#include "../components/Label.h"
#include "../components/ToolButton.h"

class IngameGuiScreen : public IScreen {
public:
    Label *lbLivingCells;
    Label *lbGeneration;

    ToolButton *btnPlayPause;
    ToolButton *btnNextGen;

    IngameGuiScreen();

    bool blocks_game_inputs() const override;

};


#endif //GAMEOFLIFE_OPENGL_INGAMEGUISCREEN_H
