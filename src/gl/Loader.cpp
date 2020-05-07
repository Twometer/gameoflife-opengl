//
// Created by twome on 06/05/2020.
//

#include <fstream>
#include <spng.h>
#include <iostream>
#include "Loader.h"
#include "../util/Logger.h"
#include "../gui/font/FontReader.h"

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

uint8_t *Loader::read_bytes(const std::string &path, size_t &size) {
    std::ifstream file(path, std::ios::binary | std::ios::in);
    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    file.seekg(0, std::ios::beg);

    if (length == -1)
        return nullptr;

    auto *buf = new uint8_t[length];
    file.read((char *) buf, length);
    size = length;

    file.close();
    return buf;
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
    // Load PNG file from disk
    spng_ctx *ctx = spng_ctx_new(0);

    size_t inputSize;
    uint8_t *input = read_bytes(path, inputSize);
    int r = spng_set_png_buffer(ctx, input, inputSize);
    std::cout << spng_strerror(r) << std::endl;

    spng_ihdr ihdr{};
    r = spng_get_ihdr(ctx, &ihdr);
    std::cout << spng_strerror(r) << std::endl;

    size_t outputSize;
    r = spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &outputSize);
    std::cout << spng_strerror(r) << std::endl;

    auto *output = new uint8_t[outputSize];
    r = spng_decode_image(ctx, output, outputSize, SPNG_FMT_RGBA8, 0);
    std::cout << spng_strerror(r) << std::endl;

    delete[] input;

    // And upload it to the GPU
    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ihdr.width, ihdr.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, output);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    return {texture, ihdr.width, ihdr.height};
}

Font *Loader::load_font(const std::string &name) {
    std::string pngPath = "assets/fonts/" + name + ".png";
    std::string fntPath = "assets/fonts/" + name + ".fnt";

    std::ifstream stream(fntPath);
    Font *font = FontReader::read_font(stream);
    font->atlas = load_texture(pngPath);

    return font;
}
