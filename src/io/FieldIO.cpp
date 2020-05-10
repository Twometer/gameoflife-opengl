//
// Created by twome on 10/05/2020.
//

#include <glm/common.hpp>
#include <iostream>
#include <fstream>
#include "FieldIO.h"
#include "AssetLoader.h"

void FieldIO::write_field(const std::string &path, Field *field) {
    uint16_t width = field->get_size().x;
    uint16_t height = field->get_size().y;

    size_t uncompressedDataLen = width * height;
    uint8_t *uncompressedData = (uint8_t *) field->get_front_buffer();

    size_t compressedDataLen = glm::ceil(uncompressedDataLen / 8.f) + 4; // 4 bytes for the metadata
    uint8_t compressedData[compressedDataLen];

    memcpy(compressedData, &width, 2);
    memcpy(compressedData + 2, &height, 2);

    for (int i = 4; i < compressedDataLen; i++) {
        compressedData[i] = merge_bytes(uncompressedData, (i - 4) * 8, uncompressedDataLen - 1);
    }

    std::ofstream stream(path, std::ios::binary | std::ios::out);
    stream.write((char *) compressedData, compressedDataLen);
    stream.close();
}

Field *FieldIO::read_field(const std::string &path) {
    size_t dataSize = 0;
    uint8_t *data = AssetLoader::read_bytes(path, dataSize);

    uint16_t width = 0;
    uint16_t height = 0;
    memcpy(&width, data, 2);
    memcpy(&height, data + 2, 2);

    auto *field = new Field(width, height);
    uint8_t *uncompressedData = (uint8_t *) field->get_front_buffer();

    for (int i = 4; i < dataSize; i++) {
        expand_bytes(data[i], uncompressedData, (i - 4) * 8, width * height - 1);
    }

    field->remesh();

    delete[] data;
    return field;
}

uint8_t FieldIO::merge_bytes(const uint8_t *data, int offset, int maxIdx) {
    uint8_t v = data[offset];
    int endIdx = glm::min(offset + 7, maxIdx);
    for (size_t i = offset + 1; i <= endIdx; i++) {
        v <<= 1u;
        if (data[i])
            v |= 0x1u;
    }
    return v;
}

void FieldIO::expand_bytes(uint8_t merged, uint8_t *dst, int offset, int maxIdx) {
    int endIdx = glm::min(offset + 7, maxIdx);
    for (int i = endIdx; i >= offset; i--) {
        if (merged & 1u)
            dst[i] = 1;
        else
            dst[i] = 0;
        merged >>= 1u;
    }
}
