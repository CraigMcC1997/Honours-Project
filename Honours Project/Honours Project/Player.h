// ######################################################################################
//
// This class contains the player, with access to the camera to move and changing shapes
// for collision testing purposes
//
// ######################################################################################

#pragma once
#include "Entity.h"
#include "Camera.h"
#include "loadTextures.h"
#include "PlaySound.h"

#include "Cube.h"
#include "Cone.h"
#include "Sphere.h"
#include "cylinder.h"


class Player : public Entity
{
private:
	GLuint texture;
	int playerShape = 1;
	glm::vec3 camPosition;
	glm::vec3 playerPosition;
	glm::vec3 cubePosition = glm::vec3(0.0f, -1000.0f, 0.0f);
	glm::vec3 ballPosition = glm::vec3(0.0f, -1100.0f, 0.0f);
	glm::vec3 conePosition = glm::vec3(0.0f, -1200.0f, 0.0f);
	glm::vec3 cylinderPosition = glm::vec3(0.0f, -1300.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.5f, 1.5f, 1.5f);

	Cube* box;
	Sphere* ball;
	Cone* cone;
	Cylinder* cylinder;

	//Used by BASS library
	HSAMPLE* samples = new HSAMPLE[1];
	bool allowSound = true, playingSound = false;

	void cameraUpdate(const Uint8*);

public:
	Player() {}
	void init();
	void update();
	void draw(GLuint, std::stack<glm::mat4>*, glm::mat4);

	void move(glm::vec3);
	void changeShape(const Uint8*);
	void storePosition();
	void playClick();

	Cube* getCube();
	Sphere* getBall();
	Cone* getCone();
	Cylinder* getCylinder();
};

