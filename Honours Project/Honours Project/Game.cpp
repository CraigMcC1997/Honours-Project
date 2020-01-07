#include "Game.h"

void Game::init()
{
	//shaders
	shaderProgram = rt3d::initShaders("../Resources/Shaders/textured.vert", "../Resources/Shaders/textured.frag");

	//textures
	textures[0] = loadTexture::loadTextures("../Resources/Textures/fabric.bmp");
	textures[1] = loadTexture::loadTextures("../Resources/Textures/dirt.bmp");
	textures[2] = loadTexture::loadTextures("../Resources/Textures/studdedmetal.bmp");

	player->init();
	box->init();
	box2->init();
	circle->init();
	cone->init();
	cylinder->init();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Game::update(SDL_Event sdlEvent)
{
	player->update();
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

	player->draw(shaderProgram, &mvStack, projection, textures[0], player->getPosition());

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


