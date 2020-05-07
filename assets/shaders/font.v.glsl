#version 330 core

// This vec4 packs the location in XY and the texture coordinates in ZW
layout(location = 0) in vec4 data;

out vec2 textureCoords;

uniform mat4 projectionMatrix;

void main(void) {
    gl_Position = projectionMatrix * vec4(data.xy, 0.0, 1.0);
    textureCoords = data.zw;
}