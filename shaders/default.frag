#version 120
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec4 objectColor;

uniform vec3 ambientColor;
uniform vec3 diffuseColor;
uniform vec3 specularColor;
uniform float shininess;

varying vec3 FragPos;
varying vec3 Normal;

void main() {
    // 1. Ambiant
    vec3 ambient = ambientColor * vec3(objectColor);

    // 2. Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diffuseColor * diff * vec3(objectColor);

    // 3. Speculaire
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularColor * spec;

    vec3 result = ambient + diffuse + specular;
    gl_FragColor = vec4(result, objectColor.a);
}