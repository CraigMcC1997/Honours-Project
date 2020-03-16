//################################################################
// A 3D cube for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cube : public Shape
{
private:
	void privMove(glm::vec3 translation);
	void VelocityVerletSolver(float dt);
	
	vector<glm::vec3> hull;
public:
	Cube(glm::vec3 cubeScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(cubeScale);
		privMove(pos);
		this->texture = texture;
	}
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection);

	void setHull(vector<glm::vec3>);
	
	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);
	vector<glm::vec3> getHull();

	void changeTexture(GLuint);
	void move(glm::vec3 dir);
	void updateVelocity(glm::vec3);
	glm::vec3 getVelocity();
	void makeHullContainer(vector<float> points);
};