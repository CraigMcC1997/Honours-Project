//################################################################
// A 3D cone for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cone : public Shape
{
private:
	void privMove(glm::vec3 translation);
	void VelocityVerletSolver(float dt);

	vector<glm::vec3> hull;
public:
	Cone(glm::vec3 coneScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(coneScale);
		privMove(pos);
		this->texture = texture;
	}
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);

	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
	
	void changeTexture(GLuint);
	void move(float dt, glm::vec3 dir);
	void updateVelocity(glm::vec3);
	glm::vec3 getVelocity();
	void makeHullContainer(vector<float> points);
};

