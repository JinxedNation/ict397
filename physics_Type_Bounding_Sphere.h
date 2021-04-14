#pragma once


#include "External_Libraries/glm/glm.hpp"
#include "External_Libraries/glm/vec2.hpp"
#include "External_Libraries/glm/vec3.hpp"

#include "game_Model_Struct.h"
#include "blend_Game_Object_Loader.h"


#include <iostream>
#include<sstream>
#include<fstream>

#include<cmath>
#include<vector>


using namespace std;

class physics_Type_Bounding_Sphere
{
public:
	physics_Type_Bounding_Sphere();
	physics_Type_Bounding_Sphere(std::vector <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points);


		/************************************************************************************************************
		* @brief  gets sphere radius
		*
		* @return radius_Of_Sphere (float)
		*************************************************************************************************************/

	float get_Radius_Of_Sphere();


		/**********************************************************************************************************
		 * @brief Sets the radius of the sphere
		 * @param uses radius to set model_Radius
		 *
		 * @return void
		 **********************************************************************************************************/

	void set_Radius_Of_Sphere(float radius);


		/***********************************************************************************************************
		 * @brief  get_Sphere_Center_Point
		 *
		 * @return float center_Point
		 ************************************************************************************************************/

	glm::vec3 get_Center_Of_Sphere() const;


		/************************************************************************************************************
  		 * @brief Sets the sphere_Center_Point to center_Point
		 *
		 * @return void
		 ************************************************************************************************************/

	void set_Center_Of_Sphere(glm::vec3 center_Point);



		/************************************************************************************************
		* @brief maps a bounding sphere
		*
		* This uses a vector<game_Model_Struct>  to find 
		*		the center_Point of the game model
		*		the radius of the object
		* 
		* @return void
		*************************************************************************************************/
	
	
	void  map_Bounding_Sphere(std::vector <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points);


		/**************************************************************************************************
		* @brief Displays the bounding sphere
		*
		* @return void
		*************************************************************************************************/

	void show_Bounding_Sphere();

		/***************************************************************************************************************
		* @brief Gets the distance
		*
		* Gets the distance between col vec3 and the center position
		* @return float
		*****************************************************************************************************************/
	
	float distance_From_Collision(glm::vec3 collision);


private:

		///Radius of the object
	float model_Radius;

		///The center co-ordinants of the object
	glm::vec3 model_Center_Point;
};