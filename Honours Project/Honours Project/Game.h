#pragma once
#include "Window.h"
#include "Player.h"
#include "loadTexture.h"
#include "Box.h"
#include "circle.h"
#include "cone.h"
#include "cylinder.h"

class Game
{
private:
	//shapes
	Player* player = new Player();
	Box* box = new Box();
	Box* box2 = new Box();
	Circle* circle = new Circle();
	Cone* cone = new Cone();
	Cylinder* cylinder = new Cylinder();

	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position

	//shader variables
	GLuint shaderProgram;
	GLuint textures[12];

	//stack of models
	std::stack<glm::mat4> mvStack;

public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
};