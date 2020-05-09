//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_GAMEWINDOW_H
#define GAMEOFLIFE_OPENGL_GAMEWINDOW_H


#include <glm/glm.hpp>
#include "../model/IField.h"
#include "Camera.h"
#include "shaders/BasicShader.h"
#include "../gui/font/FontRenderer.h"
#include "../util/Timer.h"
#include "../gui/GuiRenderer.h"
#include <GLFW/glfw3.h>

class GameWindow {
private:
    static GameWindow *instance;

    GLFWwindow *glfwHandle;

    IField *field;

    Camera camera;

    BasicShader basicShader;

    Timer timer;

    glm::vec2 viewportSize;
    glm::mat4 guiMatrix;

    GuiRenderer guiRenderer;
    FontRenderer fontRenderer;

    GameWindow();
public:
    static GameWindow *get_instance();

    ~GameWindow();

    void draw_frame();

    void on_startup();

    void on_scroll(glm::vec2 offset);

    void on_viewport_changed(glm::vec2 newSize);

    void on_mouse_down();

    void on_mouse_up();

    void set_glfw_handle(GLFWwindow *glfwHandle);

    glm::vec2 get_viewport_size();

    glm::mat4 get_gui_matrix();

    GuiRenderer *get_gui_renderer();

    FontRenderer *get_font_renderer();

private:
    void handle_input();
};


#endif //GAMEOFLIFE_OPENGL_GAMEWINDOW_H
