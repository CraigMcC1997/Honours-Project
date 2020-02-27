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
	return collidable->getConvexHull();
}

void Cone::setHull(vector<glm::vec3> points)
{
	collidable->setConvexHull(points);
}

void Cone::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cone::update(float dt)
{
	rotator += 0.02f;
}

void Cone::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, 
		transform->getPosition(), transform->getScale());
}