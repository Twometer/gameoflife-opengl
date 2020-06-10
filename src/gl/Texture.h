//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TEXTURE_H
#define GAMEOFLIFE_OPENGL_TEXTURE_H

#include <glad/glad.h>

struct Texture {

    GLuint id;
    unsigned int width;
    unsigned int height;

    void bind() const {
        glBindTexture(GL_TEXTURE_2D, id);
    }

};

#endif //GAMEOFLIFE_OPENGL_TEXTURE_H
