#include "Mesh.h"

void Mesh::loadMesh(string filename)
{
	//model loading
	rt3d::loadObj(filename.c_str(), verts, norms, tex_coords, indices);
	meshIndexCount = indices.size();
	meshObjects = rt3d::createMesh(verts.size() / 3, verts.data(), 
		nullptr, norms.data(), tex_coords.data(),
		meshIndexCount, indices.data());
	norms.clear(), tex_coords.clear(), indices.clear();
}

void Mesh::drawMesh(GLuint shader, std::stack<glm::mat4>* _mvStack,
 glm::mat4 projection, GLuint texture, Transform* modelMatrix)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	_mvStack->push(_mvStack->top());
	_mvStack->top() = _mvStack->top() * *(modelMatrix->getModelMatrix());
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
