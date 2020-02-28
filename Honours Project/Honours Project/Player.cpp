#include "Player.h"

void Player::init()
{
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);

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
	_mvStack->top() = glm::lookAt(camera::getEye(), 
		glm::vec3(camera::getEye() + camera::getFront()), camera::getUp());
}
