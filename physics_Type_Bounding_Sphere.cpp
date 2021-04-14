#include "physics_Type_Bounding_Sphere.h"



physics_Type_Bounding_Sphere::physics_Type_Bounding_Sphere()
{
	glm::vec3 origin_Point(0, 0, 0);
	
	model_Center_Point = origin_Point;

	model_Radius = 1;
}



physics_Type_Bounding_Sphere::physics_Type_Bounding_Sphere(std::vector <game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points)
{
	map_Bounding_Sphere(xyz_Model_Points, model_Scale, xyz_Normal_Points);
}




float physics_Type_Bounding_Sphere::get_Radius_Of_Sphere() { return model_Radius; }
 void physics_Type_Bounding_Sphere::set_Radius_Of_Sphere(float radius) { model_Radius = radius; }



glm::vec3 physics_Type_Bounding_Sphere::get_Center_Of_Sphere() const { return model_Center_Point; }
     void physics_Type_Bounding_Sphere::set_Center_Of_Sphere(glm::vec3 center_Point) { model_Center_Point = center_Point; }




void physics_Type_Bounding_Sphere::map_Bounding_Sphere(std::vector < game_Model_Struct> xyz_Model_Points, glm::vec3 model_Scale, glm::vec3 xyz_Normal_Points)
{
	glm::vec3 origin_Points(0, 0, 0);


	glm::vec3 minimum_Point = origin_Points;
	
	
	glm::vec3 maximum_Point = origin_Points;



	for (int current_Point = xyz_Model_Points.size() - 1; current_Point >= 0; current_Point--)
	{

		if (xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x > maximum_Point.x)
		{
			maximum_Point.x = xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x;
		}

			/// if current point is smaller than the minimum point set min point to current point
			else if (xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x < minimum_Point.x)
			{
				minimum_Point.x = xyz_Model_Points[current_Point].xyz_Normal_Points.x * model_Scale.x;
			}



		if (xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y > maximum_Point.y)
		{
			maximum_Point.y = xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y;
		}
	
			/// if current point is smaller than the minimum point set min point to current point
			else if (xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y < minimum_Point.y)
			{
				minimum_Point.y = xyz_Model_Points[current_Point].xyz_Normal_Points.y * model_Scale.y;
			}



		if (xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z > maximum_Point.z * model_Scale.z)
		{
			maximum_Point.z = xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z;
		}

				/// if current point is smaller than the minimum point set min point to current point
			else if (xyz_Model_Points[current_Point].xyz_Normal_Points.z < minimum_Point.z * model_Scale.z)
			{
				minimum_Point.z = xyz_Model_Points[current_Point].xyz_Normal_Points.z * model_Scale.z;
			}

	}

	minimum_Point.x += xyz_Normal_Points.x;
	minimum_Point.y += xyz_Normal_Points.y;
	minimum_Point.z += xyz_Normal_Points.z;
	
	
	maximum_Point.x += xyz_Normal_Points.x;
	maximum_Point.y += xyz_Normal_Points.y;
	maximum_Point.z += xyz_Normal_Points.z;



	model_Center_Point.x = (minimum_Point.x + maximum_Point.x) / 2;
	model_Center_Point.y = (minimum_Point.y + maximum_Point.y) / 2;
	model_Center_Point.z = (minimum_Point.z + maximum_Point.z) / 2;



	model_Radius = sqrt ((minimum_Point.x - maximum_Point.x) * (minimum_Point.x - maximum_Point.x) + (minimum_Point.y - maximum_Point.y) * (minimum_Point.y - maximum_Point.y) + (minimum_Point.z - maximum_Point.z) * (minimum_Point.z - maximum_Point.z));
	
	model_Radius /= 4;
}





void physics_Type_Bounding_Sphere::show_Bounding_Sphere()
{
	glPushMatrix();
	{
		glTranslatef(model_Center_Point.x, model_Center_Point.y, model_Center_Point.z);
		glutWireSphere(model_Radius, 10, 20);
	}
	glPopMatrix();
}



float physics_Type_Bounding_Sphere::distance_From_Collision(glm::vec3 collision)
{
	float distance = sqrt((collision.x - model_Center_Point.x) * (collision.x - model_Center_Point.x) + (collision.y - model_Center_Point.y) * (collision.y - model_Center_Point.y) +  (collision.z - model_Center_Point.z) * (collision.z - model_Center_Point.z));
	
	
	return distance;
}