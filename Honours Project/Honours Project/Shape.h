#pragma once
#include "Entity.h"
#include "Mesh.h"
#include "Transform.h"
#include "Collidable.h"

class Shape : Entity
{
protected:
	Mesh* mesh = new Mesh();
	Transform* transform = new Transform();
	Collidable* collidable = new Collidable();

	GLuint texture;
	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	GLuint meshIndexCount;
	GLuint meshObjects;
	float rotator = 0.0f;

	rt3d::materialStruct material0 = {
	{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
	{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
	{0.0f, 0.1f, 0.0f, 1.0f}, // specular
					   2.0f  // shininess
	};

	glm::vec3 scale = glm::vec3(1.5f, 1.5f, 1.5f);

	vector<glm::vec3> cHull;

public:
	virtual glm::vec3 getPosition() = 0;
	virtual vector<glm::vec3> getHull() = 0;
	virtual void setHull(vector<glm::vec3>) = 0;
	virtual void update(float dt) = 0;
	virtual void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection) = 0;
	virtual void changeTexture(GLuint newTexture) = 0;
};