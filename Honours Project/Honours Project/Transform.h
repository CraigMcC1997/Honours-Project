// ######################################################################################
//
// This class contains a single 4x4 matrix which is used to manipulate the shape data
// i.e position, scale and rotation
//
// ######################################################################################

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
	void Move(glm::vec3& translation);
	void Scale(glm::vec3& scaling);
	
	void RotateX(float angle); 
	void RotateY(float angle); 
	void RotateZ(float angle);

	glm::vec3 getPosition();
	glm::vec3 getScale();
	glm::mat4* getModelMatrix();
};