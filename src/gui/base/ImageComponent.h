//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_IMAGECOMPONENT_H
#define GAMEOFLIFE_OPENGL_IMAGECOMPONENT_H

#include "Component.h"

/**
 * The ImageComponent provides a base
 * class for all textured components. It
 * handles texture loading and ID mapping
 */
class ImageComponent : public Component {
protected:
    std::string textureId = "";
    Texture *texture = nullptr;

public:
    ImageComponent(const std::string &id) : Component(id) {}

    void set_texture(std::string textureId);

};


#endif //GAMEOFLIFE_OPENGL_IMAGECOMPONENT_H
