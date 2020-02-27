#pragma once
#include "PlaySound.h"
#include "Window.h"
#include "Player.h"
#include "loadTextures.h"
#include "Cube.h"
#include "Sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "GJK.h"
#include "Shape.h"

class Game
{
private:
	//shapes
	Cube* box1;
	Cube* box2;
	Sphere* ball;
	Cone* cone;
	Cylinder* cylinder;

	Player* player = new Player();
	GJK* gjk = new GJK();

	//container of shapes
	vector<Shape*> gameEntities;

	GLuint textures[3];
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

	//arbitrary point clouds for convex hull
	vector<glm::vec3> points =
	{ {1, 1, 1}, {1, 6, 1}, {7, 1, 1}, {7, 6, 1}, {3, 3, 1} };

	vector<glm::vec3> points2 =
	{ {1, 1, 1}, {-1, -6, -1}, {-7, -1, -1}, {-7, -6, -1}, {-3, -3, -1} };

	vector<glm::vec3> boxVerts =
	{ {-1.0, -1.0, -1.0}, {-1.0, -1.0,  1.0}, {-1.0, 1.0, -1.0},
	  {-1.0,  1.0,  1.0}, {1.0, -1.0, -1.0}, {1.0, -1.0,  1.0},
	  {1.0,  1.0, -1.0},  {1.0, 1.0,  1.0}
	};
public:
	void init();
	void update(SDL_Event sdlEvent, float dt);
	void draw(SDL_Window* window);
	void mouse_callback(double xpos, double ypos);
};