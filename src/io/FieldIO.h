//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FIELDIO_H
#define GAMEOFLIFE_OPENGL_FIELDIO_H


#include <string>
#include "../model/Field.h"

class FieldIO {
public:
    static void write_field(const std::string &path, Field *field);

    static Field *read_field(const std::string &path);

private:
    static uint8_t merge_bytes(const uint8_t *data, int offset, int maxIdx);

    static void expand_bytes(uint8_t merged, uint8_t *dst, int offset, int maxIdx);
};


#endif //GAMEOFLIFE_OPENGL_FIELDIO_H
