#pragma once
#include "Entity.h"
#include "Move.h"
#include "Camera.h"

class Player : public Entity
{
private:
	glm::vec3 position = glm::vec3(-10, 0, 0); //Player position

	//rotation
	GLfloat rotateValueZ = 0.0f;
	GLfloat rotateValueY = 0.0f;
	float x_prev = 0.0f;
	int x = 0.0f, y = 0.0f;
	//float f_curr_x;
	//float f_dx;

public:
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection, GLuint texture, glm::vec3 pos);

	void setPosition(glm::vec3 newPos);
	glm::vec3 getPosition();
};

