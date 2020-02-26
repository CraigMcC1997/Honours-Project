//################################################################
// A 3D cube for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cube : public Shape
{
private:
	float distance = 20;
	bool left = true;
public:
	Cube(glm::vec3 cubeScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(cubeScale);
		move(pos);
		this->texture = texture;
	}

	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection);

	void setHull(vector<glm::vec3>);
	void move(glm::vec3 translation);
	
	glm::vec3 getPosition();
	vector<glm::vec3> getHull();

	void moveCube();
	void changeTexture(GLuint);
};

