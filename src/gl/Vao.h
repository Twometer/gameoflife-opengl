//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_VAO_H
#define GAMEOFLIFE_OPENGL_VAO_H


#include <glad/glad.h>

class Vao {
private:
    GLuint vao = 0;

    /**
     * Contains the vertex positions
     */
    GLuint vertexBuffer = 0;

    /**
     * May contain colors or textures
     * for the vertices
     */
    GLuint metaBuffer = 0;

    int vertexCount = 0;
    int dimensions = 0;

public:
    explicit Vao(int dimensions);

    ~Vao();

    void bind() const;

    void unbind() const;

    void set_data(float *vertexBuf, int vertexBufSize, float *metaBuf, int metaBufSize, int metaBufDimensions = 3);

    void render() const;

};


#endif //GAMEOFLIFE_OPENGL_VAO_H
