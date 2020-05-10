//
// Created by twome on 10/05/2020.
//

#include "TextureManager.h"
#include "../io/AssetLoader.h"

std::map<std::string, Texture> TextureManager::textures;

Texture *TextureManager::load(std::string id) {
    if (textures.count(id)) {
        return &textures[id];
    } else {
        Texture tex = AssetLoader::load_texture("assets/images/" + id + ".png");
        textures[id] = tex;
        return &textures[id];
    }
}
