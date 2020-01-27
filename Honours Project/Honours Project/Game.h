#pragma once
#include "Window.h"
#include "Player.h"
#include "loadTextures.h"
#include "Cube.h"
#include "Sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "GJK.h"

class Game
{
private:
	//shapes
	Player* player = new Player();
	Cube* box1 = new Cube(glm::vec3(1.5f, 1.5f, 1.5f));
	Cube* box2 = new Cube(glm::vec3(3.5f, 3.5f, 3.5f));
	Sphere* circle = new Sphere(glm::vec3(2.0f, 2.0f, 2.0f));
	Cone* cone = new Cone(glm::vec3(3.0f, 3.0f, 3.0f));
	Cylinder* cylinder = new Cylinder(glm::vec3(2.5f, 2.5f, 2.5f));

	GJK* gjk = new GJK();
	

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