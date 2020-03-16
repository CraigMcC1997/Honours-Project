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
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	cameraUpdate(keys);
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

	playerPosition = camera::getEye();
}

void Player::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	//camera set up
	_mvStack->push(glm::lookAt(camera::getEye(), 
		glm::vec3(camera::getEye() + camera::getFront()), camera::getUp()));
}
