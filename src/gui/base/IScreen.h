//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ISCREEN_H
#define GAMEOFLIFE_OPENGL_ISCREEN_H

#include "IContainer.h"

/**
 * The base class for all GUI screens
 */
class IScreen : public IContainer {
private:
    IComponent *focusedComponent = nullptr;

public:
    explicit IScreen(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void set_focused_component(IComponent *focusedComponent);

    IComponent *get_focused_component() const;

    /**
     * This may be true for e.g. the menu screen, but false for the ingame HUD screen
     * @return Whether the current screen should block inputs to the game such as zooming and moving the field.
     */
    virtual bool blocks_game_inputs() const;

};

#endif //GAMEOFLIFE_OPENGL_ISCREEN_H
