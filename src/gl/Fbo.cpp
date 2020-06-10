//
// Created by twome on 11/05/2020.
//

#include "Fbo.h"
#include "../render/GameWindow.h"

Fbo::Fbo(int width, int height) : width(width), height(height) {
    create_framebuffer();
    create_tex_attachment();
}

Fbo::~Fbo() {
    glDeleteFramebuffers(1, &frameBuffer);
    glDeleteTextures(1, &colorTexture);
    glDeleteRenderbuffers(1, &colorBuffer);
}

void Fbo::bind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glViewport(0, 0, width, height);
}

void Fbo::unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glm::vec2 viewportSize = GameWindow::get_instance()->get_viewport_size();
    glViewport(0, 0, viewportSize.x, viewportSize.y);
}

GLuint Fbo::get_color_texture() const {
    return colorTexture;
}

int Fbo::get_width() const {
    return width;
}

int Fbo::get_height() const {
    return height;
}

void Fbo::create_framebuffer() {
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glDrawBuffer(GL_COLOR_ATTACHMENT0);
}

void Fbo::create_tex_attachment() {
    glGenTextures(1, &colorTexture);
    glBindTexture(GL_TEXTURE_2D, colorTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);
}
