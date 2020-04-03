// ######################################################################################
//
// The support function finds the furthest point in a given direction
//
// ######################################################################################

#pragma once
#include <vector>
#include <glm/glm.hpp>

class SupportFunction
{
private:
	unsigned int furthestPoint(const glm::vec3&, const std::vector<glm::vec3>&);
public:
	glm::vec3 support(const glm::vec3&, 
		const std::vector<glm::vec3>&, const std::vector<glm::vec3>&);
};

