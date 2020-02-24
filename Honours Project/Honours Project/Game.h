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
	Cube* box2 = new Cube(glm::vec3(1.5f, 1.5f, 1.5f));
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
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0;
	float lastY = 600.0 / 2.0;
	float fov = 45.0f;

	int x, y;

	//arbitrary point clouds for convex hull
	vector<glm::vec3> points =
	{ {1, 1, 1}, {1, 6, 1}, {7, 1, 1}, {7, 6, 1}, {3, 3, 1} };

	vector<glm::vec3> points2 =
	{ {1, 1, 1}, {-1, -6, -1}, {-7, -1, -1}, {-7, -6, -1}, {-3, -3, -1} };

public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void mouse_callback(double xpos, double ypos);
};