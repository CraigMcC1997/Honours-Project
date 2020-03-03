//################################################################
// A 3D cone for testing purposes
//################################################################

#pragma once
#include "Shape.h"

class Cone : public Shape
{
private:
	void privMove(glm::vec3 translation);
	void VelocityVerletSolver(float dt);

	vector<glm::vec3> coneVerts =
	{	{0.000000, - 1.000000, - 1.000000},
		{0.195090, - 1.000000, - 0.980785},
		{0.382683, - 1.000000, - 0.923880},
		{0.555570, - 1.000000, - 0.831470},
		{0.707107, - 1.000000, - 0.707107},
		{0.831470, - 1.000000, - 0.555570},
		{0.923880, - 1.000000, - 0.382683},
		{0.980785, - 1.000000, - 0.195090},
		{1.000000, - 1.000000, - 0.000000},
		{0.980785, - 1.000000, 0.195090},
		{0.923880, - 1.000000, 0.382683},
		{0.831470, - 1.000000, 0.555570},
		{0.707107, - 1.000000, 0.707107},
		{0.555570, - 1.000000, 0.831470},
		{0.382683, - 1.000000, 0.923880},
		{0.195090, - 1.000000, 0.980785},
		{-0.000000, - 1.000000, 1.000000},
		{-0.195091, - 1.000000, 0.980785},
		{-0.382684, - 1.000000, 0.923879},
		{-0.555571, - 1.000000, 0.831469},
		{-0.707107, - 1.000000, 0.707106},
		{-0.831470, - 1.000000, 0.555570},
		{-0.923880, - 1.000000, 0.382683},
		{0.000000, 1.000000, 0.000000},
		{-0.980785, - 1.000000, 0.195089},
		{-1.000000, - 1.000000, - 0.000001},
		{-0.980785, - 1.000000, - 0.195091},
		{-0.923879, - 1.000000, - 0.382684},
		{-0.831469, - 1.000000,- 0.555571},
		{-0.707106, - 1.000000, - 0.707108},
		{-0.555569, - 1.000000, - 0.831470},
		{-0.382682, - 1.000000, - 0.923880},
		{-0.195089, - 1.000000, - 0.980786},
	};

public:
	Cone(glm::vec3 coneScale, glm::vec3 pos, GLuint texture) {
		transform->Scale(coneScale);
		privMove(pos);
		this->texture = texture;
		setHull(coneVerts);
	}
	void init();
	void update(/*float dt*/);
	void draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
		glm::mat4 projection);

	glm::vec3 getPosition();
	vector<glm::vec3> getHull();
	void setHull(vector<glm::vec3>);
	
	void changeTexture(GLuint);
	void move(float dt, glm::vec3 dir);
	void updateVelocity(glm::vec3);
	glm::vec3 getVelocity();
};

