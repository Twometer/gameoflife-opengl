#version 330 core

layout(location = 0) in vec2 pos;
layout(location = 1) in vec3 color;

out vec3 fragmentColor;

uniform mat4 cameraMatrix;

void main(void) {
    gl_Position = cameraMatrix * vec4(pos.xy, 0.0f, 1.0f);
    fragmentColor = color;
}