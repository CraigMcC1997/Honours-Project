#pragma once
#include <glm/glm.hpp>
#include <vector>

using namespace std;

class Collidable
{
private:
	vector<glm::vec3> convexHull;
public:
	void setConvexHull(vector<glm::vec3> points);
	vector<glm::vec3> getConvexHull();
};