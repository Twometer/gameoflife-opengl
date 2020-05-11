//
// Created by twome on 10/05/2020.
//

#include "ImageComponent.h"
#include "../../gl/TextureManager.h"

void ImageComponent::set_texture(std::string textureId) {
    if (textureId != this->textureId) {
        this->textureId = textureId;
        texture = TextureManager::load(textureId);
    }
}

