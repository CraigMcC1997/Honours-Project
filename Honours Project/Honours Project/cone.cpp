#include "cone.h"

void Cone::init()
{
	mesh->loadMesh("../Resources/Models/cone.obj");
}

void Cone::VelocityVerletSolver(float dt)
{
	privMove(dt * velocity + 0.5f * (dt * dt) * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Cone::privMove(glm::vec3 translation)
{
	transform->Translate(translation);
	setHull(collidable->getConvexHull());
}

void Cone::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cone::move(float dt, glm::vec3 dir)
{
	//updateVelocity(dir);
	VelocityVerletSolver(dt);
}

void Cone::updateVelocity(glm::vec3 newVelocity)
{
	velocity = newVelocity;
}

glm::vec3 Cone::getVelocity()
{
	return velocity;
}

void Cone::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		glm::vec4 v = glm::vec4(points[i].x, points[i].y, points[i].z, 1.0);
		glm::mat4 m = *(transform->getModelMatrix());
		v = m * v;
		//cout << "w: " <<  v.w << endl;
		//cout << "X: " << v.x << endl;
		//cout << "Y: " << v.y << endl;
		//cout << "Z: " << v.z << endl;
		points[i] = glm::vec3(v.x, v.y, v.z);
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

glm::vec3 Cone::getPosition()
{
	return transform->getPosition();
}

vector<glm::vec3> Cone::getHull()
{
	return collidable->getConvexHull();
}

void Cone::update(/*float dt*/)
{
	//VelocityVerletSolver(dt);
	//transform->RotateY(0.1f);
	//rotator += 0.1f;
}

void Cone::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection)
{
	mesh->drawMesh(shader, _mvStack, projection, texture,
		transform);//->getPosition(), transform->getScale());
}