#include "Pokal.h"



float Pokal::GetA()
{
	return a;
}

void Pokal::ConstructVBO(std::vector<GLfloat> flattenedVertices, bool update)
{
	if (update) {
		VBO1.UpdateData(flattenedVertices.data(), flattenedVertices.size() * sizeof(GLfloat));
	}
	else {
		VAO5.Bind();
		VBO1.UpdateData(flattenedVertices.data(), flattenedVertices.size() * sizeof(GLfloat));
		VAO5.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
		VAO5.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO5.Unbind();
		VBO1.Unbind();
	}
	
}

void Pokal::DeleteVBOANDVAO()
{
	VAO5.Delete();
	
}

void Pokal::UnbindVAO()
{
	VAO5.Unbind();
}

void Pokal::BindVAO()
{
	VAO5.Bind();
}

VBO Pokal::GetVBO()
{
	return VBO1;
}

void Pokal::UpdateVertices(float Xspeed, float Yspeed, float Zspeed)
{
	for (VertexPokal& vertex : mVertecies) {
		vertex.x += Xspeed;
		vertex.y += Yspeed;
		vertex.z += Zspeed;

	}

	VBO1.UpdateData(getFlattenedVertices().data(), getFlattenedVertices().size() * sizeof(GLfloat));
}

std::vector<GLfloat> Pokal::getFlattenedVertices() const
{
	std::vector<GLfloat> flattenedVertices;
	for (const VertexPokal& vertex : mVertecies) {
		flattenedVertices.push_back((vertex.x * scaleX) + position.x);
		flattenedVertices.push_back((vertex.y * scaleY) + position.y);
		flattenedVertices.push_back((vertex.z * scaleZ) + position.z);
		flattenedVertices.push_back(vertex.r);
		flattenedVertices.push_back(vertex.g);
		flattenedVertices.push_back(vertex.b);
	}
	
	return flattenedVertices;
}




void Pokal::flattenVertices()
{
	std::vector<GLfloat> flattenedVertices;
	for (const VertexPokal& vertex : mVertecies) {
		flattenedVertices.push_back((vertex.x * scaleX) + position.x);
		flattenedVertices.push_back((vertex.y * scaleY) + position.y);
		flattenedVertices.push_back((vertex.z * scaleZ) + position.z);
		flattenedVertices.push_back(vertex.r);
		flattenedVertices.push_back(vertex.g);
		flattenedVertices.push_back(vertex.b);
	}
}
