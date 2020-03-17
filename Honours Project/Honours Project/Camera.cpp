#include "Camera.h"

namespace camera
{
	glm::vec3 cameraPos = glm::vec3(-20.0f, 0.0f, 20.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::vec3 getEye()
	{
		return cameraPos;
	}
	glm::vec3 getFront()
	{
		return cameraFront;
	}
	glm::vec3 getUp()
	{
		return cameraUp;
	}


	void setEye(glm::vec3 newEye)
	{
		cameraPos = newEye;
	}
	void setFront(glm::vec3 newAt)
	{
		cameraFront = newAt;
	}
	void setUp(glm::vec3 newUp)
	{
		cameraUp = newUp;
	}
}