#include "Mesh.h"

void Mesh::loadMesh(string filename)
{
	//model loading
	rt3d::loadObj(filename.c_str(), verts, norms, tex_coords, indices);
	meshIndexCount = indices.size();
	//storedVerts = verts;
	meshObjects = rt3d::createMesh(verts.size() / 3, verts.data(), nullptr, norms.data(), tex_coords.data(),
		meshIndexCount, indices.data());
	//verts.clear(); 
	norms.clear(), tex_coords.clear(), indices.clear();
}

void Mesh::drawMesh(GLuint shader, std::stack<glm::mat4>* _mvStack,
 glm::mat4 projection, GLuint texture, Transform* modelMatrix)//glm::vec3 pos, glm::vec3 scale)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	_mvStack->push(_mvStack->top());
	//_mvStack->top() = glm::translate(_mvStack->top(), modelMatrix->getPosition());
	//_mvStack->top() = glm::rotate(_mvStack->top(), float(rotator), glm::vec3(0.0f, 1.0f, 0.0f));
	_mvStack->top() = _mvStack->top() * *(modelMatrix->getModelMatrix());//glm::scale(_mvStack->top(), scale);
	rt3d::setUniformMatrix4fv(shader, "projection", glm::value_ptr(projection));
	rt3d::setUniformMatrix4fv(shader, "modelview", glm::value_ptr(_mvStack->top()));
	rt3d::setMaterial(shader, material0);
	rt3d::drawIndexedMesh(meshObjects, meshIndexCount, GL_TRIANGLES);
	_mvStack->pop();
}

vector<GLfloat>* Mesh::getVerts()
{
	return &verts;
}
