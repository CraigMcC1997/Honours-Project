#pragma once

#ifndef MOVE
#define MOVE
#define DEG_TO_RADIAN 0.017453293
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace std;

namespace Move
{
	glm::vec3 moveZ(glm::vec3 pos, GLfloat angle, GLfloat d);
	glm::vec3 moveX(glm::vec3 pos, GLfloat angle, GLfloat d);
	glm::vec3 moveY(glm::vec3 pos, GLfloat angle, GLfloat d);
	const glm::vec3 getRotation();
	void setRotation(glm::vec3 newRot);
};
#endif