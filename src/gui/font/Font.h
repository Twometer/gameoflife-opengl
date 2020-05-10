//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FONT_H
#define GAMEOFLIFE_OPENGL_FONT_H

#include <map>
#include "../../gl/Texture.h"
#include "Glyph.h"

struct Font {
    Texture atlas;
    std::map<int, Glyph *> glyphs;
};

#endif //GAMEOFLIFE_OPENGL_FONT_H
