//################################################################
// A sphere for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(glm::vec3 sphereScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(sphereScale);
		move(pos);
		this->texture = texture;
	}
	void init();
	void update(float dt);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);

	void move(glm::vec3 translation);
	void changeTexture(GLuint);
};

