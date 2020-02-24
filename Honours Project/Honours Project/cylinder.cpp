#include "cylinder.h"

void Cylinder::init()
{
	mesh->loadMesh("../Resources/Models/cylinder.obj");
}

glm::vec3 Cylinder::getPosition()
{
	cout << position.x << endl;
	cout << position.y << endl;
	cout << position.z << endl;
	return position;
}

vector<glm::vec3> Cylinder::getHull()
{
	return cHull;
}

void Cylinder::setHull(vector<glm::vec3> hull)
{
	cHull = hull;
}

void Cylinder::update()
{
	rotator -= 0.01f;
}

void Cylinder::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, pos);
}