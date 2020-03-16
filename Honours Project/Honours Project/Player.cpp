#include "Player.h"

void Player::init()
{
	//textures
	textures[0] = loadTextures::loadTexture("../Resources/Textures/nocollision.bmp");
	textures[1] = loadTextures::loadTexture("../Resources/Textures/colliding.bmp");
	textures[2] = loadTextures::loadTexture("../Resources/Textures/red.bmp");
	textures[3] = loadTextures::loadTexture("../Resources/Textures/blue.bmp");

	box = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), textures[0]);
	box->init();

	cone = new Cone(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), textures[0]);
	cone->init();

	cylinder = new Cylinder(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), textures[0]);
	cylinder->init();

	ball = new Sphere(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), textures[0]);
	ball->init();

	playerPosition = box->getPosition();
}

void Player::move(float dt, glm::vec3 dir)
{
	
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	cameraUpdate(keys);

	//changing player shape
	if (keys[SDL_SCANCODE_1])
	{
		playerShape = 1;	//box
		box->setPosition(playerPosition);
	}
		
	if (keys[SDL_SCANCODE_2])
	{
		playerShape = 2;	//ball
		ball->setPosition(playerPosition);
	}
		
	if (keys[SDL_SCANCODE_3])
	{
		playerShape = 3;	//cone
		//cone->setPosition(playerPosition);
	}
		
	if (keys[SDL_SCANCODE_4])
	{
		playerShape = 4;	//cylinder
	}

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

	if (keys[SDL_SCANCODE_RIGHT])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(1, 0, 0));
			break;
		case 2:
			ball->move(0.1, glm::vec3(1, 0, 0));
			break;
		case 3:
			cone->move(0.1, glm::vec3(1, 0, 0));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(1, 0, 0));
			break;
		}
	}

	if (keys[SDL_SCANCODE_LEFT])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(-1, 0, 0));
			break;
		case 2:
			ball->move(0.1, glm::vec3(-1, 0, 0));
			break;
		case 3:
			cone->move(0.1, glm::vec3(-1, 0, 0));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(-1, 0, 0));
			break;
		}
	}

	if (keys[SDL_SCANCODE_UP])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(0, 1, 0));
			break;
		case 2:
			ball->move(0.1, glm::vec3(0, 1, 0));
			break;
		case 3:
			cone->move(0.1, glm::vec3(0, 1, 0));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(0, 1, 0));
			break;
		}
	}

	if (keys[SDL_SCANCODE_DOWN])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(0, -1, 0));
			break;
		case 2:
			ball->move(0.1, glm::vec3(0, -1, 0));
			break;
		case 3:
			cone->move(0.1, glm::vec3(0, -1, 0));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(0, -1, 0));
			break;
		}
	}

	if (keys[SDL_SCANCODE_Q])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(0, 0, 1));
			break;
		case 2:
			ball->move(0.1, glm::vec3(0, 0, 1));
			break;
		case 3:
			cone->move(0.1, glm::vec3(0, 0, 1));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(0, 0, 1));
			break;
		}
	}

	if (keys[SDL_SCANCODE_E])
	{
		switch (playerShape)
		{
		case 1:
			box->move(0.1, glm::vec3(0, 0, -1));
			break;
		case 2:
			ball->move(0.1, glm::vec3(0, 0, -1));
			break;
		case 3:
			cone->move(0.1, glm::vec3(0, 0, -1));
			break;
		case 4:
			cylinder->move(0.1, glm::vec3(0, 0, -1));
			break;
		}
	}

	
	box->update();
}

void Player::cameraUpdate(const Uint8* keys)
{
	//moving the camera
	float cameraSpeed = 1.0;
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
