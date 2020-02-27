#include "Sphere.h"

void Sphere::init()
{
	//model loading
	mesh->loadMesh("../Resources/Models/sphere.obj");
}

glm::vec3 Sphere::getPosition()
{
	return transform->getPosition();
}

void Sphere::move(glm::vec3 translation)
{
	transform->Translate(translation);
}

vector<glm::vec3> Sphere::getHull()
{
	return collidable->getConvexHull();
}

void Sphere::setHull(vector<glm::vec3> points)
{
	collidable->setConvexHull(points);
}

void Sphere::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Sphere::update(float dt)
{
	rotator += 0.01f;
}

void Sphere::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, 
		transform->getPosition(), transform->getScale());
}