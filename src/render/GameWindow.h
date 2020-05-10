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

    Timer updateTimer;      // This timer checks input data and updates animations at a constant rate
    Timer generationTimer;  // This timer calculates the next GOL generation after a given time

    glm::vec2 viewportSize;
    glm::mat4 guiMatrix;

    GuiRenderer guiRenderer;
    FontRenderer fontRenderer;

    GLFWcursor *standardCursor;
    GLFWcursor *ibeamCursor;
    Cursor currentCursor = Cursor::STANDARD;

    bool shouldClose;

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

    void on_character_typed(uint32_t codepoint);

    void on_key_event(int key, int action);

    void set_glfw_handle(GLFWwindow *glfwHandle);

    glm::vec2 get_viewport_size();

    glm::mat4 get_gui_matrix();

    GuiRenderer *get_gui_renderer();

    FontRenderer *get_font_renderer();

    bool should_close();

    void close();

    void set_cursor(Cursor cursor);

    void set_field(IField *field);

private:
    void handle_input();

    void center_camera();
};


#endif //GAMEOFLIFE_OPENGL_GAMEWINDOW_H
