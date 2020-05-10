//
// Created by twome on 06/05/2020.
//

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "GameWindow.h"
#include "../io/AssetLoader.h"
#include "../gui/screens/MenuScreen.h"
#include "../gui/dialogs/SettingsDialog.h"

GameWindow *GameWindow::instance = nullptr;

GameWindow::GameWindow() : fontRenderer(FontRenderer(AssetLoader::load_font("nirmala"))), generationTimer(20),
                           updateTimer(60) {
    ingameGui = new IngameGuiScreen();
    ingameGui->btnPlayPause->set_click_listener([this]() {
        if (generationTimer.is_paused()) {
            ingameGui->btnPlayPause->set_texture("pause");
            generationTimer.resume();
        } else {
            ingameGui->btnPlayPause->set_texture("play");
            generationTimer.pause();
        }
    });
    ingameGui->btnNextGen->set_click_listener([this]() {
        next_generation();
    });
    ingameGui->btnBack->set_click_listener([this]() {
        show_demo_scene();
        guiRenderer.show_screen(new MenuScreen());
    });
    ingameGui->btnNew->set_click_listener([this]() {
        if (field != nullptr) {
            field->clear();
            field->remesh();
            update_stats();
        }
    });
    ingameGui->btnSettings->set_click_listener([this]() {
       guiRenderer.show_dialog(new SettingsDialog());
    });

    standardCursor = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    ibeamCursor = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    show_demo_scene();
}

GameWindow::~GameWindow() {
    delete field;
}

void GameWindow::draw_frame() {
    glViewport(0, 0, viewportSize.x, viewportSize.y);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.update();

    basicShader.bind();
    basicShader.set_camera_matrix(camera.get_matrix());
    field->render();

    if (generationTimer.elapsed()) {
        next_generation();
        generationTimer.reset();
    }

    if (updateTimer.elapsed()) {
        handle_input();
        updateTimer.reset();
    }

    guiRenderer.draw();
}

void GameWindow::handle_input() {
    bool focused = glfwGetWindowAttrib(glfwHandle, GLFW_FOCUSED) == GLFW_TRUE;
    if (!focused) return;

    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);


    static double mouseXLast, mouseYLast;
    if ((mouseXLast != mouseX || mouseYLast != mouseY)) {

        guiRenderer.on_mouse_move(glm::vec2(mouseX, mouseY));

        if (glfwGetMouseButton(glfwHandle, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && !guiRenderer.is_input_blocked()) {
            glm::vec2 offset = glm::vec2(-(mouseX - mouseXLast) / viewportSize.x * camera.get_size().x,
                                         (mouseY - mouseYLast) / viewportSize.y * camera.get_size().y);
            camera.move_midpoint(offset);
        }
    }

    mouseXLast = mouseX;
    mouseYLast = mouseY;
}

void GameWindow::on_startup() {
    guiRenderer.show_screen(new MenuScreen());
}

void GameWindow::on_scroll(glm::vec2 offset) {
    if (guiRenderer.is_input_blocked())
        return;
    camera.zoom += offset.y * glm::sqrt(camera.zoom.get_value() / 1280.0f);
    camera.zoom.clamp_to(0.001, 0.1);
}

void GameWindow::on_viewport_changed(glm::vec2 newSize) {
    this->viewportSize = newSize;
    guiMatrix = glm::ortho(0.0f, viewportSize.x, viewportSize.y, 0.0f);
    guiRenderer.layout();
}

void GameWindow::on_mouse_down() {
    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);
    guiRenderer.on_mouse_down(glm::vec2(mouseX, mouseY));
}

void GameWindow::on_mouse_up() {
    double mouseX, mouseY;
    glfwGetCursorPos(glfwHandle, &mouseX, &mouseY);

    auto mousePos = glm::vec2(mouseX, mouseY);
    if (!guiRenderer.is_input_blocked())
        toggle_cell(mousePos);
    guiRenderer.on_mouse_up(mousePos);
}

void GameWindow::on_character_typed(uint32_t codepoint) {
    guiRenderer.on_character_typed(codepoint);
}

void GameWindow::on_key_event(int key, int action) {
    guiRenderer.on_key_event(key, action);
}

void GameWindow::set_glfw_handle(GLFWwindow *glfwHandle) {
    this->glfwHandle = glfwHandle;
}

GameWindow *GameWindow::get_instance() {
    if (instance == nullptr)
        instance = new GameWindow();
    return instance;
}

glm::mat4 GameWindow::get_gui_matrix() {
    return guiMatrix;
}

glm::vec2 GameWindow::get_viewport_size() {
    return viewportSize;
}

GuiRenderer *GameWindow::get_gui_renderer() {
    return &guiRenderer;
}

FontRenderer *GameWindow::get_font_renderer() {
    return &fontRenderer;
}

bool GameWindow::should_close() const {
    return shouldClose;
}

void GameWindow::close() {
    shouldClose = true;
}

void GameWindow::set_cursor(Cursor cursor) {
    if (cursor != currentCursor) {
        currentCursor = cursor;

        if (cursor == Cursor::STANDARD)
            glfwSetCursor(glfwHandle, standardCursor);
        else if (cursor == Cursor::IBEAM)
            glfwSetCursor(glfwHandle, ibeamCursor);
    }
}

void GameWindow::set_field(Field *field) {
    delete this->field;
    this->field = field;

    update_stats();
    center_camera();
}

void GameWindow::show_ingame_gui() {
    guiRenderer.show_screen(ingameGui);
    generationTimer.pause();
}

void GameWindow::next_generation() {
    field->tick();      // Next generation
    field->remesh();    // Rebuild mesh

    update_stats();     // Update status labels
}

void GameWindow::update_stats() {
    ingameGui->lbLivingCells->set_text("Cells: " + std::to_string(field->get_living_cells()));
    ingameGui->lbGeneration->set_text("Gen: " + std::to_string(field->get_generation()));
    guiRenderer.layout();
}

void GameWindow::center_camera() {
    auto size = field->get_size();
    camera.set_midpoint(glm::vec2(size.x, size.y) * 0.5f);
}

void GameWindow::toggle_cell(glm::vec2 mousePos) {
    // Find zero point in screen space by projecting (0|0) with the matrix
    glm::vec2 zeroPoint = (camera.get_matrix() * glm::vec4(0, 0, 0.0f, 1.0f) +
                           glm::vec4(1.0f, 1.0f, 0.0f, 0.0f)) * 0.5f;

    // Using that offset, unproject again to find mouse position in field space
    int fieldX = glm::floor((mousePos.x / viewportSize.x - zeroPoint.x) * camera.get_size().x);
    // Y mouse is inverted (OpenGL coordinate system is inverted to ours), so 1 - mousePos
    int fieldY = glm::floor(((1 - mousePos.y / viewportSize.y) - zeroPoint.y) * camera.get_size().y);

    // Check if that click was inside the field
    if (fieldX >= 0 && fieldY >= 0 && fieldX < field->get_size().x && fieldY < field->get_size().y) {
        field->toggle_cell(fieldX, fieldY);
        field->remesh();
    }
}

void GameWindow::show_demo_scene() {
    auto field = new Field(128, 128);
    field->randomize(4);
    field->remesh();

    camera.zoom = .01f;

    generationTimer.resume();
    set_field(field);
    center_camera();
}




