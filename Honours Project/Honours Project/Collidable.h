#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Quickhull/QuickHull.hpp"

using namespace std;
using namespace quickhull;

class Collidable
{
private:
	vector<glm::vec3> convexHull;
	QuickHull<float> qh; // Could be double as well
public:
	void setConvexHull(vector<glm::vec3> points);
	vector<glm::vec3> getConvexHull();
};