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
#include "Mouse.h"
#include <time.h>

class Game
{
private:
	//mouse
	Mouse* mouse = new Mouse();

	//shapes
	Cube* boxes[5];
	Sphere* ball[5];
	Cone* cone[5];
	Cylinder* cylinder[5];
	const int MAX_SHAPES = 5;

	Player* player = new Player();
	GJK* gjk = new GJK();
	Grid* grid;

	//container of shapes
	vector<Shape*> gameEntities;

	GLuint textures[4];
	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position
	GLuint shaderProgram;
	std::stack<glm::mat4> mvStack;

	//Used by BASS library
	HSAMPLE* samples = new HSAMPLE[5];
public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void checkCollisions();
};