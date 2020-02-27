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

void Cube::moveCube()
{
	//if (transform->getPosition().x < -5)
	//	left = false;
	//if (transform->getPosition().x > 5)
	//	left = true;
	//
	//if (left)
	//	move(glm::vec3(transform->getPosition()));

	//cout << "X: " << transform->getPosition().x << endl;
	//cout << "Y: " << transform->getPosition().y << endl;
	//cout << "Z: " << transform->getPosition().z << endl;
	///*if (!left)
	//	move(glm::vec3((transform->getPosition().x + 0.001f),
	//		transform->getPosition().y, transform->getPosition().z));*/
}

void Cube::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cube::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		points[i] += transform->getPosition();
		points[i] *= transform->getScale();
	}
		
	collidable->setConvexHull(points);
}

void Cube::VelocityVerletSolver(float dt)
{
	move(dt * velocity + 0.5f * dt * dt * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Cube::update(float dt)
{
	VelocityVerletSolver(dt);
	//transform->RotateY(0.1f);
	//rotator += 0.1f;
}

void Cube::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, 
		transform->getPosition(), transform->getScale());
}