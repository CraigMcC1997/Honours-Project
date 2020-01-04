#include "Move.h"

namespace Move
{
	//variables
	GLfloat r = 0.0f;

	glm::vec3 moveZ(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		return glm::vec3(pos.x, pos.y, pos.z + d);
	}

	glm::vec3 moveX(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		return glm::vec3(pos.x + d, pos.y, pos.z);
	}

	const GLfloat getRotation()
	{
		return r;
	}
}