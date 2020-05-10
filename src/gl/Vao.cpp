//
// Created by twome on 06/05/2020.
//

#include "Vao.h"

Vao::Vao(int dimensions) {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &colorBuffer);

    glBindVertexArray(0);

    this->dimensions = dimensions;
}

void Vao::bind() const {
    glBindVertexArray(vao);
}

void Vao::unbind() const {
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

void Vao::render() const {
    if (vertexCount == 0)
        return;

    bind();

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    unbind();
}

Vao::~Vao() {
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &colorBuffer);

    glDeleteVertexArrays(1, &vao);
}
