#include "Player.h"

void Player::init()
{
}

void Player::setPosition(glm::vec3 newPos)
{
	position = newPos;
}

glm::vec3 Player::getPosition()
{
	return position;
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	//using WASD to control the players movement around the 3D world
	if (keys[SDL_SCANCODE_A]) {
		setPosition(Move::moveZ(position, Move::getRotation(), -0.2));
	}

	if (keys[SDL_SCANCODE_D]) {
		setPosition(Move::moveZ(position, Move::getRotation(), 0.2));
	}

	if (keys[SDL_SCANCODE_W]) {
		setPosition(Move::moveX(position, Move::getRotation(), 0.2));
	}

	if (keys[SDL_SCANCODE_S]) {
		setPosition(Move::moveX(position, Move::getRotation(), -0.2));
	}

	//using QE for moving the player up and down
	if (keys[SDL_SCANCODE_Q]) {
		setPosition(Move::moveY(position, Move::getRotation(), 0.2));
	}

	if (keys[SDL_SCANCODE_E]) {
		setPosition(Move::moveY(position, Move::getRotation(), -0.2));
	}

	//using LEFT, RIGHT, UP and DOWN to control the players camera movement
	if (keys[SDL_SCANCODE_LEFT]) {
		rotateValueZ += 0.1;
		cout << rotateValueZ << endl;
	}

	if (keys[SDL_SCANCODE_RIGHT]) {
		rotateValueZ -= 0.1;
		cout << rotateValueZ << endl;
	}
	if (keys[SDL_SCANCODE_UP]) {
		rotateValueY += 0.1;
		cout << rotateValueY << endl;
	}

	if (keys[SDL_SCANCODE_DOWN]) {
		rotateValueY -= 0.1;
		cout << rotateValueY << endl;
	}

	//beginning attempt at finding the mouse position and using this to control
	//the camera
	if (SDL_GetMouseState(&x, &y))
	{
		cout << x << endl;
		cout << y << endl;
	}

	//camera follows players position
	camera::setEye(position);
}

void Player::draw(GLuint shader, std::stack<glm::mat4>* _mvStack, glm::mat4 projection, GLuint texture, glm::vec3 pos)
{
	//camera set up
	camera::setAt(Move::moveX(camera::getEye(), Move::getRotation(), 1.0f));
	_mvStack->top() = glm::lookAt(camera::getEye(),
		glm::vec3(camera::getAt().x, camera::getAt().y, camera::getAt().z), camera::getUp());
}
