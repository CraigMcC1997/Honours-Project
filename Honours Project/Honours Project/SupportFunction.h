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
	unsigned int furthestPoint(const glm::vec3 direction, const vector<glm::vec3> points);
	glm::vec3 support(const glm::vec3 direction, 
		const vector<glm::vec3> points, const vector<glm::vec3> points2);
};

