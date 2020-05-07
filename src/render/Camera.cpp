//
// Created by twome on 06/05/2020.
//

#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "GameWindow.h"

void Camera::update() {
    auto window = GameWindow::get_instance();

    zoom.update();

    // Calculate camera size depending on the zoom value
    // but keeping the aspect ratio
    auto aspectRatio = window->get_viewport_size().y / window->get_viewport_size().x;
    auto camWidth = 1.0f / zoom.get_value();
    auto camHeight = camWidth * aspectRatio;

    sizeInWorld = glm::vec2(camWidth, camHeight);

    projectionMatrix = glm::ortho(-camWidth / 2.f + midpoint.x, +camWidth / 2.f + midpoint.x,
                                  -camHeight / 2.f + midpoint.y, +camHeight / 2.f + midpoint.y);
}

glm::mat4 Camera::get_matrix() {
    return projectionMatrix;
}

// Initialize matrix to identity
Camera::Camera() : projectionMatrix(1.0f) {

}

void Camera::set_midpoint(glm::vec2 midpoint) {
    this->midpoint = midpoint;
}

void Camera::move_midpoint(glm::vec2 offset) {
    this->midpoint += offset;
}

glm::vec2 Camera::get_size() {
    return sizeInWorld;
}
