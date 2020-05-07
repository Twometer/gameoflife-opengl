//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_ISHADER_H
#define GAMEOFLIFE_OPENGL_ISHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class IShader {
protected:
    GLuint id = 0;

    void initialize(const std::string &vertex, const std::string &fragment);

    virtual void bind_uniforms() = 0;

    int get_location(const std::string &uniform);

    void load_matrix(int loc, glm::mat4 matrix);

    void load_float(int loc, float f);

    void load_vec2(int loc, glm::vec2 vec);

    void load_vec3(int loc, glm::vec3 vec);

    void load_vec4(int loc, glm::vec4 vec);

public:
    void bind();

    void unbind();

};


#endif //GAMEOFLIFE_OPENGL_ISHADER_H
