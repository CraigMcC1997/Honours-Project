#include "Game.h"

void Game::init()
{
	//shaders
	shaderProgram = rt3d::initShaders("../Resources/Shaders/textured.vert", "../Resources/Shaders/textured.frag");

	//textures
	textures[0] = loadTexture::loadTextures("../Resources/Textures/fabric.bmp");
	textures[1] = loadTexture::loadTextures("../Resources/Textures/dirt.bmp");
	textures[2] = loadTexture::loadTextures("../Resources/Textures/studdedmetal.bmp");

	box->init();
	box2->init();
	circle->init();
	cone->init();
	cylinder->init();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Game::setPosition(glm::vec3 newPos)
{
	position = newPos;
}

void Game::update(SDL_Event sdlEvent)
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
	
	box->update();
	box2->update();
	circle->update();
	cone->update();
	cylinder->update();
}

void Game::draw(SDL_Window* window)
{
	// clear the screen
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set base position for scene
	glm::mat4 modelview(1.0); 
	glm::mat4 projection(1.0);
	projection = glm::perspective(float(60.0f * DEG_TO_RADIAN), 800.0f / 600.0f, 1.0f, 150.0f);
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));
	stack<glm::mat4> mvStack;
	mvStack.push(modelview);

	//global lighting
	glm::vec4 tmp = mvStack.top() *lightPos;
	rt3d::setLightPos(shaderProgram, glm::value_ptr(tmp));

	//camera set up
	camera::setAt(Move::moveX(camera::getEye(), Move::getRotation(), 1.0f));
	mvStack.top() = glm::lookAt(camera::getEye(), 
		glm::vec3(camera::getAt().x, camera::getAt().y, camera::getAt().z), camera::getUp());

	//draw here
	glUseProgram(shaderProgram);
	box->draw(shaderProgram, &mvStack, projection, textures[0], glm::vec3(0,0,0));
	box2->draw(shaderProgram, &mvStack, projection, textures[1], glm::vec3(0, 0, 10));
	circle->draw(shaderProgram, &mvStack, projection, textures[2], glm::vec3(0, 0, 20));
	cone->draw(shaderProgram, &mvStack, projection, textures[2], glm::vec3(0, 0, 30));
	cylinder->draw(shaderProgram, &mvStack, projection, textures[1], glm::vec3(0, 0, 40));

	mvStack.pop();
	SDL_GL_SwapWindow(window); // swap buffers
}


