#pragma once
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct Vertex
{
	float x, y, z;
	float r, g, b;
	float u, v;

};
class Construct
{
public:
	std::array<Vertex, 36> Cube(glm::vec3 Color);
	std::array<Vertex, 36> Table(glm::vec3 Color);
	std::array<Vertex, 48> House(glm::vec3 Color);
	std::array<Vertex, 6> NotAPlane( glm::vec3 Color);
};

