#include "Move.h"

namespace Move
{
	//variables
	glm::vec3 r;

	glm::vec3 moveZ(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		r = glm::vec3(d * std::sin(glm::radians(angle)), 0.0f, d * std::cos(glm::radians(angle)));
		return glm::vec3(pos.x + r.x, pos.y, pos.z + r.z);
	}

	glm::vec3 moveX(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		r = glm::vec3(d * std::cos(glm::radians(angle)), 0.0f, d * std::sin(glm::radians(angle)));
		return glm::vec3(pos.x + r.x, pos.y, pos.z + r.z);
	}

	glm::vec3 moveY(glm::vec3 pos, GLfloat angle, GLfloat d)
	{
		return glm::vec3(pos.x, pos.y + d, pos.z);
	}

	const glm::vec3 getRotation()
	{
		return r;
	}
	
	void setRotation(glm::vec3 newRot)
	{
		r = newRot;
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