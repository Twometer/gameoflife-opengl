#version 330 core

in vec2 fragmentUv;
out vec4 outColor;

uniform sampler2D colorTexture;

void main(void) {
    outColor = texture(colorTexture, fragmentUv);
}