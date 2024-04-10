#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Resources/Shaders/VBO.h"
#include "Resources/Shaders/VAO.h"
class Table
{


    struct Vertex {
        float x, y, z, r, g, b;
    };

private:
    std::vector<Vertex> mVertecies;
public:
    std::vector<GLfloat> vertices;
    float speedX = 0.010f;


    float sphere_center_x = 0;
    float sphere_center_y = 0;
    float sphere_center_z = 0;
    float sphere_radius = 0;
    VAO vao; 
    VBO vbo;


    Table(float scale, float x, float y, float z) : a(scale)
    {
        // Define the dimensions of the table
        Vertex v0{ x - a, y - a, z + a , 1.0f, 0.3f, 0.0f };
        Vertex v1{ x + a, y - a, z + a , 1.0f, 0.2f, 0.1f };
        Vertex v2{ x + a, y + a, z + a , 1.0f, 0.0f, 0.0f };
        Vertex v3{ x - a, y + a, z + a , 0.0f, 1.0f, 0.0f };
        Vertex v4{ x - a, y - a, z - a , 1.0f, 0.0f, 0.8f };
        Vertex v5{ x + a, y - a, z - a , 0.5f, 0.0f, 0.0f };
        Vertex v6{ x + a, y + a, z - a , 0.0f, 0.4f, 0.0f };
        Vertex v7{ x - a, y + a, z - a , 1.0f, 0.0f, 1.0f };

        Vertex v8{ x - (3 * a), y + a, z + (4 * a) , 0.0f, 1.0f, 0.0f };
        Vertex v9{ x + (3 * a), y + a, z + (4 * a) , 1.0f, 0.0f, 0.0f };
        Vertex v10{ x - (3 * a), y + a, z - (4 * a) , 1.0f, 0.0f, 1.0f };
        Vertex v11{ x + (3 * a), y + a, z - (4 * a) , 0.0f, 0.4f, 0.0f };


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
        mVertecies.push_back(v8);
        mVertecies.push_back(v9);
        mVertecies.push_back(v10);
        mVertecies.push_back(v10);
        mVertecies.push_back(v9);
        mVertecies.push_back(v11);

        // Bottom face
        mVertecies.push_back(v4);
        mVertecies.push_back(v5);
        mVertecies.push_back(v0);
        mVertecies.push_back(v0);
        mVertecies.push_back(v5);
        mVertecies.push_back(v1);


        // Calculate sphere parameters for collision detection if needed
        sphere_center_x = x;
        sphere_center_y = y;
        sphere_center_z = z;
        sphere_radius = a * 6;

        // Initialize VBO after populating mVertices
        vertices = flattenVertices(mVertecies);
        if (!mVertecies.empty())
            vbo = VBO(vertices.data(), vertices.size() * sizeof(GLfloat));
    }

    void ConstructVBO();

    void DeleteVBOANDVAO();
    void UnbindVAO();
    void BindVAO();
    VBO GetVBO();

private:
    float a{ 1.0f };



    std::vector<GLfloat> flattenVertices(std::vector<Vertex> mvert) {
        std::vector<GLfloat> flattenedVertices;
        for (const Vertex& vertex : mvert) {
            flattenedVertices.push_back(vertex.x);
            flattenedVertices.push_back(vertex.y);
            flattenedVertices.push_back(vertex.z);
            flattenedVertices.push_back(vertex.r);
            flattenedVertices.push_back(vertex.g);
            flattenedVertices.push_back(vertex.b);
        }
        return flattenedVertices;
    }

};

