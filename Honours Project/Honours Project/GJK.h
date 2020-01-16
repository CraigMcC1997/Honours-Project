#pragma once
#include "Convex_Hull.h"
#include "SupportFunction.h"
#include "Simplex.h"

class GJK
{
private:
	//subsections of the algorithm
	Convex_Hull* cHull = new Convex_Hull();
	SupportFunction* support = new SupportFunction();
	Simplex* simplex = new Simplex();

	//!!TEST CODE!!

	glm::vec3 direction;

	//arbitrary point clouds for convex hull
	vector<glm::vec3> points =
	{ {1, 1, 1}, {1, 6, 4}, {7, 1, 1}, {7, 6, 4}, {3, 3, 5} };

	vector<glm::vec3> points2 =
	{ {1, 3, 1}, {1, 6, 1}, {5, 3, 1}, {7, 6, 1}, {2, 3, 1} };

	//testing support function
	vector<glm::vec3> points3 = {
	{3, 2, 1}, {1, 6, 1}, {7, 1, 1} };

	vector<glm::vec3> points4 = {
	{3, 2, 1}, {1, 6, 1}, {7, 1, 1} };
public:
	void performGJK();
};