#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ctime>
#include "util/Logger.h"
#include "render/GameWindow.h"

int main() {
    srand(time(NULL)); // Seed the randomizer

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

    GLFWwindow *window = glfwCreateWindow(1024, 768, "Conway's Game Of Life", nullptr, nullptr);
    if (!window) {
        Logger::error("Failed to create GLFW window");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        Logger::error("Failed to initialize OpenGL");
        glfwTerminate();
        return 1;
    }

    Logger::info("Init complete, starting game");

    auto gameWindow = GameWindow::get_instance();
    while (!glfwWindowShouldClose(window)) {
        gameWindow->draw_frame();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete gameWindow;

    return 0;
}
