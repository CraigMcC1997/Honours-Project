#include "Cube.h"

void Cube::init()
{
	mesh->loadMesh("../Resources/Models/cube.obj");
	//makeHullContainer(*mesh->getVerts());
	//setHull(hull);
}

void Cube::VelocityVerletSolver(float dt)
{
	privMove(dt * velocity + 0.5f * (dt * dt) * acceleration);
	glm::vec3 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Cube::privMove(glm::vec3 translation)
{
	transform->Translate(translation);
	setHull(boxVerts);
}

void Cube::changeTexture(GLuint newTexture)
{
	texture = newTexture;
}

void Cube::move(float dt)
{
	//updateVelocity(dir);
	VelocityVerletSolver(dt);
}

void Cube::updateVelocity(glm::vec3 newVelocity)
{
	velocity = newVelocity;
}

glm::vec3 Cube::getVelocity()
{
	return velocity;
}

void Cube::makeHullContainer(vector<float> points)
{
	hull.resize(points.size() / 3);
	int counter = 0;

	for (int i = 0; i < points.size() /3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			hull[i] += points[counter];
			counter++;
		}
		
	}
	collidable->setConvexHull(hull);

}

void Cube::setHull(vector<glm::vec3> points)
{
	for (int i = 0; i < points.size(); ++i)
	{
		glm::vec4 v = glm::vec4(points[i].x, points[i].y, points[i].z, 1.0);
		glm::mat4 m = *(transform->getModelMatrix());
		v = m * v ;
		//cout << "w: " <<  v.w << endl;
		//cout << "X: " << v.x << endl;
		//cout << "Y: " << v.y << endl;
		//cout << "Z: " << v.z << endl;
		points[i] = glm::vec3(v.x, v.y, v.z);
	}

	collidable->setConvexHull(points);

	for (int i = 0; i < points.size(); ++i)
	{
		cout << "---" << endl;
		cout << "COLLIDABLE POS:" << endl;
		cout << "X: " << collidable->getConvexHull()[i].x << endl;
		cout << "Y: " << collidable->getConvexHull()[i].y << endl;
		cout << "Z: " << collidable->getConvexHull()[i].z << endl;
	}

	//cout << "---" << endl;
	//cout << "MESH POS:" << endl;
	//cout << "X: " << transform->getPosition().x << endl;
	//cout << "Y: " << transform->getPosition().y << endl;
	//cout << "Z: " << transform->getPosition().z << endl;
}

glm::vec3 Cube::getPosition()
{
	return transform->getPosition();
}

vector<glm::vec3> Cube::getHull()
{
	return collidable->getConvexHull();
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
		transform);//->getPosition(), transform->getScale());
}