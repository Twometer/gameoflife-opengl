//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_LOADER_H
#define GAMEOFLIFE_3D_LOADER_H


#include <glad/glad.h>
#include <string>
#include "Texture.h"

class Loader {
private:
    static void check_shader(const std::string &name, GLuint shader);

public:
    static std::string read_text(const std::string &path);

    static GLuint load_shader(const std::string &vertex, const std::string &fragment);

    static Texture load_texture(const std::string &path);

};


#endif //GAMEOFLIFE_3D_LOADER_H
