#version 120
// Compatibilité GLSL 1.20 pour correspondre à votre code actuel
attribute vec3 position;
attribute vec3 normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

varying vec3 FragPos;
varying vec3 Normal;

void main() {
    FragPos = vec3(modelMatrix * vec4(position, 1.0));

    // Extraction de la matrice normale pour transformer les normales sans l'échelle
    mat3 normalMatrix = mat3(
        modelMatrix[0].xyz,
        modelMatrix[1].xyz,
        modelMatrix[2].xyz
    );
    Normal = normalMatrix * normal;

    gl_Position = projectionMatrix * viewMatrix * vec4(FragPos, 1.0);
}