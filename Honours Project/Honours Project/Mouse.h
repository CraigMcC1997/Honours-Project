//Get mouse data
//THIS CODE WAS TAKEN FROM 
//https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/7.2.camera_keyboard_dt/camera_keyboard_dt.cpp
//All camera code based around the https://learnopengl.com/Getting-started/Camera tutorial

#pragma once
#include "glm/glm.hpp"
#include "Camera.h"

class Mouse
{
private:
	bool firstMouse = true;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0;
	float lastY = 600.0 / 2.0;
	float fov = 45.0f;
public:
	void mouse_callback(double, double);
};