#pragma once

#include "blend_Game_Object_Loader.h"

#include "physics_Type_Bounding_Box.h"
#include "physics_Type_Bounding_Sphere.h"
#include "game_Model_Struct.h"

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>


#include <vector>
#include <cmath>

#include <glm.hpp>
#include <GL/glut.h>


/**********************************************************************************************************************
* @class game_Model
* @brief Storing the information for a game model object
*
* This class holds a game_Model_Struct which is used to draw a game model, which contains
* scale, bounding box or bounding sphere and the position for the model allowing the game model to be loaded in,
* displayed and interacted with in the world
*
* @author William Halling
* @version 01
* @date april 2021
*
* @bug no known bugs, but there may be some out there...
***********************************************************************************************************************/

#pragma once
class game_Model
{
public:
     game_Model();
    ~game_Model();
     game_Model(std::vector<game_Model_Struct> xyz_Loc_Points, glm::vec3 xyz_Model_Points, glm::vec3 model_Scale, int temp_texture_Num, glm::vec3 temp_Current_Colour);

    
        /******************************************************************************************************************************************************************************************
         * @brief  : get_Model_Center_Point
         *
         * @brief  : gets the centre point of the game model 
         *
         * @param  : None
         * @return : vector3 xyz_Center_Point
         *****************************************************************************************************************************************************************************************/

    glm::vec3 get_Model_Location_Points() const;



        /******************************************************************************************************************************************************************************************
        * @brief  : set_Model_Center_Point 
        *
        * @brief  : sets the centre point of the game model 
        *
        * @param  : glm::vec3 
        * @return : void
        ******************************************************************************************************************************************************************************************/

    void set_Model_Location_Points(glm::vec3 xyz_Model_Points);



        /*********************************************************************************************************************************************************************************************
         * @brief  : get_XYZ_Model_Scale
         *
         * @brief  : gets the xyz model scale
         *
         * @param  : None 
         * @return : vec3 model_Scale
         ************************************************************************************************************************************************************************************************/
   
    glm::vec3 get_Game_Model_Scale() const;



        /******************************************************************************************************************************************************************************************
         * @brief sets xyz scale of the model
         *
         * @param   : glm::vec3
         * @return  : void
         *****************************************************************************************************************************************************************************************/

    void set_Game_Model_Scale(glm::vec3 xyz_Model_Points);



        /****************************************************************************************************************************************************************************************
         * @brief  : get_Current_Colour
         *
         * @brief  : gets the Current_Colour
         *
         * @param  : None
         * @return : current_Colour (glm::vec3)
         ****************************************************************************************************************************************************************************************/

    glm::vec3 get_Current_Colour() const;


        /****************************************************************************************************************************************************************************************
         * @brief  : set_Current_Colour
         *
         * @brief  : sets the Current_Colour
         *
         * @param  : glm::vec3 temp_Current_Colour
         * @return : void
         ****************************************************************************************************************************************************************************************/

    void set_Current_Colour(glm::vec3 temp_Current_Colour);


        /****************************************************************************************************************************************************************************************
         * @brief  : get_Current_Texture_Number
         *
         * @brief  : gets the current texture number
         *
         * @param  : None
         * @return : texture_Number (int)
         ****************************************************************************************************************************************************************************************/

    int  get_Texture_Number() const;


        /****************************************************************************************************************************************************************************************
         * @brief  : set_Current_Texture_Number
         *
         * @brief  : sets the current texture number
         *
         * @param  : temp_texture_Num (int)
         * @return : void
         ****************************************************************************************************************************************************************************************/

    void set_Texture_Number(int temp_texture_Num);



        /****************************************************************************************************************************************************************************************
         * @brief : get_Game_Model_Location
         *
         * @brief : gets the game model xyz_Location at position i in the vertex
         *
         * @return void
         ***************************************************************************************************************************************************************************************/

    game_Model_Struct get_Game_Model_Location(int i);



        /****************************************************************************************************************************************************************************************
         * @brief  : set_Game_Model_Location
         *
         * @brief  : Sets a xyz_Location to position i in the vertex
         *
         * @param  : game_Model_Struct v, int i
         * @return : void
         ****************************************************************************************************************************************************************************************/

    void set_Game_Model_Location(game_Model_Struct xyz_Loc_Points, int i);


        /****************************************************************************************************************************************************************************************
         * @brief  : get_Bounding_Box
         *
         * @brief  : Returns bounding_Box
         *
         * @param  : None
         * @return : physics_Type_Bounding_Box b_Box_Physics (object)
         ***************************************************************************************************************************************************************************************/

    physics_Type_Bounding_Box get_Bounding_Box() const;



        /****************************************************************************************************************************************************************************************
         * @brief : set_Bounding_Box
         * 
         * @brief : sets the bounding_Box to value temp_B_Box
         * 
         * 
         * @param : physics_Type_Bounding_Box temp_B_Box
         * @return void
         ***************************************************************************************************************************************************************************************/

    void set_Bounding_Box(physics_Type_Bounding_Box temp_B_Box);



        /****************************************************************************************************************************************************************************************
         * @brief get_Bounding_Sphere
         *
         *
         * @return physics_Type_Bounding_Sphere sphere (object)
         ***************************************************************************************************************************************************************************************/

    physics_Type_Bounding_Sphere get_Bounding_Sphere() const;


        /***************************************************************************************************************************************************************************************
         * @brief  : set_Bounding_Sphere
         * 
         * @brief  : sets the bounding_Sphere with temp_Sphere
         * 
         * @param  : temp_Sphere (physics_Type_Bounding_Sphere)
         * @return : void
         ***************************************************************************************************************************************************************************************/

    void set_Bounding_Sphere(physics_Type_Bounding_Sphere temp_Sphere);

        /***************************************************************************************************************************************************************************************
         * @brief : Displays the game model
         * 
         * @brief : displays the model at the position, with the scale, 
         *          it has the vector position, texture co-ordinants and normals for lighting if it is added
         *
         * @return void
         ***************************************************************************************************************************************************************************************/
   
    void display_Game_Model();




        /****************************************************************************************************************
         * @brief : Load_Game_Model, sets the game model position and scale
         *
         * @brief : This functon loads in the game_Model_Struct for the model, sets the position, and sets the scale
         *
         * @return void
         ********************************************************************************************************************/
    
    void Load_Game_Model(std::vector<game_Model_Struct> xyz_Loc_Points, glm::vec3 xyz_Model_Points, glm::vec3 model_Scale, int temp_texture_Num, glm::vec3 temp_Current_Colour);



        /*********************************************************************************************************************
         * @brief Getter for model
         *
         * Gets the vertex from model position i
         *
         * @return vertex model[i]
         *********************************************************************************************************************/

    std::vector<game_Model_Struct> get_Full_Model();


        /************************************************************************************************************************
         * @brief Clears the vertex vector
         *
         * @return void
         *************************************************************************************************************************/
    
    void Clear();


private:

 
        ///The central position of the object
    glm::vec3 xyz_Location_Point;

        ///The scale of x, y, z
    glm::vec3 game_Model_Scale;


        ///The texture number to apply it
    int texture_Number;

        ///The colour of game model
    glm::vec3 colour_Of_Game_Model;


    ///creates a vector to hold the game_Model structure information
    std::vector<game_Model_Struct> model_Data;

        ///The bounding box for the model
    physics_Type_Bounding_Box bounding_Box;

        ///The bounding sphere for the model
    physics_Type_Bounding_Sphere bounding_Sphere;

};


