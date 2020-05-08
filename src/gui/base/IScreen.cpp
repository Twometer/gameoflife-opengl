//
// Created by twome on 08/05/2020.
//

#include "IScreen.h"

void IScreen::draw() {
    for(auto component : components)
        component->draw();
}

