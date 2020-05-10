#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ctime>
#include "util/Logger.h"
#include "render/GameWindow.h"

void scroll_callback(GLFWwindow *window, double xo, double yo) {
    GameWindow::get_instance()->on_scroll(glm::vec2(xo, yo));
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    GameWindow::get_instance()->on_viewport_changed(glm::vec2(width, height));
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        GameWindow::get_instance()->on_mouse_down();
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        GameWindow::get_instance()->on_mouse_up();
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    GameWindow::get_instance()->on_key_event(key, action);
}

void character_callback(GLFWwindow *window, unsigned int codepoint) {
    GameWindow::get_instance()->on_character_typed(codepoint);
}

int main() {
    // Seed the randomizer
    srand(time(NULL));

    // Load GLFW
    Logger::info("Initializing rendering context...");
    if (!glfwInit()) {
        Logger::error("Failed to initialize GLFW");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(1024, 768, "Conway's Game Of Life", nullptr, nullptr);
    if (!window) {
        Logger::error("Failed to create GLFW window");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL with glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        Logger::error("Failed to load OpenGL");
        glfwTerminate();
        return 1;
    }

    // Register window callbacks
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCharCallback(window, character_callback);
    glfwSetKeyCallback(window, key_callback);

    // Initialize game window
    auto gameWindow = GameWindow::get_instance();
    gameWindow->set_glfw_handle(window);

    // And its size
    int viewportWidth, viewportHeight;
    glfwGetFramebufferSize(window, &viewportWidth, &viewportHeight);
    gameWindow->on_viewport_changed(glm::vec2(viewportWidth, viewportHeight));
    gameWindow->on_startup();

    Logger::info("Init complete, starting game");

    // Then start the game
    while (!glfwWindowShouldClose(window) && !gameWindow->should_close()) {
        gameWindow->draw_frame();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete gameWindow;

    return 0;
}
