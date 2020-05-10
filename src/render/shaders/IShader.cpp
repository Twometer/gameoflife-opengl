//
// Created by twome on 06/05/2020.
//

#include "IShader.h"
#include "../../io/AssetLoader.h"

int IShader::get_location(const std::string &uniform) {
    return glGetUniformLocation(id, uniform.c_str());
}


void IShader::load_matrix(int loc, glm::mat4 matrix) {
    glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
}

void IShader::load_float(int loc, float f) {
    glUniform1f(loc, f);
}

void IShader::load_vec2(int loc, glm::vec2 vec) {
    glUniform2f(loc, vec.x, vec.y);
}

void IShader::load_vec3(int loc, glm::vec3 vec) {
    glUniform3f(loc, vec.x, vec.y, vec.z);
}

void IShader::load_vec4(int loc, glm::vec4 vec) {
    glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
}

void IShader::unbind() {
    glUseProgram(0);
}

void IShader::bind() {
    glUseProgram(id);
}

void IShader::initialize(const std::string &vertex, const std::string &fragment) {
    id = AssetLoader::load_shader(vertex, fragment);
    bind_uniforms();
}

