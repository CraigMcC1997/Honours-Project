#pragma once
#include "Window.h"
#include "Player.h"
#include "loadTexture.h"
#include "Box.h"
#include "circle.h"
#include "cone.h"
#include "cylinder.h"
#include "Convex_Hull.h"

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
	Convex_Hull* cHull = new Convex_Hull();

	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position

	//shader variables
	GLuint shaderProgram;
	GLuint textures[12];

	//stack of models
	std::stack<glm::mat4> mvStack;

	bool firstMouse = true;
	float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0;
	float lastY = 600.0 / 2.0;
	float fov = 45.0f;

	int x, y;

public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void mouse_callback(double xpos, double ypos);
};