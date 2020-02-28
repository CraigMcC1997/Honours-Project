#pragma once
#include "Entity.h"
#include "Camera.h"

//#include "Cube.h"
//#include "Cone.h"
//#include "Sphere.h"
//#include "cylinder.h"

class Player : public Entity
{
private:
	int playerShape = 0;
	glm::vec3 playerPosition;
	glm::vec3 scale = glm::vec3(1.5f, 1.5f, 1.5f);

public:
	void init();
	void update();
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack,
		glm::mat4 projection, GLuint texture, glm::vec3 pos);
};

