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

	glm::vec3 moveY(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		return glm::vec3(pos.x, pos.y + d, pos.z);
	}

	const GLfloat getRotation()
	{
		return r;
	}
}




//used for moving forward and backwards
//glm::vec3 moveForward(glm::vec3 cam, GLfloat angle, GLfloat d)
//{
//	return glm::vec3(cam.x + d * std::sin(glm::radians(angle)),
//		cam.y, cam.z - d * std::cos(glm::radians(angle)));
//}
//
////used for moving left and right
//glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d)
//{
//	return glm::vec3(pos.x + d * std::cos(glm::radians(angle)),
//		pos.y, pos.z + d * std::sin(glm::radians(angle)));
//}