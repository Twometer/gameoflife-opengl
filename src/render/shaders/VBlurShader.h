//
// Created by Twometer on 20/12/2019.
//

#ifndef GAMEOFLIFE_OPENGL_VBLURSHADER_H
#define GAMEOFLIFE_OPENGL_VBLURSHADER_H

#include "IShader.h"

class VBlurShader : public IShader {

private:
    GLuint loc_targetHeight;

public:
    VBlurShader() {
        initialize("vblur", "blur");
    }

    void bind_uniforms() override {
        loc_targetHeight = glGetUniformLocation(id, "targetHeight");
    }

    void set_target_height(float targetHeight) {
        glUniform1f(loc_targetHeight, targetHeight);
    }

};

#endif //GAMEOFLIFE_OPENGL_HGAUSSSHADER_H
