#include "Game.h"

void Game::init()
{
	//shaders
	shaderProgram = rt3d::initShaders("../Resources/Shaders/textured.vert", "../Resources/Shaders/textured.frag");

	//textures
	textures[0] = loadTextures::loadTexture("../Resources/Textures/fabric.bmp");
	textures[1] = loadTextures::loadTexture("../Resources/Textures/dirt.bmp");
	textures[2] = loadTextures::loadTexture("../Resources/Textures/studdedmetal.bmp");

	player->init();
	box1->init();
	box2->init();
	circle->init();
	cone->init();
	cylinder->init();

	bool test = gjk->performDetection(/*box1->getHull(), box2->getHull()*/);
	cout << test << endl;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Game::mouse_callback(double xpos, double ypos)
{
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.2f; // change this value to your liking
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	camera::setFront(glm::normalize(front));
}

void Game::update(SDL_Event sdlEvent)
{	
	if (!SDL_GetGlobalMouseState(&x, &y))
		mouse_callback(x, y);
		
	player->update();
	box1->update();
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
	
	projection = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 1.0f, 150.0f);
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));
	stack<glm::mat4> mvStack;
	mvStack.push(modelview);

	//global lighting
	glm::vec4 tmp = mvStack.top() *lightPos;
	rt3d::setLightPos(shaderProgram, glm::value_ptr(tmp));

	player->draw(shaderProgram, &mvStack, projection, NULL, camera::getEye());

	//draw here
	glUseProgram(shaderProgram);
	box1->draw(shaderProgram, &mvStack, projection, textures[0], glm::vec3(0, 0, 0));
	box2->draw(shaderProgram, &mvStack, projection, textures[1], glm::vec3(10, 0, 0));
	circle->draw(shaderProgram, &mvStack, projection, textures[2], glm::vec3(20, 0, 0));
	cone->draw(shaderProgram, &mvStack, projection, textures[2], glm::vec3(30, 0, 0));
	cylinder->draw(shaderProgram, &mvStack, projection, textures[1], glm::vec3(40, 0, 0));


	mvStack.pop();
	SDL_GL_SwapWindow(window); // swap buffers
}