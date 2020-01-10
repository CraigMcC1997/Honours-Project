//################################################################
// A class for creating a 3D 4-simplex
//################################################################

#pragma once
#include <vector>
#include <glm/glm.hpp>

using namespace std;

class Simplex
{
public:
	void performSimplex(vector<glm::vec3> convexHull, vector<glm::vec3> direction);
};