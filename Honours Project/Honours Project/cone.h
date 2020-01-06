//################################################################
// A 3D cone for testing purposes
//################################################################

#pragma once
#include "Entity.h"

using namespace std;

class Cone : Entity
{
private:
	GLuint texture;

	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	GLuint meshIndexCount[1];
	GLuint meshObjects[1];
	float rotator = 0.0f;

public:
	Cone() {};
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos);
};

