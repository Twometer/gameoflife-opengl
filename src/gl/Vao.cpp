//
// Created by twome on 06/05/2020.
//

#include "Vao.h"

Vao::Vao(int dimensions) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);

    glBindVertexArray(0);

    this->dimensions = dimensions;
    this->vao = vao;
    this->vertexBuffer = vertexBuffer;
    this->colorBuffer = colorBuffer;
}

void Vao::bind() {
    glBindVertexArray(vao);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

void Vao::set_data(float *vertexBuf, int vertexBufSize, float *colorBuf, int colorBufSize) {
    bind();
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexBufSize * sizeof(GLfloat), vertexBuf, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, dimensions, GL_FLOAT, false, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, colorBufSize * sizeof(GLfloat), colorBuf, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, nullptr);

    unbind();
    vertexCount = vertexBufSize / dimensions;
}

void Vao::render() {
    if (vertexCount == 0)
        return;

    bind();

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount / 3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    unbind();
}

Vao::~Vao() {
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &colorBuffer);

    glDeleteVertexArrays(1, &vao);
}
