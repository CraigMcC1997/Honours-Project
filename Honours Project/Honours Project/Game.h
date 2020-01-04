#pragma once
#include "Window.h"
#include "rt3d.h"
#include "rt3dObjLoader.h"
#include "Camera.h"
#include "Move.h"

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
	//shader variables
	GLuint ShaderProgram;
	rt3d::lightStruct light0;
	rt3d::materialStruct material0;

	//stack of models
	std::stack<glm::mat4> mvStack;

	//camera

public:
	void init();
	void update();
	void draw(SDL_Window* window);
};