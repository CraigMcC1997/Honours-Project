#pragma once
#include <vector>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;

class MinkowskiSum
{
public:
	std::vector<glm::vec3> sum(std::vector<glm::vec3>, std::vector<glm::vec3>);
};