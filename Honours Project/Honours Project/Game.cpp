#include "Game.h"

void Game::init()
{
	shaderProgram = rt3d::initShaders("../Resources/Shaders/textured.vert", "../Resources/Shaders/textured.frag");	//initialising the chosen shaders

	textures[0] = loadTexture::loadTextures("../Resources/Textures/fabric.bmp");

	//model loading
	rt3d::loadObj("../Resources/3D_Objects/cube.obj", verts, norms, tex_coords, indices);
	meshIndexCount[0] = indices.size();
	meshObjects[0] = rt3d::createMesh(verts.size() / 3, verts.data(), nullptr, norms.data(), tex_coords.data(),
		meshIndexCount[0], indices.data());
	verts.clear(), norms.clear(), tex_coords.clear(), indices.clear();

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

	if (keys[SDL_SCANCODE_Q]) {
		setPosition(Move::moveY(position, Move::getRotation(), 0.2));
	}

	if (keys[SDL_SCANCODE_E]) {
		setPosition(Move::moveY(position, Move::getRotation(), -0.2));
	}

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

	if (SDL_GetMouseState(&x, &y))
	{
		cout << x << endl;
		cout << y << endl;
	}

	//camera::setAt(glm::vec3());
	camera::setEye(position);
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
	mvStack.top() = glm::lookAt(camera::getEye(), glm::vec3(camera::getAt().x, rotateValueY, rotateValueZ), camera::getUp());

	//draw here
	glUseProgram(shaderProgram);

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(0,0,0));
	//mvStack.top() = glm::rotate(mvStack.top(), float(90.0f * DEG_TO_RADIAN), glm::vec3(0.0f, 1.0f, 0.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(1.5f, 1.5f, 1.5f));
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	rt3d::setMaterial(shaderProgram, material0);
	rt3d::drawIndexedMesh(meshObjects[0], meshIndexCount[0], GL_TRIANGLES);
	mvStack.pop();

	mvStack.pop();
	SDL_GL_SwapWindow(window); // swap buffers
}


