#pragma once
#include "rt3d.h"
#include "rt3dObjLoader.h"
#include <string.h>
#include <iostream>
#include <stack>
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Mesh
{
private:
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

	vector<GLfloat> storedVerts;

public:
	void loadMesh(string filename);
	void drawMesh(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection, GLuint texture, glm::vec3 pos);
};