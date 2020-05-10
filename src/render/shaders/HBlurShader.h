//
// Created by Twometer on 20/12/2019.
//

#ifndef GAMEOFLIFE_OPENGL_HBLURSHADER_H
#define GAMEOFLIFE_OPENGL_HBLURSHADER_H

#include "IShader.h"

class HBlurShader : public IShader {

private:
    GLuint loc_targetWidth;

public:
    HBlurShader() {
        initialize("hblur", "blur");
    }

    void bind_uniforms() override {
        loc_targetWidth = glGetUniformLocation(id, "targetWidth");
    }

    void set_target_width(float targetWidth) {
        glUniform1f(loc_targetWidth, targetWidth);
    }

};

#endif //GAMEOFLIFE_OPENGL_HBLURSHADER_H
