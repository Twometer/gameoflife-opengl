//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_TEXTUREDSHADER_H
#define GAMEOFLIFE_OPENGL_TEXTUREDSHADER_H

#include "IShader.h"

class TexturedShader : public IShader {
private:
    GLuint loc_cameraMatrix;

public:
    TexturedShader() {
        initialize("textured", "textured");
    }

    void bind_uniforms() override {
        loc_cameraMatrix = get_location("cameraMatrix");
    }

    void set_camera_matrix(glm::mat4 matrix) {
        load_matrix(loc_cameraMatrix, matrix);
    }

};

#endif //GAMEOFLIFE_OPENGL_TEXTUREDSHADER_H
