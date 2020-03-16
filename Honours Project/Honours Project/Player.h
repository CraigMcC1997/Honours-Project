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
	glm::vec3 hidePosition = glm::vec3(0.0f, -1000.0f, 0.0f);
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
	void draw(GLuint, std::stack<glm::mat4>*, glm::mat4);

	void move(glm::vec3);
	void changeShape(const Uint8*);
	void storePosition();

	Cube* getCube();
	Sphere* getBall();
	Cone* getCone();
	Cylinder* getCylinder();
};

