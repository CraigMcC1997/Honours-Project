#include "Player.h"

void Player::init()
{
}

void Player::choseShape(int option)
{
	//playerShape = option;

	//switch (option)
	//{
	//case 1:
	//	//cube
	//	cube->init();
	//	break;
	//case 2:
	//	//cone
	//	cone->init();
	//	break;
	//case 3:
	//	//sphere
	//	sphere->init();
	//	break;
	//case 4:
	//	//cylinder
	//	cylinder->init();
	//	break;
	//}
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

	//player choosing object
	if (keys[SDL_SCANCODE_1])
		choseShape(1);
	if (keys[SDL_SCANCODE_2])
		choseShape(2);
	if (keys[SDL_SCANCODE_3])
		choseShape(3);
	if (keys[SDL_SCANCODE_4])
		choseShape(4);

	playerPosition = camera::getEye();
}

void Player::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	//camera set up
	_mvStack->top() = glm::lookAt(camera::getEye(), glm::vec3(camera::getEye() + camera::getFront()), camera::getUp());

	////draw players chosen object here
	//switch (playerShape)
	//{
	//case 1:
	//{ cube->draw(shader, _mvStack, projection, texture, playerPosition); } break;
	//case 2:
	//{ cone->draw(shader, _mvStack, projection, texture, playerPosition); } break;
	//case 3:
	//{ sphere->draw(shader, _mvStack, projection, texture, playerPosition); } break;
	//case 4:
	//{ cylinder->draw(shader, _mvStack, projection, texture, playerPosition); } break;
	//}
}
