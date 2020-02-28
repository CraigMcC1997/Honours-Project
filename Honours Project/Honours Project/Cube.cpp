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
	setHull(collidable->getConvexHull());
}

vector<glm::vec3> Cube::getHull()
{
	return collidable->getConvexHull();
}

void Cube::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cube::move(float dt)
{
	VelocityVerletSolver(dt);
}

void Cube::setHull(vector<glm::vec3> points)
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

void Cube::VelocityVerletSolver(float dt)
{
	move(dt * velocity + 0.5f * (dt * dt) * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Cube::update(float dt)
{
	//VelocityVerletSolver(dt);
	//transform->RotateY(0.1f);
	//rotator += 0.1f;
}

void Cube::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, 
		transform->getPosition(), transform->getScale());
}