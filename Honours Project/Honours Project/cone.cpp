#include "cone.h"

void Cone::init()
{
	mesh->loadMesh("../Resources/Models/cone.obj");
}

glm::vec3 Cone::getPosition()
{
	return transform->getPosition();
}

void Cone::move(glm::vec3 translation)
{
	transform->Translate(translation);
}


vector<glm::vec3> Cone::getHull()
{
	return cHull;
}

void Cone::setHull(vector<glm::vec3> hull)
{
	cHull = hull;
}

void Cone::update()
{
	rotator += 0.02f;
}

void Cone::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, transform->getPosition());
}