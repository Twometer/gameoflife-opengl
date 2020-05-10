//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GRAPHICS_H
#define GAMEOFLIFE_OPENGL_GRAPHICS_H


#include "../gl/MeshBuilder.h"
#include "font/FontRenderer.h"
#include "../gl/Vao.h"
#include "../render/shaders/BasicShader.h"

class Graphics {
private:
    Vao *vao;
    MeshBuilder *builder;

    BasicShader *guiShader;

    glm::vec2 origin;

public:
    Graphics(Vao *vao, MeshBuilder *builder, BasicShader *guiShader, const glm::vec2 &origin);

    void begin();

    void push_rectangle(float x, float y, float width, float height, glm::vec3 color);

    void draw_text(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

    void draw_centered_text(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

    void end();

    Graphics create_offset(glm::vec2 offset);
};


#endif //GAMEOFLIFE_OPENGL_GRAPHICS_H
