//################################################################
// A 3D cone for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cone : public Shape
{
public:
	Cone(glm::vec3 coneScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(coneScale);
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

