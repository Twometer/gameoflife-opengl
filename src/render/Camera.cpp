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

    projectionMatrix = glm::ortho(-camWidth / 2.f, +camWidth / 2.f, -camHeight / 2.f, +camHeight / 2.f);
}

glm::mat4 Camera::get_matrix() {
    return projectionMatrix * viewMatrix;
}

// Initialize matrices to identity
Camera::Camera() : viewMatrix(1.0f), projectionMatrix(1.0f) {

}

void Camera::set_midpoint(glm::vec2 midpoint) {

}
