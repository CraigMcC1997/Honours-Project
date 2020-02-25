//################################################################
// An abstract entity class based on Marco Gilardi's entity class
//################################################################

#pragma once
#include "rt3d.h"
#include "rt3dObjLoader.h"

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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