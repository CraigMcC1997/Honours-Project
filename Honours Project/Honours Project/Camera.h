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