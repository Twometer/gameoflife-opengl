//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FONTREADER_H
#define GAMEOFLIFE_OPENGL_FONTREADER_H


#include <fstream>
#include "Glyph.h"
#include "Font.h"

class FontReader {

private:
    static int parse_property(const std::string &line, const std::string &property);

    static Glyph *parse_glyph(const std::string &line);

    static bool is_glyph(const std::string &line);

public:
    static Font *read_font(std::ifstream &stream);

};


#endif //GAMEOFLIFE_OPENGL_FONTREADER_H
