//################################################################
// A 3D cube for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cube : public Shape
{
public:
	Cube(glm::vec3 cubeScale) { scale = cubeScale; }
	void init();
	void update();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos);
	glm::vec3 getPosition();
	vector<GLfloat> getVerts();
};

