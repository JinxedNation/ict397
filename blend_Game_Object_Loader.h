#pragma once
/************************************************************************************
 * @class blend_Game_Object
 *
 * @brief       *
 *
 *
 * Class that gets the required information from an obj file, which is then stored into a vector of type game_Model_Struct                      *
 * contains the models positions, texture postions and normals points                *
 * load_Game_Object_File function stores and sorts the game model data               *                                                                                 *
 *                                                                                   *
 * @author William Halling 32233703                                                  *
 * @version 01                                                                       *
 * @date 1/04/2021                                                                   *
 *                                                                                   *
 *                                                                                   *
 * @bug no known bugs, but there may be some out there...                            *
 *************************************************************************************/

using namespace std;


#include<cmath>
#include<vector>

#include "External_Libraries/glm/glm.hpp"
#include "External_Libraries/glm/vec2.hpp"
#include "External_Libraries/glm/vec3.hpp"

#include <iostream>
#include<sstream>
#include<fstream>

#include "game_Model_Struct.h"



class blend_Game_Object_Loader
{
public:
    blend_Game_Object_Loader();

    //destructor
    ~blend_Game_Object_Loader();


    blend_Game_Object_Loader(std::string game_Object_File_Name);
    

        /********************************************************************************
         * @brief Gets the get_Game_Model_Information
         *
         * Gets the get_Game_Model_Information and returns it
         *
         * @return vector<game_Model_Struct> game_Model_Information
         *********************************************************************************/

    std::vector<game_Model_Struct> get_Game_Model_Information();
    

       /**********************************************************************************
        * @brief Setter for game_Model at location i
        *
        * Sets a game_Model_Struct to the vector at point i
        *
        * @return void
        *********************************************************************************/
    
    void set_Game_Model_Structure_Type(game_Model_Struct temp_Game_Model, int i_Location);


        /**********************************************************************************
         * @brief Getter for vertex at position i
         *
         * Returns the game_Model_Struct at postion i of vector verticies
         *
         * @return void
         *********************************************************************************/

    game_Model_Struct get_Game_Model(int i_Location);


        /**********************************************************************************
         * @brief Loads the obj file into the vertex
         *
         * Loads the game object file and places its contents into the game_Model_Struct vector
         *
         * @return void
         *********************************************************************************/

    void load_Game_Object_File(std::string game_Object_File_Name);


        /**********************************************************************************************************
         * @brief Clears the game_Model_Information vector
         *
         * @return void
         *****************************************************************************************************************/

    void Clear();


private:

    std::vector <game_Model_Struct> game_Model_Information;
};

