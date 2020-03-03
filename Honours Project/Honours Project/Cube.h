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

	vector<glm::vec3> boxVerts =
	{ {-1.0, -1.0, -1.0}, {-1.0, -1.0,  1.0}, {-1.0, 1.0, -1.0},
	  {-1.0,  1.0,  1.0}, {1.0, -1.0, -1.0}, {1.0, -1.0,  1.0},
	  {1.0,  1.0, -1.0},  {1.0, 1.0,  1.0}
	};
	
	vector<glm::vec3> hull;
public:
	Cube(glm::vec3 cubeScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(cubeScale);
		privMove(pos);
		this->texture = texture;
		setHull(boxVerts);
	}

	void init();
	void update(/*float dt*/);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection);

	void setHull(vector<glm::vec3>);
	
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();

	void changeTexture(GLuint);
	void move(float dt, glm::vec3 dir);
	void updateVelocity(glm::vec3);
	glm::vec3 getVelocity();
	void makeHullContainer(vector<float> points);
};