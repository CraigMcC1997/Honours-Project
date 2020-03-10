// CODE FROM http://www.dyn4j.org/2010/01/sat/


#pragma once
#include "collisionDetector.h"

class SAT : public collisionDetector
{
private:

public:
	bool performDetection(vector<glm::vec3>&, vector<glm::vec3>&);
};