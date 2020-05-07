//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_VAO_H
#define GAMEOFLIFE_OPENGL_VAO_H


#include <glad/glad.h>

class Vao {
private:
    GLuint vao = 0;

    GLuint vertexBuffer = 0;
    GLuint colorBuffer = 0;

    int vertexCount = 0;
    int dimensions = 0;

public:
    explicit Vao(int dimensions);

    ~Vao();

    void bind();

    void unbind();

    void set_data(float* vertexBuf, int vertexBufSize, float* colorBuf, int colorBufSize);

    void render();

};


#endif //GAMEOFLIFE_OPENGL_VAO_H
