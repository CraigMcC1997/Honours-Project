// ######################################################################################
//
// This is the collision system for this project: The GJK collision detection system
//
// ######################################################################################
// ######################################################################################
//
// This code was based on code from ->>> http://in2gpu.com/2014/05/18/gjk-algorithm-3d/
//
// ######################################################################################

#pragma once
#include "collisionDetector.h"
#include "SupportFunction.h"

class GJK : public collisionDetector
{
private:
	SupportFunction* support = new SupportFunction();

	int steps;
	int simplexSize = 0;
	glm::vec3 simplex[4];
	glm::vec3 direction = glm::vec3(1, 1, 1);

	bool initialise(std::vector<glm::vec3>&, std::vector<glm::vec3>&);
	bool ContainsOrigin(glm::vec3&);
	bool triangle(glm::vec3&);
	bool tetrahedron(glm::vec3&);
	bool checkTetrahedron(const glm::vec3&, const glm::vec3&,
		const glm::vec3&, const glm::vec3&, glm::vec3&);

public:
	GJK() { };
	bool performDetection(std::vector<glm::vec3>&, std::vector<glm::vec3>&);
};