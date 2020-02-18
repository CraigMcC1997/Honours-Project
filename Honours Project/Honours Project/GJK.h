#pragma once
#include "collisionDetector.h"
#include "SupportFunction.h"
#include "Simplex.h"

class GJK : public collisionDetector
{
private:
	//subsections of the algorithm
	SupportFunction* support = new SupportFunction();
	//Simplex* simplex = new Simplex();

	//!!TEST CODE!!

	glm::vec3 direction = glm::vec3(1, 1, 1);

	//arbitrary point clouds for convex hull
	vector<glm::vec3> points =
	{ {1, 1, 1}, {1, 6, 1}, {7, 1, 1}, {7, 6, 1}, {3, 3, 1} };

	vector<glm::vec3> points2 =
	{ {1, 1, 1}, {-1, -6, -1}, {-7, -1, -1}, {-7, -6, -1}, {-3, -3, -1} };

	/*vector<glm::vec3> points2 =
	{ {1, 3, 1}, {1, 8, 1}, {5, 3, 1}, {7, 6, 1}, {2, 3, 1} };*/

	/*vector<glm::vec3> points2 =
	{ {1, 1, 1}, {1, 6, 4}, {7, 1, 1}, {7, 6, 4}, {3, 3, 5} };*/



	//testing support function
	vector<glm::vec3> points3 = {
	{3, 2, 1}, {1, 6, 1}, {7, 1, 1} };

	vector<glm::vec3> points4 = {
	{3, 2, 1}, {1, 6, 1}, {7, 1, 1} };



	int iter_count = 0;


	//TEST CODE
	//glm::vec3 a, b, c, d;
	int simplexSize = 0;
	glm::vec3 simplex[4];


public:
	bool performDetection(/*vector<glm::vec3>, vector<glm::vec3>*/);


	// TESTING CODE ONLY!!
	bool ContainsOrigin(glm::vec3);
	bool triangle(glm::vec3);
	bool tetrahedron(glm::vec3);
	bool checkTetrahedron(const glm::vec3, const glm::vec3, 
		const glm::vec3, const glm::vec3, glm::vec3 dir);
};