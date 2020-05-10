//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ASSETLOADER_H
#define GAMEOFLIFE_OPENGL_ASSETLOADER_H


#include <glad/glad.h>
#include <string>
#include "../gl/Texture.h"
#include "../gui/font/Font.h"

class AssetLoader {
private:
    static void check_shader(const std::string &name, GLuint shader);

public:
    static std::string read_text(const std::string &path);

    static uint8_t *read_bytes(const std::string &path, size_t &size);

    static GLuint load_shader(const std::string &vertex, const std::string &fragment);

    static Font *load_font(const std::string &name);

    static Texture load_texture(const std::string &path);

};


#endif //GAMEOFLIFE_OPENGL_ASSETLOADER_H
