#include "Construct.h"

std::array<Vertex, 36> Construct::Cube(glm::vec3 Color)
{
    std::array<Vertex, 36> CubeArray;
    glm::vec3 sizeXYZ = glm::vec3(1.f, 1.f, 1.f);
    // Front face vertices
    Vertex v0{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v1{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Right face vertices
    Vertex v4{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v5{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v6{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v7{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Back face vertices
    Vertex v8{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v9{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v10{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v11{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Left face vertices
    Vertex v12{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v13{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v14{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v15{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Top face vertices
    Vertex v16{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v17{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v18{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v19{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Bottom face vertices
    Vertex v20{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v21{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v22{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v23{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };
    // Assign vertices to CubeArray
    CubeArray[0] = v0;
    CubeArray[1] = v1;
    CubeArray[2] = v2;
    CubeArray[3] = v2;
    CubeArray[4] = v3;
    CubeArray[5] = v0;
    CubeArray[6] = v4;
    CubeArray[7] = v5;
    CubeArray[8] = v6;
    CubeArray[9] = v6;
    CubeArray[10] = v7;
    CubeArray[11] = v4;
    CubeArray[12] = v8;
    CubeArray[13] = v9;
    CubeArray[14] = v10;
    CubeArray[15] = v10;
    CubeArray[16] = v11;
    CubeArray[17] = v8;
    CubeArray[18] = v12;
    CubeArray[19] = v13;
    CubeArray[20] = v14;
    CubeArray[21] = v14;
    CubeArray[22] = v15;
    CubeArray[23] = v12;
    CubeArray[24] = v16;
    CubeArray[25] = v17;
    CubeArray[26] = v18;
    CubeArray[27] = v18;
    CubeArray[28] = v19;
    CubeArray[29] = v16;
    CubeArray[30] = v20;
    CubeArray[31] = v21;
    CubeArray[32] = v22;
    CubeArray[33] = v22;
    CubeArray[34] = v23;
    CubeArray[35] = v20;
    return CubeArray;
}

std::array<Vertex, 36> Construct::Table(glm::vec3 Color)
{
    std::array<Vertex, 36> TableArray;
    float size = 1;

    Vertex v0{ -size, -size, size , Color.x, Color.y, Color.z };
    Vertex v1{ size, -size, size, Color.x, Color.y, Color.z };
    Vertex v2{ size, size, size , Color.x, Color.y, Color.z };
    Vertex v3{ -size, size, size ,  Color.x, Color.y, Color.z };
    Vertex v4{ -size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v5{ size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v6{ size, size, -size ,  Color.x, Color.y, Color.z };
    Vertex v7{ -size, size, -size , Color.x, Color.y, Color.z };

    Vertex v8{(3 * -size),  size, (4 * size) , Color.x, Color.y, Color.z};
    Vertex v9{(3 * size),  size, (4 * size) , Color.x, Color.y, Color.z };
    Vertex v10{ (3 * -size) ,  size,(4 * -size), Color.x, Color.y, Color.z };
    Vertex v11{(3 * size), size,(4 * -size) , Color.x, Color.y, Color.z };

    TableArray = {
        // Front face
        v0, v1, v3,
        v3, v1, v2,

        // Back face
        v4, v5, v7,
        v7, v5, v6,

        // Right face
        v1, v5, v2,
        v2, v5, v6,

        // Left face
        v4, v0, v7,
        v7, v0, v3,

        // Top face
        v8, v9, v10,
        v10, v9, v11,


        // Bottom face
        v4, v5, v0,
        v0, v5, v1
    };

    return TableArray;
}

std::array<Vertex, 48> Construct::House(glm::vec3 Color)
{
    std::array<Vertex, 48> houseArray;
    float size = 1.f; 

    // House
    Vertex v0{ -size, -size, size , Color.x, Color.y, Color.z };
    Vertex v1{ size, -size, size, Color.x, Color.y, Color.z };
    Vertex v2{ size, size, size , Color.x, Color.y, Color.z };
    Vertex v3{ -size, size, size ,  Color.x, Color.y, Color.z };
    Vertex v4{ -size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v5{ size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v6{ size, size, -size ,  Color.x, Color.y, Color.z };
    Vertex v7{ -size, size, -size , Color.x, Color.y, Color.z };

    // Roof
    Vertex v8{ 0.0f, size + size / 2,  size, Color.x, Color.y, Color.z };
    Vertex v9{ 0.0f, size + size / 2, -size, Color.x, Color.y, Color.z };

    houseArray =
    {
        // Front face
        v0, v1, v3,
        v3, v1, v2,

        // Back face
        v4, v5, v7,
        v7, v5, v6,

        // Right face
        v1, v5, v2,
        v2, v5, v6,

        // Left face
        v4, v0, v7,
        v7, v0, v3,

        // Bottom face
        v4, v5, v0, 
        v0, v5, v1, 

        // Roof faces
        // Front triangle
        v3, v2, v8,
        // Back triangle
        v6, v7, v9,

        // Left roof face
        v3, v7, v8,
        v7, v8, v9,

        // Right roof face
        v2, v6, v8,
        v6, v8, v9
    };

    return houseArray;
}

std::array<Vertex, 6> Construct::NotAPlane(glm::vec3 Color)
{
    std::array<Vertex, 6> PlaneArray;
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);

    //  = glm::vec3(sizeXYZ.x / 4, sizeXYZ.x / 2, 0);
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v6{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z ,  Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v7{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    v7.y += 0.5;
    //v7.y = newHeight2;
    PlaneArray[0] = v3;
    PlaneArray[1] = v2;
    PlaneArray[2] = v6;
    PlaneArray[3] = v6;
    PlaneArray[4] = v7;
    PlaneArray[5] = v3;
    return PlaneArray;
}
