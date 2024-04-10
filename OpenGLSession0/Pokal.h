#pragma once
#include "Resources/Shaders/VBO.h"
#include "Resources/Shaders/VAO.h"
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Player.h"

class Player;


using namespace std;
struct VertexPokal
{
	float x, y, z;
	float r, g, b;
};
class Pokal {
public:
	vector<VertexPokal> mVertecies;
	glm::vec3 position;
	float scaleX, scaleY, scaleZ;
	float r, g, b;
	float sphere_center_x = 0;
	float sphere_center_y = 0;
	float sphere_center_z = 0;
	float sphere_radius = 0;
	std::string name;
	glm::vec3 velocity;
	VAO VAO5;
	VBO VBO1;

	std::vector<GLfloat> flattenedVertices1;
	Pokal(float scale, const glm::vec3& initialPosition = glm::vec3(0.0f, 0.0f, 0.0f), float scaleX = 1.0f, float scaleY = 1.0f, float scaleZ = 1.0f, float red = 1.0f, float green = 1.0f, float blue = 1.0f)
		: a(scale), position(initialPosition), scaleX(scaleX), scaleY(scaleY), scaleZ(scaleZ), velocity(glm::vec3(0.0f)), r(red), g(green), b(blue) {
		VertexPokal v0{ -a, -a, a , r, g, b };
		VertexPokal v1{ a, -a, a , r, g, b };
		VertexPokal v2{ a, a, a , r, g, b };
		VertexPokal v3{ -a, a, a ,  r, g, b };
		VertexPokal v4{ -a, -a, -a ,  r, g, b };
		VertexPokal v5{ a, -a, -a ,  r, g, b };
		VertexPokal v6{ a, a, -a ,  r, g, b };
		VertexPokal v7{ -a, a, -a , r, g, b };


		// Front face

		mVertecies.push_back(v0);
		mVertecies.push_back(v1);
		mVertecies.push_back(v3);
		mVertecies.push_back(v3);
		mVertecies.push_back(v1);
		mVertecies.push_back(v2);



		// Back face
		mVertecies.push_back(v4);
		mVertecies.push_back(v5);
		mVertecies.push_back(v7);
		mVertecies.push_back(v7);
		mVertecies.push_back(v5);
		mVertecies.push_back(v6);

		// Right face
		mVertecies.push_back(v1);
		mVertecies.push_back(v5);
		mVertecies.push_back(v2);
		mVertecies.push_back(v2);
		mVertecies.push_back(v5);
		mVertecies.push_back(v6);

		// Left face
		mVertecies.push_back(v4);
		mVertecies.push_back(v0);
		mVertecies.push_back(v7);
		mVertecies.push_back(v7);
		mVertecies.push_back(v0);
		mVertecies.push_back(v3);

		// Top face
		mVertecies.push_back(v3);
		mVertecies.push_back(v2);
		mVertecies.push_back(v7);
		mVertecies.push_back(v7);
		mVertecies.push_back(v2);
		mVertecies.push_back(v6);

		// Bottom face
		mVertecies.push_back(v4);
		mVertecies.push_back(v5);
		mVertecies.push_back(v0);
		mVertecies.push_back(v0);
		mVertecies.push_back(v5);
		mVertecies.push_back(v1);

		sphere_center_x = initialPosition.x;
		sphere_center_y = initialPosition.y;
		sphere_center_z = initialPosition.z;
		sphere_radius = 1.f;


		flattenVertices();
	}
	float GetA();
	void ConstructVBO(std::vector<GLfloat> flattenedVertices, bool update);
	void DeleteVBOANDVAO();
	void UnbindVAO();
	void BindVAO();
	VBO GetVBO();
	void UpdateVertices(float Xspeed, float Yspeed, float Zspeed);
	
	std::vector<GLfloat> getFlattenedVertices() const;
	void flattenVertices();
	
private:
	float a{1.0f};



};