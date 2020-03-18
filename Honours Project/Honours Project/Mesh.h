#pragma once
#include "rt3d.h"
#include "rt3dObjLoader.h"
#include <string.h>
#include <iostream>
#include <stack>
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "Transform.h"

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

	rt3d::materialStruct material0 = {
	{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
	{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
	{0.0f, 0.1f, 0.0f, 1.0f}, // specular
					   2.0f  // shininess
	};

public:
	void loadMesh(string filename);
	void drawMesh(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection, GLuint texture, Transform* modelMatrix);
	vector<GLfloat>* getVerts();
};