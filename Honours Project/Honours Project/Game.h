// ######################################################################################
//
// This class handles all game functionality and provides a working example
// of the collision detection system implemented
//
// ######################################################################################

#pragma once
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

	//range for shape positions
	const int MAX_X = 50, MAX_Y = 20, MAX_Z = 30;

	//shapes
	static const int MAX_SHAPES = 5;
	Cube* boxes[MAX_SHAPES];
	Cone* cone[MAX_SHAPES];
	Sphere* ball[MAX_SHAPES];
	Cylinder* cylinder[MAX_SHAPES];

	Player* player = new Player();
	GJK* gjk = new GJK();
	Grid* grid;

	//container of shapes
	vector<Shape*> gameEntities;

	GLuint textures[4];
	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position
	GLuint shaderProgram;
	std::stack<glm::mat4> mvStack;
public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void checkCollisions();
};