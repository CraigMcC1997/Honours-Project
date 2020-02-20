//#############################################################
// Backup maths namespace for anything outside the scope of GLM
//#############################################################


#pragma once

#ifndef MATHS
#define MATHS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Maths
{
	glm::vec3 cross(const glm::vec3 v1, const glm::vec3 v2);
	glm::vec3 doubleCross(const glm::vec3 v1, const glm::vec3 v2);
};

#endif