//################################################################
// A 3D cylinder for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cylinder : public Shape
{
public:
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos);
	glm::vec3 getPosition();
};

