#pragma once
struct game_Model_Struct
{
    ///The position co-ordinant(v)
    glm::vec3 xyz_Model_Points;

    ///The texture co-ordinant(vt)
    glm::vec2 texture_Points;

    ///The normal co-ordinant(vn)
    glm::vec3 xyz_Normal_Points;

    game_Model_Struct(glm::vec3 temp_XYZ_Location, glm::vec2 temp_Textures, glm::vec3 temp_Normal_Points)
    {
        xyz_Model_Points       = temp_XYZ_Location;
        texture_Points         = temp_Textures;
        xyz_Normal_Points      = temp_Normal_Points;
    }
};