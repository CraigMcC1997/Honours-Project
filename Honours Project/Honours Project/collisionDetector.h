#pragma once
#include <vector>
#include <glm/glm.hpp>

class collisionDetector
{
public:
	virtual bool performDetection(std::vector<glm::vec3>&, std::vector<glm::vec3>&) = 0;
};