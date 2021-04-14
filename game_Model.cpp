#include "game_Model.h"



game_Model::game_Model()
{
	glm::vec3 xyz_Normal_Points(0, 0, 0);
	glm::vec3 model_Scale(0, 0, 0);
	xyz_Location_Point   = xyz_Normal_Points;
	game_Model_Scale     = model_Scale;
	texture_Number       = 0;
	colour_Of_Game_Model = model_Scale;
}

game_Model::game_Model(std::vector<game_Model_Struct> xyz_Model_Points, glm::vec3 xyz_Model_Point, glm::vec3 model_Scale, int temp_texture_Num, glm::vec3 temp_Current_Colour)
{
	Load_Game_Model(xyz_Model_Points, xyz_Model_Point, model_Scale, temp_texture_Num, temp_Current_Colour);
}

game_Model::~game_Model()
{
	model_Data.clear();
}


void game_Model::Clear() { model_Data.clear(); }


std::vector<game_Model_Struct> game_Model::get_Full_Model() { return model_Data; }


glm::vec3 game_Model::get_Model_Location_Points() const { return xyz_Location_Point; }
void      game_Model::set_Model_Location_Points(glm::vec3 temp_XYZ_Points) { xyz_Location_Point = temp_XYZ_Points; }



glm::vec3 game_Model::get_Game_Model_Scale() const { return game_Model_Scale; }
void      game_Model::set_Game_Model_Scale(glm::vec3 model_Scale) { game_Model_Scale = model_Scale; }



glm::vec3 game_Model::get_Current_Colour() const { return colour_Of_Game_Model; }
void      game_Model::set_Current_Colour(glm::vec3 temp_Current_Colour) { colour_Of_Game_Model = temp_Current_Colour; }



int       game_Model::get_Texture_Number() const { return texture_Number; }
void      game_Model::set_Texture_Number(int temp_Texture_Number) { texture_Number = temp_Texture_Number; }



game_Model_Struct game_Model::get_Game_Model_Location(int i) { return model_Data[i]; }
void              game_Model::set_Game_Model_Location(game_Model_Struct v, int i) { model_Data[i] = v; }



physics_Type_Bounding_Box    game_Model::get_Bounding_Box()    const { return bounding_Box; }
void                         game_Model::set_Bounding_Box(physics_Type_Bounding_Box temp_Bounding_Box) { bounding_Box = temp_Bounding_Box; }



physics_Type_Bounding_Sphere game_Model::get_Bounding_Sphere() const { return bounding_Sphere; }
void                         game_Model::set_Bounding_Sphere(physics_Type_Bounding_Sphere temp_Sphere) { bounding_Sphere = temp_Sphere; }




void game_Model::Load_Game_Model(std::vector<game_Model_Struct> xyz_Model_Points, glm::vec3 xyz_Model_Point, glm::vec3 model_Scale, int temp_Texture_Number, glm::vec3 temp_Current_Colour)
{
	model_Data.swap(xyz_Model_Points);
	
	xyz_Location_Point   = xyz_Model_Point;
	game_Model_Scale     = model_Scale;
	texture_Number       = temp_Texture_Number;
	colour_Of_Game_Model = temp_Current_Colour;

	physics_Type_Bounding_Box    temp_Box(model_Data, game_Model_Scale, xyz_Location_Point);
	physics_Type_Bounding_Sphere temp_Sphere(model_Data, game_Model_Scale, xyz_Location_Point);

	bounding_Box    = temp_Box;
	bounding_Sphere = temp_Sphere;
	
	
}

void game_Model::display_Game_Model()
{
	glPushMatrix();
	{
		glTranslatef(xyz_Location_Point.x, xyz_Location_Point.y, xyz_Location_Point.z);
		glScalef(game_Model_Scale.x, game_Model_Scale.y, game_Model_Scale.z);
		glColor3f(colour_Of_Game_Model.x, colour_Of_Game_Model.y, colour_Of_Game_Model.z);


		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		
		glVertexPointer(3, GL_FLOAT, sizeof(game_Model_Struct), &model_Data[0].xyz_Model_Points);
		glTexCoordPointer(2, GL_FLOAT, sizeof(game_Model_Struct), &model_Data[0].texture_Points);
		//glNormalPointer(GL_FLOAT, sizeof(game_Model_Struct), &model_Data[0].xyz_Normal_Points);
		glDrawArrays(GL_TRIANGLES, 0, model_Data.size());
		
		
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();

	//sphere.Display();
	//axisBox.Display();
}