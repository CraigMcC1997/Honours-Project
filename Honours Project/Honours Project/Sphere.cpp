#include "Sphere.h"

void Sphere::init()
{
	//model loading
	mesh->loadMesh("../Resources/Models/sphere.obj");
}

glm::vec3 Sphere::getPosition()
{
	cout << position.x << endl;
	cout << position.y << endl;
	cout << position.z << endl;
	return position;
}

vector<glm::vec3> Sphere::getHull()
{
	return cHull;
}

void Sphere::setHull(vector<glm::vec3> hull)
{
	cHull = hull;
}

void Sphere::update()
{
	rotator += 0.01f;
}

void Sphere::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, pos);
}