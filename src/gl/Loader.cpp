//
// Created by twome on 06/05/2020.
//

#include <fstream>
#include "Loader.h"
#include "../util/Logger.h"

void Loader::check_shader(const std::string &name, GLuint shader) {
    int infoLogLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
        char errorMsg[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, nullptr, errorMsg);
        Logger::error(name + ": " + std::string(errorMsg));
    }
}

std::string Loader::read_text(const std::string &path) {
    std::ifstream stream(path);
    std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    return content;
}

GLuint Loader::load_shader(const std::string &vertex, const std::string &fragment) {
    Logger::info("Loading shader '" + vertex + "/" + fragment + "'");

    std::string vertexSource = read_text("assets/shaders/" + vertex + ".v.glsl");
    std::string fragmentSource = read_text("assets/shaders/" + fragment + ".f.glsl");

    if (vertexSource.length() == 0 || fragmentSource.length() == 0) {
        Logger::error("Failed to load shader");
        return 0;
    }

    auto vertexSourcePtr = vertexSource.c_str();
    auto fragmentSourcePtr = fragmentSource.c_str();

    auto program = glCreateProgram();

    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSourcePtr, nullptr);
    glCompileShader(vertexShader);
    check_shader(vertex, vertexShader);

    auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSourcePtr, nullptr);
    glCompileShader(fragmentShader);
    check_shader(fragment, fragmentShader);

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

Texture Loader::load_texture(const std::string &path) {
    return Texture();
}
