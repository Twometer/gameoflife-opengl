//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_TEXTURE_H
#define GAMEOFLIFE_3D_TEXTURE_H

#include <glad/glad.h>

struct Texture {

    GLuint id;
    unsigned int width;
    unsigned int height;

    void bind() {
        glBindTexture(GL_TEXTURE_2D, id);
    }

};

#endif //GAMEOFLIFE_3D_TEXTURE_H
