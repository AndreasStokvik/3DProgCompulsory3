#include "Table.h"

void Table::ConstructVBO()
{
	vao.Bind();
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.Unbind();
	vao.Unbind();
}

void Table::DeleteVBOANDVAO()
{
	vao.Delete();
}

void Table::UnbindVAO()
{
	vao.Unbind();
}

void Table::BindVAO()
{
	vao.Bind();
}

VBO Table::GetVBO()
{
	return vbo;
}
