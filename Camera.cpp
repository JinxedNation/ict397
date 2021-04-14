#include "Camera.h"
Camera::Camera()
{

}

Camera::Camera(glm::vec3 start_Position, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat initial_Movement_Speed, GLfloat initial_Rotation_Speed)
{

	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	fronty = glm::vec3(0.0f, 0.0f, -1.0f);


	player_Current_Position = start_Position;
	player_Movement_Speed = initial_Movement_Speed;
	player_Rotation_Speed = initial_Rotation_Speed;

	update_Camera();
}


void Camera::update_Camera()
{
	fronty.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	fronty.y = sin(glm::radians(pitch));
	fronty.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	fronty   = glm::normalize(fronty);

	righty  = glm::normalize(glm::cross(fronty, worldUp));
	up      = glm::normalize(glm::cross(righty, fronty));

}

void Camera::keyboard_Input(bool* keyboard_Input, GLfloat time_Delta_Time)
{


	if (keyboard_Input[GLFW_KEY_W])
	{
		player_Current_Position = player_Current_Position + fronty * player_Movement_Speed * time_Delta_Time;
	}



	if (keyboard_Input[GLFW_KEY_S])
	{
		player_Current_Position = player_Current_Position - fronty * player_Movement_Speed * time_Delta_Time;
	}



	if (keyboard_Input[GLFW_KEY_A])
	{
		player_Current_Position = player_Current_Position - righty * player_Movement_Speed * time_Delta_Time;
	}


	if (keyboard_Input[GLFW_KEY_D])
	{
		player_Current_Position = player_Current_Position + righty * player_Movement_Speed * time_Delta_Time;
	}

}

void Camera::mouse_Input(GLfloat update_X_Position, GLfloat update_Y_Position)
{
	update_X_Position = update_X_Position * player_Rotation_Speed;
	update_Y_Position = update_Y_Position * player_Rotation_Speed;

	yaw = yaw + update_X_Position;
	pitch = pitch + update_Y_Position;



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

glm::mat4 Camera::update_View_Matrix()
{
	return glm::lookAt(player_Current_Position, player_Current_Position + fronty, up);
}