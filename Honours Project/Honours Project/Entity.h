//################################################################
// An abstract entity class based on Marco Gilardi's entity class
//################################################################

#pragma once
#include <GL/glew.h>
#include <SDL.h>

#include <glm/glm.hpp>

#include <stack>
#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <iostream>
#include <vector>

using namespace std;

class Entity
{
public:
	virtual void init() = 0;
};