// ######################################################################################
//
// This class is the highest level abstract class for all entities within the project
//
// ######################################################################################
//################################################################
//
// An abstract entity class based on Marco Gilardi's entity class
// Computer Games Technologies, 2nd Year
//
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

class Entity
{
public:
	virtual void init() = 0;
};