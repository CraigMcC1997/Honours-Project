// ######################################################################################
//
// This class contains the convex hull created by the shape implementing it
//
// ######################################################################################

#pragma once
#include <glm/glm.hpp>
#include <vector>

class Collidable
{
private:
	std::vector<glm::vec3> convexHull;
public:
	void setConvexHull(std::vector<glm::vec3> points);
	std::vector<glm::vec3> getConvexHull();
};