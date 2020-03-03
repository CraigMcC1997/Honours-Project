#include "cylinder.h"

void Cylinder::init()
{
	mesh->loadMesh("../Resources/Models/cylinder.obj");
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
	setHull(collidable->getConvexHull());
}

void Cylinder::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cylinder::move(float dt, glm::vec3 dir)
{
	//updateVelocity(dir);
	VelocityVerletSolver(dt);
}

void Cylinder::updateVelocity(glm::vec3 newVelocity)
{
	velocity = newVelocity;
}

glm::vec3 Cylinder::getVelocity()
{
	return velocity;
}

void Cylinder::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		points[i] += transform->getPosition();
		points[i] *= transform->getScale();
	}

	collidable->setConvexHull(points);

	//for (int i = 0; i < points.size(); ++i)
	//{
	//	cout << "---" << endl;
	//	cout << "COLLIDABLE POS:" << endl;
	//	cout << "X: " << collidable->getConvexHull()[i].x << endl;
	//	cout << "Y: " << collidable->getConvexHull()[i].y << endl;
	//	cout << "Z: " << collidable->getConvexHull()[i].z << endl;
	//}

	//cout << "---" << endl;
	//cout << "MESH POS:" << endl;
	//cout << "X: " << transform->getPosition().x << endl;
	//cout << "Y: " << transform->getPosition().y << endl;
	//cout << "Z: " << transform->getPosition().z << endl;

}

glm::vec3 Cylinder::getPosition()
{
	return transform->getPosition();
}

vector<glm::vec3> Cylinder::getHull()
{
	return collidable->getConvexHull();
}

void Cylinder::update(/*float dt*/)
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