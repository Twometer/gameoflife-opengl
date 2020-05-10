//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_IIMAGECOMPONENT_H
#define GAMEOFLIFE_OPENGL_IIMAGECOMPONENT_H

#include "IComponent.h"

/**
 * The IImageComponent provides a base
 * class for all textured components. It
 * handles texture loading and ID mapping
 */
class IImageComponent : public IComponent {
protected:
    std::string textureId = "";
    Texture *texture = nullptr;

public:
    IImageComponent(const std::string &id) : IComponent(id) {}

    void set_texture(std::string textureId);

};


#endif //GAMEOFLIFE_OPENGL_IIMAGECOMPONENT_H
