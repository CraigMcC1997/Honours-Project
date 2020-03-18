#include "Player.h"

void Player::init()
{
	//textures
	texture = loadTextures::loadTexture("../Resources/Textures/player.bmp");

	box = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 5.0f), texture);
	box->init();

	cone = new Cone(glm::vec3(1.0f, 1.0f, 1.0f), conePosition, texture);
	cone->init();

	cylinder = new Cylinder(glm::vec3(1.0f, 1.0f, 1.0f), cylinderPosition, texture);
	cylinder->init();

	ball = new Sphere(glm::vec3(1.0f, 1.0f, 1.0f), ballPosition, texture);
	ball->init();

	playerPosition = box->getPosition();
}

void Player::move(glm::vec3 dir)
{
	switch (playerShape)
	{
	case 1:
		box->move(dir);
		break;
	case 2:
		ball->move(dir);
		break;
	case 3:
		cone->move(dir);
		break;
	case 4:
		cylinder->move(dir);
		break;
	}
}

void Player::changeShape(const Uint8* keys)
{
	//changing player shape
	if (keys[SDL_SCANCODE_1])
	{
		playerShape = 1;	//box
		box->setPosition(playerPosition);
		ball->setPosition(ballPosition);
		cone->setPosition(conePosition);
		cylinder->setPosition(cylinderPosition);
	}

	if (keys[SDL_SCANCODE_2])
	{
		playerShape = 2;	//ball
		ball->setPosition(playerPosition);
		box->setPosition(cubePosition);
		cone->setPosition(conePosition);
		cylinder->setPosition(cylinderPosition);
	}

	if (keys[SDL_SCANCODE_3])
	{
		playerShape = 3;	//cone
		cone->setPosition(playerPosition);
		ball->setPosition(ballPosition);
		box->setPosition(cubePosition);
		cylinder->setPosition(cylinderPosition);
	}

	if (keys[SDL_SCANCODE_4])
	{
		playerShape = 4;	//cylinder
		cylinder->setPosition(playerPosition);
		cone->setPosition(conePosition);
		ball->setPosition(ballPosition);
		box->setPosition(cubePosition);
	}
}

void Player::storePosition()
{
	switch (playerShape)
	{
	case 1:
		playerPosition = box->getPosition();
		break;
	case 2:
		playerPosition = ball->getPosition();
		break;
	case 3:
		playerPosition = cone->getPosition();
		break;
	case 4:
		playerPosition = cylinder->getPosition();
		break;
	}
}

Cube* Player::getCube()
{
	return box;
}

Sphere* Player::getBall()
{
	return ball;
}

Cone* Player::getCone()
{
	return cone;
}

Cylinder* Player::getCylinder()
{
	return cylinder;
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	cameraUpdate(keys);
	changeShape(keys);
	storePosition();

	if (keys[SDL_SCANCODE_RIGHT])
		move(glm::vec3(1, 0, 0));
	if (keys[SDL_SCANCODE_LEFT])
		move(glm::vec3(-1, 0, 0));
	if (keys[SDL_SCANCODE_UP])
		move(glm::vec3(0, 1, 0));
	if (keys[SDL_SCANCODE_DOWN])
		move(glm::vec3(0, -1, 0));
	if (keys[SDL_SCANCODE_E])
		move(glm::vec3(0, 0, 1));
	if (keys[SDL_SCANCODE_Q])
		move(glm::vec3(0, 0, -1));

	box->changeTexture(texture);
	ball->changeTexture(texture);
	cone->changeTexture(texture);
	cylinder->changeTexture(texture);
}

//THIS CODE WAS TAKEN FROM 
//https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/7.2.camera_keyboard_dt/camera_keyboard_dt.cpp
//All camera code based around the https://learnopengl.com/Getting-started/Camera tutorial
void Player::cameraUpdate(const Uint8* keys)
{
	//moving the camera
	float cameraSpeed = 0.5;
	if (keys[SDL_SCANCODE_W])
		camera::setEye(camera::getEye() += cameraSpeed * camera::getFront());
	if (keys[SDL_SCANCODE_S])
		camera::setEye(camera::getEye() -= cameraSpeed * camera::getFront());
	if (keys[SDL_SCANCODE_A])
		camera::setEye(camera::getEye() -= glm::normalize(glm::cross(camera::getFront(), camera::getUp())) * cameraSpeed);
	if (keys[SDL_SCANCODE_D])
		camera::setEye(camera::getEye() += glm::normalize(glm::cross(camera::getFront(), camera::getUp())) * cameraSpeed);

	camPosition = camera::getEye();
}

void Player::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, 
	glm::mat4 projection)
{
	//camera set up
	_mvStack->push(glm::lookAt(camera::getEye(), 
		glm::vec3(camera::getEye() + camera::getFront()), camera::getUp()));

	switch (playerShape)
	{
	case 1:
		box->draw(shader, _mvStack, projection);
		break;
	case 2:
		ball->draw(shader, _mvStack, projection);
		break;
	case 3:
		cone->draw(shader, _mvStack, projection);
		break;
	case 4:
		cylinder->draw(shader, _mvStack, projection);
		break;
	}
}
