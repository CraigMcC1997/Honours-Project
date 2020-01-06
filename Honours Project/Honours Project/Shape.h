#pragma once
#include "Entity.h"

class Shape : Entity
{
protected:
	GLuint texture;
	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	GLuint meshIndexCount[1];
	GLuint meshObjects[1];
	float rotator = 0.0f;

	rt3d::lightStruct light0 = {
							{0.4f, 0.4f, 0.4f, 1.0f}, // ambient
							{1.0f, 1.0f, 1.0f, 1.0f}, // diffuse
							{1.0f, 1.0f, 1.0f, 1.0f}, // specular
							{-5.0f, 2.0f, 2.0f, 1.0f}  // position
	};

	rt3d::materialStruct material0 = {
								{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
								{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
								{0.0f, 0.1f, 0.0f, 1.0f}, // specular
													2.0f  // shininess
	};

public:
};