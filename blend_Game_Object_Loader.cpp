#include "blend_Game_Object_Loader.h"

blend_Game_Object_Loader::blend_Game_Object_Loader() 
{

}


blend_Game_Object_Loader::~blend_Game_Object_Loader() 
{
	Clear();
}

blend_Game_Object_Loader::blend_Game_Object_Loader(std::string game_Object_File_Name)
{
	load_Game_Object_File(game_Object_File_Name);
}




void blend_Game_Object_Loader::load_Game_Object_File(std::string game_Object_File_Name)
{
	std::vector<glm::vec3> temporary_XYZ;

	std::vector<glm::vec2> temporary_Texture_Points;

	std::vector<glm::vec3> temp_Normal_P;

	float x;
	float y;
	float z;

	std::string file_Line_info;

	game_Model_Information.clear();

	std::ifstream input_Game_Model_Name;
	input_Game_Model_Name.open(game_Object_File_Name);


	if (input_Game_Model_Name.is_open())
	{

		std::cout << "Game Model is being loaded " << game_Object_File_Name << "*......*......*......* " << std::endl;


		while (getline(input_Game_Model_Name, file_Line_info))
		{
			std::istringstream current_Line_Information(file_Line_info);

			std::string prefix_Type;

			current_Line_Information >> prefix_Type;



			if (prefix_Type == "v")
			{
				current_Line_Information >> x >> y >> z;

				glm::vec3 temp_XYZ(x, y, z);


				temporary_XYZ.push_back(temp_XYZ);
			}


			else if (prefix_Type == "vt")
			{
				current_Line_Information >> x >> y;

				glm::vec2 temporary_Points(x, y);


				temporary_Texture_Points.push_back(temporary_Points);

			}


			else if (prefix_Type == "vn")
			{
				current_Line_Information >> x >> y >> z;

				glm::vec3 temporary_Norm(x, y, z);


				temp_Normal_P.push_back(temporary_Norm);
			}



			else if (prefix_Type == "f")
			{
				std::string face_Info[3];
				std::string temporary_String[3];


				current_Line_Information >> face_Info[0] >> face_Info[1] >> face_Info[2];

				int face_Num[3];

				for (int i = 0; i < 3; i++)
				{
					std::stringstream face_Information(face_Info[i]);


					getline(face_Information, temporary_String[0], '/');
					getline(face_Information, temporary_String[1], '/');
					getline(face_Information, temporary_String[2], '/');


					int temp_XYZ_Vert = atoi(temporary_String[0].c_str());
					int temp_Text_Point = atoi(temporary_String[1].c_str());
					int temp_Normal_Point = atoi(temporary_String[2].c_str());


					glm::vec3 temp_XYZ_Points    = temporary_XYZ[temp_XYZ_Vert - 1];
					glm::vec2 temp_Textures      = temporary_Texture_Points[temp_Text_Point - 1];
					glm::vec3 temp_Normal_Points = temp_Normal_P[temp_Normal_Point - 1];



					game_Model_Struct temporary_Game_Model_Data(temp_XYZ_Points, temp_Textures, temp_Normal_Points);
					game_Model_Information.push_back(temporary_Game_Model_Data);
				}
			}
		}
	}
}

	

std::vector <game_Model_Struct> blend_Game_Object_Loader::get_Game_Model_Information()
{
	return game_Model_Information;
}

void blend_Game_Object_Loader::set_Game_Model_Structure_Type(game_Model_Struct temp_Game_Model, int i_Location)
{
	game_Model_Information[i_Location] = temp_Game_Model;
}



game_Model_Struct blend_Game_Object_Loader::get_Game_Model(int i_Location)
{
	return game_Model_Information[i_Location];
}


void blend_Game_Object_Loader::Clear()
{
	game_Model_Information.clear();
}