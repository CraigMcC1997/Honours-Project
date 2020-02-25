//#######################################
// !! (c) Marco Gilardi, 2017 !!
//#######################################

#pragma once
#include "glm/glm.hpp"
#include <glm\gtc\matrix_access.hpp>

#include <iostream>

class Transform
{
private:
	glm::mat4 transformMatrix;
public:
	Transform();
	virtual ~Transform() {}

	void Translate(glm::vec3& translation);
	void Scale(glm::vec3 scaling);
	
	void RotateX(float angle); 
	void RotateY(float angle); 
	void RotateZ(float angle);

	glm::vec3 getPosition();
	glm::vec3 getScale();
	glm::vec3 getOrientation();
	glm::vec3 getUpDir();
	glm::vec3 getLeftDir();

	glm::mat4 localToWorldMatrix();
	glm::mat4 worldToLocalMatrix();
};