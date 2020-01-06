#include "cone.h"

void Cone::init()
{
	//model loading
	rt3d::loadObj("../Resources/Models/cone.obj", verts, norms, tex_coords, indices);
	meshIndexCount[0] = indices.size();
	meshObjects[0] = rt3d::createMesh(verts.size() / 3, verts.data(), nullptr, norms.data(), tex_coords.data(),
		meshIndexCount[0], indices.data());
	verts.clear(), norms.clear(), tex_coords.clear(), indices.clear();
}

void Cone::update()
{
	rotator += 0.01f;
}

void Cone::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	_mvStack->push(_mvStack->top());
	_mvStack->top() = glm::translate(_mvStack->top(), pos);
	_mvStack->top() = glm::rotate(_mvStack->top(), float(rotator), glm::vec3(0.0f, 1.0f, 0.0f));
	_mvStack->top() = glm::scale(_mvStack->top(), glm::vec3(1.5f, 1.5f, 1.5f));
	rt3d::setUniformMatrix4fv(shader, "projection", glm::value_ptr(projection));
	rt3d::setUniformMatrix4fv(shader, "modelview", glm::value_ptr(_mvStack->top()));
	rt3d::setMaterial(shader, material0);
	rt3d::drawIndexedMesh(meshObjects[0], meshIndexCount[0], GL_TRIANGLES);
	_mvStack->pop();
}