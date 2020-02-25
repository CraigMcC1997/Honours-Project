#include "Cube.h"

void Cube::init()
{
	mesh->loadMesh("../Resources/Models/cube.obj");
}

glm::vec3 Cube::getPosition()
{
	return transform->getPosition();
}

void Cube::move(glm::vec3 translation)
{
	transform->Translate(translation);
}

vector<glm::vec3> Cube::getHull()
{
	return collidable->getConvexHull();
}

void Cube::setHull(vector<glm::vec3> points)
{
	collidable->setConvexHull(points);
}

void Cube::update()
{
	//rotator += 0.001f;
}

void Cube::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
	glm::mat4 projection)
{
	//mesh->drawMesh(shader, _mvStack, projection, texture, pos);
	mesh->drawMesh(shader, _mvStack, projection, texture, transform->getPosition());
}