#include "Simplex.h"

void Simplex::addPoint(glm::vec3 newPoint) {
	simplex.push_back(newPoint); //add point
	lastPoint = newPoint;		 //last point
}

glm::vec3 Simplex::getLastPoint() {
	return lastPoint;
}






