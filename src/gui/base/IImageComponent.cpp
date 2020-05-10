//
// Created by twome on 10/05/2020.
//

#include "IImageComponent.h"
#include "../../gl/TextureManager.h"

void IImageComponent::set_texture(std::string textureId) {
    if (textureId != this->textureId) {
        this->textureId = textureId;
        texture = TextureManager::load(textureId);
    }
}

