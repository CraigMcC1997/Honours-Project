//################################################################
// A sphere for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Sphere : public Shape
{
private:
	void privMove(glm::vec3 translation);
	void VelocityVerletSolver(float dt);
public:
	Sphere(glm::vec3 sphereScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(sphereScale);
		privMove(pos);
		this->texture = texture;
	}
	void init();
	void update(float dt);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);

	void changeTexture(GLuint);
	void move(float dt);
	void updateVelocity(glm::vec3);
	glm::vec3 getVelocity();
};

