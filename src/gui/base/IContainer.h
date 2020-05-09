//
// Created by twome on 08/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ICONTAINER_H
#define GAMEOFLIFE_OPENGL_ICONTAINER_H

#include <vector>
#include "IComponent.h"

/**
 * The IContainer is a special component that
 * implements a simple grid-based container for components
 */
class IContainer : public IComponent {
protected:
    std::vector<IComponent *> components;

    int rows = 1;
    int columns = 1;

public:
    explicit IContainer(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void set_rows(int r);

    void set_cols(int c);

    void add_component(IComponent *component);

    void on_mouse_down(glm::vec2 position) override;

    void on_mouse_up(glm::vec2 position) override;

    void on_mouse_move(glm::vec2 position) override;

private:
    IComponent *find_component(int row, int col);

    void build_rows(std::vector<float> &rowWidths);

    void build_cols(std::vector<float> &colHeights);

    inline glm::vec2 get_origin();
};

#endif //GAMEOFLIFE_OPENGL_ICONTAINER_H
