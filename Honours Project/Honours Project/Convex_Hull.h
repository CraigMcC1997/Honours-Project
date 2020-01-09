//################################################################
// convex hull class based on https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
// Jarvis algorithm for convex hulls
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
	vector<glm::vec3> convexHull(vector<glm::vec3> points, int n);
};