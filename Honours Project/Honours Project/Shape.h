// ######################################################################################
//
// This class handles all shape data and acts as a middle management class for all shapes
//
// ######################################################################################

#pragma once
#include "Entity.h"
#include "Mesh.h"
#include "Transform.h"
#include "Collidable.h"

class Shape : public Entity
{
protected:
	Mesh* mesh = new Mesh();
	Transform* transform = new Transform();
	Collidable* collidable = new Collidable();
	glm::vec3 scale;
	GLuint texture;
	vector<glm::vec3> cHull;
	float speed = 0.1;

	glm::vec3 velocity = glm::vec3(1.5, 0, 0);
	glm::vec3 acceleration = glm::vec3(0, 0, 0);

public:
	virtual void update() = 0;
	virtual void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection) = 0;
	
	virtual void setHull(vector<glm::vec3>) = 0;
	virtual void makeHullContainer(vector<float> points) = 0;
	virtual void changeTexture(GLuint newTexture) = 0;
	virtual void move(glm::vec3 dir) = 0;
	virtual void updateVelocity(glm::vec3) = 0;

	virtual glm::vec3 getPosition() = 0;
	virtual vector<glm::vec3> getHull() = 0;
	virtual glm::vec3 getVelocity() = 0;
};