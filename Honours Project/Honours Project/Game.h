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
#include <mmsystem.h>
#include <iostream>
#include <vector>

class Game
{
private:
	//shader variables
	GLuint shaderProgram;
	rt3d::lightStruct light0;
	rt3d::materialStruct material0;
	GLuint textures[2];

	//stack of models
	std::stack<glm::mat4> mvStack;
	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	GLuint meshIndexCount[1];
	GLuint md2VertCount = 0;
	GLuint meshObjects[3];
	GLuint cubeIndexCount = 36;

	//camera

public:
	void init();
	void update();
	void draw(SDL_Window* window);
};