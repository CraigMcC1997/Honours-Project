#include "SAT.h"

bool SAT::performDetection(/*vector<glm::vec3> hull1, vector<glm::vec3> hull2*/)
{
	// projections
	// based on algorithms from --->>https://www.metanetsoftware.com/technique/tutorialA.html
	glm::vec3 proj;
	glm::vec3 a, b;
	proj.x = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.x;
	proj.y = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.y;
	proj.z = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.z;


	return false;
}