//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TEXTUREMANAGER_H
#define GAMEOFLIFE_OPENGL_TEXTUREMANAGER_H


#include <string>
#include <map>
#include "Texture.h"

class TextureManager {
private:
    static std::map<std::string, Texture> textures;

public:
    static Texture *load(std::string id);

};


#endif //GAMEOFLIFE_OPENGL_TEXTUREMANAGER_H
