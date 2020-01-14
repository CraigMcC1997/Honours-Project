//################################################################
// finds the index of the furthest point
// in a given direction
//################################################################

#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <iostream>

using namespace std;

class SupportFunction
{
public:
	unsigned int furthestPoint(glm::vec3 direction, vector<glm::vec3> points);
	glm::vec3 support(glm::vec3 direction, vector<glm::vec3> points, vector<glm::vec3> points2);
};

