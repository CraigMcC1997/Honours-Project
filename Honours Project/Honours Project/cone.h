//################################################################
// A 3D cone for testing purposes
//################################################################

#pragma once
#include "Shape.h"
#include "Mesh.h"

class Cone : public Shape
{
private:
	Mesh* mesh = new Mesh();
public:
	Cone(glm::vec3 coneScale) { scale = coneScale; }
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos);
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
};

