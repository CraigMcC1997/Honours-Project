#include "Sphere.h"

void Sphere::init()
{
	mesh->loadMesh("../Resources/Models/sphere.obj");
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

void Sphere::setHull(vector<glm::vec3> points)
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