//################################################################
// convex hull class based on https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
//################################################################
#pragma once
#include <vector>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Convex_Hull
{
public:
	int orientation(glm::vec3 p, glm::vec3 q, glm::vec3 r);
	void convexHull(glm::vec3 points[], int n);
};