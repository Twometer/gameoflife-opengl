//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_BASICSHADER_H
#define GAMEOFLIFE_OPENGL_BASICSHADER_H

#include "IShader.h"

class BasicShader : public IShader {
private:
    GLuint loc_cameraMatrix;

public:
    BasicShader() {
        initialize("basic", "basic");
    }

    void bind_uniforms() override {
        loc_cameraMatrix = get_location("cameraMatrix");
    }

    void set_camera_matrix(glm::mat4 matrix){
        load_matrix(loc_cameraMatrix, matrix);
    }

};

#endif //GAMEOFLIFE_OPENGL_BASICSHADER_H
