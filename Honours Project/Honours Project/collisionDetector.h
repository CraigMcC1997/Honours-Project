#pragma once
#include <vector>
#include <glm/glm.hpp>

using namespace std;

class collisionDetector
{
public:
	virtual bool performDetection(vector<glm::vec3>, vector<glm::vec3>) = 0;
};