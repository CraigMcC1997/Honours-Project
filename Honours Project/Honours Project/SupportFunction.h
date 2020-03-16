//################################################################
// finds the index of the furthest point
// in a given direction
//################################################################

#pragma once
#include <vector>
#include <glm/glm.hpp>

class SupportFunction
{
private:
	unsigned int furthestPoint(const glm::vec3& direction, const std::vector<glm::vec3>& points);
public:
	glm::vec3 support(const glm::vec3& direction, 
		const std::vector<glm::vec3>& points, const std::vector<glm::vec3>& points2);
};

