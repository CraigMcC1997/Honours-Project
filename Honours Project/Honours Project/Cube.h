//################################################################
// A 3D cube for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cube : public Shape
{
public:
	Cube(glm::vec3 cubeScale, glm::vec3 pos, GLuint texture) {
		scale = cubeScale;
		move(pos);
		this->texture = texture;
	}

	void init();
	void update();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);
	glm::vec3 getPosition();


	void move(glm::vec3 translation);
};

