#pragma once
#include <vector>
#include <glm/glm.hpp>

using namespace std;

class SupportFunction
{
public:
	vector<glm::vec3> support(vector<glm::vec3> direction);
};

