//################################################################
// A sphere for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(glm::vec3 sphereScale) { scale = sphereScale; }
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos);
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
};

