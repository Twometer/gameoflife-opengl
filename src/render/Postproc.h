//
// Created by Twometer on 20/12/2019.
//

#ifndef GAMEOFLIFE_OPENGL_POSTPROC_H
#define GAMEOFLIFE_OPENGL_POSTPROC_H


#include "../gl/Fbo.h"

class Postproc {
private:
    static GLuint vao;

public:
    static void initialize();

    static void start();

    static void stop();

    static void copy(Fbo *src, Fbo *dst);
};


#endif //GAMEOFLIFE_OPENGL_POSTPROC_H
