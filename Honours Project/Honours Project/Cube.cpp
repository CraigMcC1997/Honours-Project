#include "Cube.h"

void Cube::init()
{
	//model loading
	rt3d::loadObj("../Resources/Models/cube.obj", verts, norms, tex_coords, indices);
	meshIndexCount = indices.size();
	storedVerts = verts;
	meshObjects = rt3d::createMesh(verts.size() / 3, verts.data(), nullptr, norms.data(), tex_coords.data(),
		meshIndexCount, indices.data());
	verts.clear(), norms.clear(), tex_coords.clear(), indices.clear();
}

glm::vec3 Cube::getPosition()
{
	return position;
}

void Cube::setPosition(glm::vec3 newPos)
{
	position = newPos;
}

vector<GLfloat> Cube::getVerts()
{
	cout << storedVerts.size() /3 << endl;
	return verts;
}

vector<glm::vec3> Cube::getHull()
{
	vector<glm::vec3> hull;
	hull.resize(storedVerts.size() / 3);
	int counter = 0;

	for (int i = 0; i < hull.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			hull[i] += storedVerts[counter];
			counter++;
		}
		//hull[i] += position;
		//hull[i] *= scale;
	}

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
	//setting objects position
	position = pos;

	glBindTexture(GL_TEXTURE_2D, texture);
	_mvStack->push(_mvStack->top());
	_mvStack->top() = glm::translate(_mvStack->top(), pos);
	_mvStack->top() = glm::rotate(_mvStack->top(), float(rotator), glm::vec3(0.0f, 1.0f, 0.0f));
	_mvStack->top() = glm::scale(_mvStack->top(), scale);
	rt3d::setUniformMatrix4fv(shader, "projection", glm::value_ptr(projection));
	rt3d::setUniformMatrix4fv(shader, "modelview", glm::value_ptr(_mvStack->top()));
	rt3d::setMaterial(shader, material0);
	rt3d::drawIndexedMesh(meshObjects, meshIndexCount, GL_TRIANGLES);
	_mvStack->pop();
}