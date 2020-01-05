#pragma once
#include "Window.h"
#include "rt3d.h"
#include "rt3dObjLoader.h"
#include "Camera.h"
#include "Move.h"
#include "loadTexture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stack>
#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <iostream>
#include <vector>

class Game
{
private:
	//Position
	glm::vec3 position = glm::vec3(0, 0, 0);

	//shader variables
	GLuint shaderProgram;
	GLuint textures[1];

	rt3d::lightStruct light0 = {
	{0.4f, 0.4f, 0.4f, 1.0f}, // ambient
	{1.0f, 1.0f, 1.0f, 1.0f}, // diffuse
	{1.0f, 1.0f, 1.0f, 1.0f}, // specular
	{-5.0f, 2.0f, 2.0f, 1.0f}  // position
	};
	glm::vec4 lightPos = glm::vec4(1.0f, 2.0f, 2.0f, 1.0f); //light position

	rt3d::materialStruct material0 = {
		{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
		{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
		{0.0f, 0.1f, 0.0f, 1.0f}, // specular
							2.0f  // shininess
	};

	//stack of models
	std::stack<glm::mat4> mvStack;
	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	GLuint meshIndexCount[1];
	GLuint meshObjects[1];

	//rotation
	GLfloat rotateValueZ = 0.0f;
	GLfloat rotateValueY = 0.0f;
	float x_prev = 0.0f;
	int x = 0.0f, y = 0.0f;
	float f_curr_x;
	float f_dx;
	bool b_button_released = false;

public:
	void init();
	void update(SDL_Event sdlEvent);
	void draw(SDL_Window* window);
	void setPosition(glm::vec3);
};