#pragma once

#include "game_Model_Struct.h"
#include "blend_Game_Object_Loader.h"


#include "External_Libraries/glm/glm.hpp"
#include "External_Libraries/glm/vec2.hpp"
#include "External_Libraries/glm/vec3.hpp"


#include<cmath>
#include<vector>

#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


/************************************************************************************
 * @class physics_Type_Bounding_Box  
 *
 * @brief creates a physics bounding box for detecting collisions from a vertex      *
 *                             
 *
 * Class that has a bounding box, with min and max co-ordinants.                     *
 * It is created using a vector of vertexes                                          *
 *                                                                                   *
 *                                                                                   *
 * @author William Halling 32233703                                                  *
 * @version 01                                                                       *
 * @date 1/04/2021                                                                   *
 *                                                                                   *
 *                                                                                   *
 * @bug no known bugs, but there may be some out there...                            *
 *************************************************************************************/



class physics_Type_Bounding_Box
{
public:
    physics_Type_Bounding_Box();
    physics_Type_Bounding_Box(std::vector <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points);
    





        /********************************************************************************
         * @brief gets the get_Minimum_XYZ_points
         *
         * gets the minimum_XYZ_Locations
         *
         * @return xyz_Minimum_Point
         *********************************************************************************/

    glm::vec3 get_Minimum_XYZ_Point() const;



        /********************************************************************************
         * @brief sets the set_Minimum_XYZ_Locations
         * 
         * sets the minimum_XYZ_Locations 
         *
         * @return void
         *********************************************************************************/

    void set_Minimum_XYZ_Point(glm::vec3 temp_Minimum_XYZ);
  
    
        /********************************************************************************
         * @brief sets the get_Maximum_Points
         *
         * gets the maximum_Points
         *
         * @return xyz_Maximum_Point
         *********************************************************************************/

    glm::vec3 get_Maximum_Points() const;


        /********************************************************************************
         * @brief sets the Maximum_Points
         *
         * gets the maximum_Points
         *
         * @return void
         *********************************************************************************/

    void set_Maximum_Points(glm::vec3 temp_Maxi_XYZ);

    


        /********************************************************************************
         * @brief gets the Maximum_X_Location
         *
         * sets the get_Maximum_X_Location
         *
         * @return maximum_X_Location
         *********************************************************************************/

    float get_Maximum_X_Location();


        /********************************************************************************
        * @brief sets the set_Maximum_X_Location
        *
        * sets the maximum_X_Location
        *
        * @return void
        *********************************************************************************/

    void  set_Maximum_X_Location(float temp_Max_x);



        /********************************************************************************
         * @brief gets the minimum_X_Location
         *
         * gets the minimum_X_Location
         *
         * @return float minimum_X_Location
         *********************************************************************************/

    float get_Minimum_X_Location();



        /********************************************************************************
         * @brief sets the minimum_X_Location
         *
         * sets the minimum_X_Location
         *
         * @return void
         *********************************************************************************/

    void  set_Minimum_X_Location(float temp_Min_X);



        /********************************************************************************
         * @brief gets the get_Maximum_Y_Location
         *
         * gets the naximum_Y_Location
         *
         * @return float maximum_Y_Location
         *********************************************************************************/

    float get_Maximum_Y_Location();



        /********************************************************************************
        * @brief sets the set_Maximum_Y_Location
        *
        * sets the minimum_Y_Location
        *
        * @return void
        *********************************************************************************/

    void  set_Maximum_Y_Location(float temp_Max_y);



        /********************************************************************************
          * @brief Gets the get_Minimum_Y_Location
          *
          * gets the minimum_Y_Location
          *
          * @return minimum_Y_Location
          *********************************************************************************/

    float get_Minimum_Y_Location();



        /********************************************************************************
         * @brief sets the minimum_Y_Location
         *
         * sets the minimum_Y_Location
         *
         * @return void
         *********************************************************************************/

    void  set_Minimum_Y_Location(float temp_Min_Y);




        /********************************************************************************
         * @brief gets the maximum_Z_Location
         *
         * gets the maximum_Z_Location
         *
         * @return float maximum_Z_Location
         *********************************************************************************/

    float get_Maximum_Z_Location();
   
    
        /********************************************************************************
         * @brief sets the maximum_Z_Location
         *
         * sets the maximum_Z_Location
         *
         * @return void
         *********************************************************************************/

    void  set_Maximum_Z_Location(float temp_Max_z);



        /********************************************************************************
         * @brief gets the minimum_Z_Location
         *
         * gets the minimum_Z_Location
         *
         * @return float minimum_z_Location
         *********************************************************************************/

    float get_Minimum_Z_Location();

        /********************************************************************************
         * @brief sets the set_Minimum_Z_Location
         *
         * sets the minimum_Z_Location
         *
         * @return void
         *********************************************************************************/

    void  set_Minimum_Z_Location(float temp_Min_Z);


        /********************************************************************************
         * @brief updates the Current_X_Location
         *
         * update_Current_X_Location
         *
         * @return void
         *********************************************************************************/

    void  update_Current_X_Location(float temp_X);


        /********************************************************************************
         * @brief updates the update_Current_Y_Location
         *
         * update_Current_Y_Location
         *
         * @return void
         *********************************************************************************/
   
    void  update_Current_Y_Location(float temp_Y);


        /********************************************************************************
         * @brief updates the update_Current_Z_Location
         *
         * update_Current_Z_Location
         *
         * @return void
         *********************************************************************************/

    void  update_Current_Z_Location(float temp_Z);
    
        /********************************************************************************
         * @brief checks if a collision has occured
         * 
         * collision_Detection
         *
         * @return bool 
         *********************************************************************************/

    bool collision_Detection(glm::vec3 xyz_Collision_Detection);


        /********************************************************************************
         * @brief shows the bounding box on the floor
         *
         * @return void
         *********************************************************************************/

    void present_Ground();


        /********************************************************************************
         * @brief shows the bounding box to show the boxes location
         *
         * @return void
         *********************************************************************************/

    void show_Bounding_Box();



        /********************************************************************************
         * @brief creates a bounding box
         *
         * @return void
         *********************************************************************************/

    void build_Bounding_Box(std::vector  <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points);


private:
    glm::vec3 minimum_Point;
    glm::vec3 maximum_Point;
};

