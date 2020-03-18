//THIS CODE WAS TAKEN FROM 
//https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/7.2.camera_keyboard_dt/camera_keyboard_dt.cpp
//All camera code based around the https://learnopengl.com/Getting-started/Camera tutorial
#pragma once
#ifndef CAMERA
#define CAMERA

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace camera
{
	glm::vec3 getEye();
	glm::vec3 getFront();
	glm::vec3 getUp();
	void setEye(glm::vec3 newEye);
	void setFront(glm::vec3 newAt);
	void setUp(glm::vec3 newUp);
};

#endif