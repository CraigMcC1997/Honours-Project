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