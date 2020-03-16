#pragma once
#include "Entity.h"
#include "Camera.h"

#include "Cube.h"
#include "Cone.h"
#include "Sphere.h"
#include "cylinder.h"
#include "loadTextures.h"

class Player : public Entity
{
private:
	GLuint textures[4];
	int playerShape = 1;
	glm::vec3 camPosition;
	glm::vec3 playerPosition;
	glm::vec3 scale = glm::vec3(1.5f, 1.5f, 1.5f);

	Cube* box;
	Sphere* ball;
	Cone* cone;
	Cylinder* cylinder;

	void cameraUpdate(const Uint8*);

public:
	Player() {}
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection);

	void move(float dt, glm::vec3 dir);
};

