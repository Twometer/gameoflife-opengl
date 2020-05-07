//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_3D_FONT_H
#define GAMEOFLIFE_3D_FONT_H

#include <map>
#include "../../gl/Texture.h"
#include "Glyph.h"

struct Font {
    Texture atlas;
    std::map<int, Glyph*> glyphs;
};

#endif //GAMEOFLIFE_3D_FONT_H
