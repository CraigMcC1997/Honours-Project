//################################################################
// A class for creating a 3D 4-simplex
//################################################################

#pragma once
#include <vector>
#include <glm/glm.hpp>

using namespace std;

class Simplex
{
private:
	vector<glm::vec3> simplex;
	glm::vec3 lastPoint;
	
public:
	void addPoint(glm::vec3 convexHull);
	glm::vec3 getLastPoint();
};