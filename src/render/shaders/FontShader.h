//
// Created by twome on 07/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_FONTSHADER_H
#define GAMEOFLIFE_OPENGL_FONTSHADER_H

#include "IShader.h"

class FontShader : public IShader {
private:
    GLuint loc_projectionMatrix;
    GLuint loc_color;

public:
    FontShader() {
        initialize("font", "font");
    }

    void bind_uniforms() override {
        loc_projectionMatrix = get_location("projectionMatrix");
        loc_color = get_location("color");
    }

    void set_projection_matrix(glm::mat4 matrix) {
        load_matrix(loc_projectionMatrix, matrix);
    }

    void set_color(glm::vec4 color) {
        load_vec4(loc_color, color);
    }

};

#endif //GAMEOFLIFE_OPENGL_FONTSHADER_H
