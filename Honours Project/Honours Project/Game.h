#pragma once
#include "Window.h"
#include "Camera.h"
#include "Move.h"
#include "loadTexture.h"
#include "Box.h"

class Game
{
private:
	//box
	Box* box = new Box();
	Box* box2 = new Box();

	glm::vec3 position = glm::vec3(0, 0, 0); //Player position
	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //global light position

	//shader variables
	GLuint shaderProgram;
	GLuint textures[1];

	//stack of models
	std::stack<glm::mat4> mvStack;

	//rotation
	GLfloat rotateValueZ = 0.0f;
	GLfloat rotateValueY = 0.0f;
	float x_prev = 0.0f;
	int x = 0.0f, y = 0.0f;
	//float f_curr_x;
	//float f_dx;

public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void setPosition(glm::vec3);
};