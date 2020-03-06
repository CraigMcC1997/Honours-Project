#pragma once
#include "PlaySound.h"
#include "Window.h"
#include "loadTextures.h"
#include "Player.h"
#include "Shape.h"
#include "Cube.h"
#include "Sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "GJK.h"
#include "Grid.h"
#include <time.h>

class Game
{
private:
	//shapes
	//Cube* boxes[10];
	Cube* box;
	Cube* box2;
	Cube* box3;
	Cube* box4;
	Sphere* ball;
	Cone* cone;
	Cylinder* cylinder;

	Player* player = new Player();
	GJK* gjk = new GJK();
	GJK* gjk2 = new GJK();
	Grid* grid;

	//container of shapes
	vector<Shape*> gameEntities;

	GLuint textures[5];
	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position
	GLuint shaderProgram;
	std::stack<glm::mat4> mvStack;

	//Mouse Controls
	bool firstMouse = true;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0;
	float lastY = 600.0 / 2.0;
	float fov = 45.0f;

	//Used by BASS library
	HSAMPLE* samples = new HSAMPLE[5];
public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void mouse_callback(double xpos, double ypos);
	void checkCollisions();
	void moveObjects();
};