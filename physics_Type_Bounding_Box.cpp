#pragma once
#include "physics_Type_Bounding_Box.h"
#include<string>
#include<vector>

#include<iostream>
#include<sstream>
#include<fstream>


//#include<glm.hpp>
//#include<GL/glut.h>



physics_Type_Bounding_Box::physics_Type_Bounding_Box()
{
	glm::vec3 origin_Point(0, 0, 0);
	minimum_Point = origin_Point;
	maximum_Point = origin_Point;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

physics_Type_Bounding_Box::physics_Type_Bounding_Box(std::vector <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points)
{
    build_Bounding_Box(xyz_Model_Points, model_Scale, xyz_Normal_Points);
}



glm::vec3 physics_Type_Bounding_Box::get_Minimum_XYZ_Point() const { return minimum_Point; }
     void physics_Type_Bounding_Box::set_Minimum_XYZ_Point(glm::vec3 temp_Minimum_Points) { minimum_Point = temp_Minimum_Points; }



glm::vec3 physics_Type_Bounding_Box::get_Maximum_Points() const { return maximum_Point; }
     void physics_Type_Bounding_Box::set_Maximum_Points(glm::vec3 temp_Maximum_Points) { maximum_Point = temp_Maximum_Points; }


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



float physics_Type_Bounding_Box::get_Maximum_X_Location() { return maximum_Point.x; }
void physics_Type_Bounding_Box::set_Maximum_X_Location(float temp_X_Maximum) { maximum_Point.x = temp_X_Maximum; }



float physics_Type_Bounding_Box::get_Minimum_X_Location() { return minimum_Point.x; }
void physics_Type_Bounding_Box::set_Minimum_X_Location(float temp_X_Minimum) { minimum_Point.x = temp_X_Minimum; }

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


float physics_Type_Bounding_Box::get_Maximum_Y_Location() { return maximum_Point.y; }
void  physics_Type_Bounding_Box::set_Maximum_Y_Location(float temp_Y_Maximum) { maximum_Point.y = temp_Y_Maximum; }


float physics_Type_Bounding_Box::get_Minimum_Y_Location() { return minimum_Point.y; }
void  physics_Type_Bounding_Box::set_Minimum_Y_Location(float temp_Y_Min) { minimum_Point.y = temp_Y_Min; }


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



float physics_Type_Bounding_Box::get_Maximum_Z_Location() { return maximum_Point.z; }
void  physics_Type_Bounding_Box::set_Maximum_Z_Location(float temp_Z_Maximum) { maximum_Point.z = temp_Z_Maximum; }



float physics_Type_Bounding_Box::get_Minimum_Z_Location() { return minimum_Point.z; }
void  physics_Type_Bounding_Box::set_Minimum_Z_Location(float temp_Z_Min) { minimum_Point.z = temp_Z_Min; }




void physics_Type_Bounding_Box::update_Current_X_Location(float x)
{
	minimum_Point.x += x;
	maximum_Point.x += x;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void physics_Type_Bounding_Box::update_Current_Y_Location(float y)
{
	minimum_Point.y += y;
	maximum_Point.y += y;
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void physics_Type_Bounding_Box::update_Current_Z_Location(float z)
{
	minimum_Point.z += z;
	maximum_Point.z += z;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void physics_Type_Bounding_Box::build_Bounding_Box(std::vector < game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points)
{
	glm::vec3 origin_Point(0, 0, 0);

	minimum_Point = origin_Point;
	maximum_Point = origin_Point;


	for (int current_Point = xyz_Model_Points.size() - 1; current_Point >= 0; current_Point--)
	{
		if (xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x > maximum_Point.x)
		{
			maximum_Point.x = xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x;
		}


		else if (xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x < minimum_Point.x)
		{
			minimum_Point.x = xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x;
		}



		if (xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y > maximum_Point.y)
		{
			maximum_Point.y = xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y;
		}


		else if (xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y < minimum_Point.y)
		{
			minimum_Point.y = xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y;
		}



		if (xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z > maximum_Point.z * model_Scale.z)
		{
			maximum_Point.z = xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z;
		}


		else if (xyz_Model_Points[current_Point].xyz_Normal_Points.z < minimum_Point.z * model_Scale.z)
		{
			minimum_Point.z = xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z;
		}


		minimum_Point.x += xyz_Normal_Points.x;
		minimum_Point.y += xyz_Normal_Points.y;
		minimum_Point.z += xyz_Normal_Points.z;


		maximum_Point.x += xyz_Normal_Points.x;
		maximum_Point.y += xyz_Normal_Points.y;
		maximum_Point.z += xyz_Normal_Points.z;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void physics_Type_Bounding_Box::present_Ground()
{
	float reduction = 900.0f;
	
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y - reduction, maximum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y - reduction, maximum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y,             maximum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y,             maximum_Point.z);
	}
	glEnd();

	
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y - reduction, minimum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y - reduction, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y,             minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y,             minimum_Point.z);
	}
	glEnd();


	glBegin(GL_QUADS);
	{
		glVertex3f(maximum_Point.x, minimum_Point.y - reduction, maximum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y - reduction, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y,             minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y,             maximum_Point.z);
	}
	glEnd();


	
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y - reduction, maximum_Point.z);
		glVertex3f(minimum_Point.x, maximum_Point.y - reduction, minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y,             minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y,             maximum_Point.z);
	}
	glEnd();
}


void physics_Type_Bounding_Box::show_Bounding_Box()
{
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y, maximum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y, maximum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, maximum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y, maximum_Point.z);
	}
	glEnd();

	//face 2
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y, minimum_Point.z);
	}
	glEnd();

	//face 3
	glBegin(GL_QUADS);
	{
		glVertex3f(maximum_Point.x, maximum_Point.y, maximum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, maximum_Point.z);
	}
	glEnd();

	//face 4
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y, maximum_Point.z);
		glVertex3f(minimum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y, minimum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y, maximum_Point.z);
	}
	glEnd();

	//face 5
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, maximum_Point.y, maximum_Point.z);
		glVertex3f(minimum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, maximum_Point.y, maximum_Point.z);
	}
	glEnd();


	//face 6
	glBegin(GL_QUADS);
	{
		glVertex3f(minimum_Point.x, minimum_Point.y, maximum_Point.z);
		glVertex3f(minimum_Point.x, minimum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, minimum_Point.z);
		glVertex3f(maximum_Point.x, minimum_Point.y, maximum_Point.z);
	}
	glEnd();
}


bool physics_Type_Bounding_Box::collision_Detection(glm::vec3 xyz_Point_Detection)
{
	return (xyz_Point_Detection.x >= minimum_Point.x && xyz_Point_Detection.x <= maximum_Point.x) && (xyz_Point_Detection.y >= minimum_Point.y && xyz_Point_Detection.y <= maximum_Point.y) && (xyz_Point_Detection.z >= minimum_Point.z && xyz_Point_Detection.z <= maximum_Point.z);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------