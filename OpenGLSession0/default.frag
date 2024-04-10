#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
in vec2 TexCoords;

// Uniforms
uniform sampler2D ourTexture;

struct Material
{
	vec3 diffuse;
};

void main()
{
	Material mat;
	mat.diffuse = vec3(texture(ourTexture, TexCoords));
	vec3 finalColor = mat.diffuse * color;

	FragColor = vec4(finalColor, 1.0f);
}