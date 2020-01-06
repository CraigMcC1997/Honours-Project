//################################################################
// An abstract entity class based on Marco Gilardi's entity class
//################################################################

#pragma once
#include "rt3d.h"
#include "rt3dObjLoader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stack>
#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <iostream>
#include <vector>

class Entity
{
protected:

	rt3d::lightStruct light0 = {
								{0.4f, 0.4f, 0.4f, 1.0f}, // ambient
								{1.0f, 1.0f, 1.0f, 1.0f}, // diffuse
								{1.0f, 1.0f, 1.0f, 1.0f}, // specular
								{-5.0f, 2.0f, 2.0f, 1.0f}  // position
								};

	rt3d::materialStruct material0 = {
		{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
		{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
		{0.0f, 0.1f, 0.0f, 1.0f}, // specular
							2.0f  // shininess
	};
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection, GLuint texture, glm::vec3 pos) = 0;
};