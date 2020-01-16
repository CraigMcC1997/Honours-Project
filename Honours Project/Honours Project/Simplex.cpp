#include "Simplex.h"

void Simplex::addPoint(glm::vec3 newPoint)
{
	simplex.push_back(newPoint);	// add new point to the simplex
	lastPoint = newPoint;			// label this as the last point added so far
}

glm::vec3 Simplex::getLastPoint()
{
	return lastPoint;
}
