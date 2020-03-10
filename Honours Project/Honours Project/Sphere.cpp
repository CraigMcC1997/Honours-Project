#include "Sphere.h"

void Sphere::init()
{
	mesh->loadMesh("../Resources/Models/sphere.obj");
	makeHullContainer(*mesh->getVerts());
}

void Sphere::VelocityVerletSolver(float dt)
{
	privMove(dt * velocity + 0.5f * (dt * dt) * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Sphere::privMove(glm::vec3 translation)
{
	transform->Translate(translation);
	setHull(collidable->getConvexHull());
}

void Sphere::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Sphere::move(float dt, glm::vec3 dir)
{
	//updateVelocity(dir);
	VelocityVerletSolver(dt);
}

void Sphere::updateVelocity(glm::vec3 newVelocity)
{
	velocity = newVelocity;
}

glm::vec3 Sphere::getVelocity()
{
	return velocity;
}

void Sphere::makeHullContainer(vector<float> points)
{
	hull.resize(8);
	int counter = 0;

	for (int i = 0; i < hull.size(); ++i)
	{
		hull[i].x = points[counter];
		hull[i].y = points[counter + 1];
		hull[i].z = points[counter + 2];
		counter += 3;
	}
	setHull(hull);
}

void Sphere::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		points[i] += transform->getPosition();
		points[i] *= transform->getScale();
	}

	collidable->setConvexHull(points);
}

glm::vec3 Sphere::getPosition()
{
	return transform->getPosition();
}

vector<glm::vec3> Sphere::getHull()
{
	return collidable->getConvexHull();
}

void Sphere::update()
{
	//VelocityVerletSolver(dt);
	//transform->RotateY(0.1f);
	//rotator += 0.1f;
}

void Sphere::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture,
		transform);// ->getPosition(), transform->getScale());
}