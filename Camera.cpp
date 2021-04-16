#include "Camera.h"
Camera::Camera()
{

}

Camera::Camera(glm::vec3 start_Position, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat initial_Movement_Speed, GLfloat initial_Rotation_Speed)
{

	worldUp          = startUp;
	yaw              = startYaw;
	pitch            = startPitch;
	y_Plane_Movement = glm::vec3(0.0f, 0.0f, -1.0f);


	player_Current_Position = start_Position;
	player_Movement_Speed   = initial_Movement_Speed;
	player_Rotation_Speed   = initial_Rotation_Speed;

	update_Camera();
}


void Camera::update_Camera()
{
	y_Plane_Movement.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	y_Plane_Movement.y = sin(glm::radians(pitch));
	y_Plane_Movement.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	y_Plane_Movement   = glm::normalize(y_Plane_Movement);

	x_Plane_Movement   = glm::normalize(glm::cross(y_Plane_Movement, worldUp));
	up                 = glm::normalize(glm::cross(x_Plane_Position_Movement, y_Plane_Movement));

}


glm::mat4 Camera::update_View_Matrix()
{
	return glm::lookAt(player_Current_Position, player_Current_Position + y_Plane_Movement, up);
}


	/****************************************************************************************************
	 * player_Keyboard_Input switch statement, read keyboard inputs below to see each keys task
	 *
	 *
	 * player  move fowards         = w or W key 
	 * player  move backwards       = s or S key 
	 * player  move left            = a or A key
	 * player  move right           = d or D key
	 *****************************************************************************************************/


void Camera::read_Player_Movement_Inputs(bool* player_Keyboard_Input, float deltaTime)
{
	
	std::cin << player_Keyboard_Input;

	if(player_Keyboard_Input == 'w' || player_Keyboard_Input == 'W')
	{
		player_Current_Position = player_Current_Position + y_Plane_Movement * player_Movement_Speed * deltaTime;
	}
	
	if(player_Keyboard_Input == 's' || player_Keyboard_Input == 'S')
	{		
		player_Current_Position = player_Current_Position - y_Plane_Movement * player_Movement_Speed * deltaTime;
	}
	
	
	if(player_Keyboard_Input == 'a'|| player_Keyboard_input == 'A')
	{ 	
		player_Current_Position = player_Current_Position - x_Plane_Movement * player_Movement_Speed * deltaTime;
	}	

	
	if(player_Keyboard_Input == 'd' || player_Keyboard_Input == 'D')
	{	
		player_Current_Position = player_Current_Position + x_Plane_Movement * player_Movement_Speed * deltaTime;
	}
}

/****************************************************************************************************************************
	 * Display helpful instructions = m or M
	 * Display terrain wireframe    = k or K
****************************************************************************************************************************/


void Camera::read_Game_Option_Inputs(bool* player_Keyboard_Input)
{
	
	std::cin << player_Keyboard_Input;


	if(player_Keyboard_Input == 'm' || player_Keyboard_Input == 'M')
	{
	
		if (display_Player_Instructions)
		{
			display_Player_Instructions = false;
		}

		else
		{
			display_Player_Instructions = true;
		}
	}


	if(player_Keyboard_Input == 'k' || player_Keyboard_Input == 'K')
	{
		if (show_Environment_Wireframe) 
		{
			
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			show_Wireframe = false;
		}


		else 
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			show_Wireframe = true;
		}
	}
}



void Camera::mouse_Input(float update_X_Position, float update_Y_Position)
{
	update_X_Position = update_X_Position * camera_Rotation_Speed;
	update_Y_Position = update_Y_Position * camera_Rotation_Speed;

	yaw   = yaw   + update_X_Position;
	pitch = pitch + update_Y_Position;


	///adjusts the angel / pitch of the camera so the players game view will not flip
	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}



	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	update_Camera();
}



//dont understand what y offset is so here is some psudo code
void Camera::player_Camera_Zoom()
{
	float player_Camera; 

	if(player_Camera >= 1.0 && player_Camera <= 20.0)
	{
		player_Camera -= //yoff;
	}

	if(player_Camera >= 20.0)
	{
		player_Camera = 20.0;
	}

	if(player_Camera < 0.5)
	{
		player_Camera = 0.5;
	}
}



void Camera::lau_Player_Input()
{
	lua_State* L = lua_open();

	if (L == NULL)
	{
		std::cout << "An error occured when trying to launch a lua state ... please rectify state issue " << std::endl;
	}

	// allows access to lua libraries 
	luaL_openlibs(L);


	// Load and run the player input script
	if (luaL_dofile(L, "lua_Script/player_Camera_Inputs.lua"))
	{
		std::cout << "Error occured when trying to open the lua file.. " << std::endl;
	}


	lua_settop(L,0);

	lua_getglobal(L,"player_Rotation_Speed");
	lua_getglobal(L,"player_Movement_Speed");
	
	
	lua_getglobal(L,"x_Plane_Camera");
	lua_getglobal(L,"y_Plane_Camera");
	lua_getglobal(L,"z_Plane_Camera");

	/***************************************************
     * setting up the following variables 
	 * Player camera movement speed
     * Player camera rotation speed
	 * Player camera current X position
	 * Player camera current Y Position
	 * Player camera current Z Position
	 ********************************************/
	camera_Rotation_Speed     = lua_tonumber(L,1);
	player_Movement_Speed     = lua_tonumber(L,2);
	player_Current_Position.x = lua_tonumber(L,3);
	player_Current_Position.y = lua_tonumber(L,4);
	player_Current_Position.z = lua_tonumber(L,5);

	// Close lua state
	lua_close(L);
}