//################################################################
// A 3D cube for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cube : public Shape
{
private:
	float distance = 20;
	bool left = true;

	glm::vec3 velocity = glm::vec3(0.001, 0, 0);
	glm::vec3 acceleration = glm::vec3(0, 0, 0);
	void move(glm::vec3 translation);
	void VelocityVerletSolver(float dt);
public:
	Cube(glm::vec3 cubeScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(cubeScale);
		move(pos);
		this->texture = texture;
	}

	void init();
	void update(float dt);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection);

	void setHull(vector<glm::vec3>);
	
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();

	void changeTexture(GLuint);
	void move(float dt);
};

