#include "cylinder.h"

void Cylinder::init()
{
	mesh->loadMesh("../Resources/Models/cylinder.obj");
}

glm::vec3 Cylinder::getPosition()
{
	return transform->getPosition();
}

void Cylinder::move(glm::vec3 translation)
{
	transform->Translate(translation);
}

vector<glm::vec3> Cylinder::getHull()
{
	return collidable->getConvexHull();
}

void Cylinder::setHull(vector<glm::vec3> points)
{
	collidable->setConvexHull(points);
}

void Cylinder::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cylinder::update()
{
	rotator -= 0.01f;
}

void Cylinder::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, 
		transform->getPosition(), transform->getScale());
}