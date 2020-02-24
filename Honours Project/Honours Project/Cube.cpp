#include "Cube.h"

void Cube::init()
{
	mesh->loadMesh("../Resources/Models/cube.obj");
}

glm::vec3 Cube::getPosition()
{
	return position;
}

void Cube::setPosition(glm::vec3 newPos)
{
	position = newPos;
}

//vector<GLfloat> Cube::getVerts()
//{
//	cout << storedVerts.size() /3 << endl;
//	return verts;
//}
//
vector<glm::vec3> Cube::getHull()
{
	vector<glm::vec3> hull;
//	hull.resize(storedVerts.size() / 3);
//	int counter = 0;
//
//	for (int i = 0; i < hull.size(); i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			hull[i] += storedVerts[counter];
//			counter++;
//		}
//		//hull[i] += position;
//		//hull[i] *= scale;
//	}
//
	return hull;
}

void Cube::setHull(vector<glm::vec3> hull)
{
	cHull = hull;
}

void Cube::update()
{
	//rotator += 0.001f;
}

void Cube::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	mesh->drawMesh(shader, _mvStack, projection, texture, pos);
}