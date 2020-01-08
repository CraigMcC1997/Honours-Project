#pragma once
#include "Entity.h"
#include "Camera.h"

class Player : public Entity
{
private:

public:
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection, GLuint texture, glm::vec3 pos);
};

