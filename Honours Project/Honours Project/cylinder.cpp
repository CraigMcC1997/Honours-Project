#include "cylinder.h"

void Cylinder::init()
{
	mesh->loadMesh("../Resources/Models/cylinder.obj");
	makeHullContainer(*mesh->getVerts());
}

void Cylinder::VelocityVerletSolver(float dt)
{
	privMove(dt * velocity + 0.5f * (dt * dt) * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Cylinder::privMove(glm::vec3 translation)
{
	transform->Translate(translation);
	setHull(hull);
}

void Cylinder::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cylinder::move(glm::vec3 dir)
{
	updateVelocity(dir);
	VelocityVerletSolver(speed);
}

void Cylinder::updateVelocity(glm::vec3 newVelocity)
{
	velocity = newVelocity;
}

glm::vec3 Cylinder::getVelocity()
{
	return velocity;
}

void Cylinder::makeHullContainer(vector<float> points)
{
	hull.resize(points.size() /3);
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

void Cylinder::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		glm::vec4 v = glm::vec4(points[i].x, points[i].y, points[i].z, 1.0);
		glm::mat4 m = *(transform->getModelMatrix());
		v = m * v;
		points[i] = glm::vec3(v.x, v.y, v.z);
	}
	collidable->setConvexHull(points);
}

glm::vec3 Cylinder::getPosition()
{
	return transform->getPosition();
}

void Cylinder::setPosition(glm::vec3 newPosition)
{
	transform->Move(newPosition);
	setHull(hull);
}

vector<glm::vec3> Cylinder::getHull()
{
	return collidable->getConvexHull();
}

void Cylinder::update()
{
	//VelocityVerletSolver(dt);
	//transform->RotateY(0.1f);
	//rotator += 0.1f;
}

void Cylinder::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture,
		transform);// ->getPosition(), transform->getScale());
}