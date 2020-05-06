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
    glVertexAttribPointer(0, dimensions, GL_FLOAT, false, 0, nullptr);

    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

    glBindVertexArray(0);

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
    glBufferData(GL_ARRAY_BUFFER, vertexBufSize * sizeof(float), vertexBuf, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, colorBufSize * sizeof(float), colorBuf, GL_DYNAMIC_DRAW);

    unbind();
    vertexCount = vertexBufSize / 3;
}

void Vao::render() {
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount / 3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindVertexArray(0);
}

Vao::~Vao() {
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &colorBuffer);

    glDeleteVertexArrays(1, &vao);
}
