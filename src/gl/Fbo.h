//
// Created by twome on 11/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FBO_H
#define GAMEOFLIFE_OPENGL_FBO_H

#include <glad/glad.h>

class Fbo {
private:
    int width;
    int height;

    GLuint frameBuffer = 0;
    GLuint colorBuffer = 0;

    GLuint colorTexture = 0;

public:
    Fbo(int width, int height);

    ~Fbo();

    void bind();

    void unbind();

    GLuint get_color_texture();

    int get_width();

    int get_height();

private:
    void create_framebuffer();

    void create_tex_attachment();

};


#endif //GAMEOFLIFE_OPENGL_FBO_H
