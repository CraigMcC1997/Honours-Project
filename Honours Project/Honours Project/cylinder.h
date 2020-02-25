//################################################################
// A 3D cylinder for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cylinder : public Shape
{
public:
	Cylinder(glm::vec3 cylinderScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(cylinderScale);
		move(pos);
		this->texture = texture;
	}

	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
	
	void move(glm::vec3 translation);
};