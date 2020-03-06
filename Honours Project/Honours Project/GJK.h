// EVERYTHING BELOW HERE IS FOR TESTING PURPOSES ONLY!!! 
// CODE TAKEN FROM ->>> http://in2gpu.com/2014/05/18/gjk-algorithm-3d/
// THE BELOW IS NOT ALL MY WORK AND SHOULD NOT APPEAR IN FINAL CODE WITHOUT 
// PERSONALISED CHANGES AND EDITIONS

#pragma once
#include "collisionDetector.h"
#include "SupportFunction.h"
//#include "Simplex.h"
#include "Maths.h"

class GJK : public collisionDetector
{
private:
	//subsections of the algorithm
	SupportFunction* support = new SupportFunction();

	int steps = 0;
	int simplexSize = 0;
	glm::vec3 simplex[4];

public:
	GJK() { /*fill(std::begin(simplex), std::end(simplex), glm::vec3(0, 0, 0));*/ }

	bool performDetection(vector<glm::vec3>&, vector<glm::vec3>&);
	bool ContainsOrigin(glm::vec3);
	bool line(glm::vec3 direction);
	bool triangle(glm::vec3);
	bool tetrahedron(glm::vec3);
	bool checkTetrahedron(const glm::vec3, const glm::vec3, 
		const glm::vec3, const glm::vec3, glm::vec3);
};