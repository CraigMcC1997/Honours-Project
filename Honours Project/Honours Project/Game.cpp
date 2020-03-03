#include "Game.h"

void Game::init() {
	//shaders
	shaderProgram = rt3d::initShaders("../Resources/Shaders/textured.vert", "../Resources/Shaders/textured.frag");

	//textures
	textures[0] = loadTextures::loadTexture("../Resources/Textures/nocollision.bmp");
	textures[1] = loadTextures::loadTexture("../Resources/Textures/colliding.bmp");
	textures[2] = loadTextures::loadTexture("../Resources/Textures/red.bmp");
	textures[3] = loadTextures::loadTexture("../Resources/Textures/blue.bmp");
	
	//adding sound files to the array to be played later in code
	samples[0] = Sound::loadSample("../Resources/SoundFiles/Click.wav", BASS_SAMPLE_OVER_POS);	

	//adding a grid for optimisation
	grid = new Grid(1200, 800, 50);

	//Shapes		//scale							//position			//texture
	ball = new Sphere(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(20, 0, 0), textures[2]);
	cone = new Cone(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(5, 0, 0), textures[2]);
	cylinder = new Cylinder(glm::vec3(2.5f, 2.5f, 2.5f), glm::vec3(40, 0, 0), textures[2]);

	//randomly placing the boxes
	srand(time(NULL));
	/*for (auto i = 0; i < 10; i++) {
		glm::vec3 position = glm::vec3(rand() % 20, rand() % 20, rand() % 20);
		glm::vec3 velocity = glm::vec3(rand() % 5, rand() % 5, rand() % 5);
		velocity.x /= 100;
		velocity.y /= 100;
		velocity.z /= 100;

		boxes[i] = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), 
			position, textures[0]);

		boxes[i]->init();
		boxes[i]->updateVelocity(velocity);
		gameEntities.push_back(boxes[i]);
		grid->registerObj(boxes[i]);
	}*/

	player->init();

	box = new Cube(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 4.0f, 0.0f), textures[0]);
	box->init();
	gameEntities.push_back(box);
	grid->registerObj(box);
	
	box2 = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(30.0f, 0.0f, 0.0f), textures[0]);
	box2->init();
	gameEntities.push_back(box2);
	grid->registerObj(box2);

	//box3 = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(10.0f, 0.0f, 0.0f), textures[0]);
	//box3->init();
	//gameEntities.push_back(box3);
	//grid->registerObj(box3);

	ball->init();
	gameEntities.push_back(ball);
	grid->registerObj(ball);

	cone->init();
	gameEntities.push_back(cone);
	grid->registerObj(cone);

	cylinder->init();
	gameEntities.push_back(cylinder);
	grid->registerObj(cylinder);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//Get mouse data
void Game::mouse_callback(double xpos, double ypos)
{
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.2f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

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

void Game::checkCollisions()
{
	//for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end() - 1; ++it)
	//{
	//	//dynamic cast first object here //
	//	Cube* cube1 = dynamic_cast<Cube*> (*it);
	//	if (cube1 != nullptr)
	//	{
	//		vector<Shape*> objs = gameEntities; //grid->getNeighbours(cube1);

	//		for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
	//		{
	//			if (*it != *it1)
	//			{
	//				//dynamic cast second object here //
	//				Cube* cube2 = dynamic_cast<Cube*> (*it1);
	//				if (cube2 != nullptr)
	//				{
						if (gjk->performDetection(box->getHull(), cone->getHull()))
						{
							//Collision response
							Sound::playSample(samples[0]);
							box->changeTexture(textures[1]);
							cone->changeTexture(textures[3]);
						}
						else
						{
							//No collision response
							box->changeTexture(textures[0]);
							cone->changeTexture(textures[2]);
						}
					/*}
				}
			}
		}
	}*/
}

void Game::moveObjects(float dt)
{
	//for (vector<Shape*>::iterator it = gameEntities.begin(); 
	//	it < gameEntities.end(); it++)
	//{
	//	if ((*it)->getPosition().x > 10 ||
	//		(*it)->getPosition().y > 10 ||
	//		(*it)->getPosition().z > 10)
	//		(*it)->updateVelocity(-(*it)->getVelocity());
	//	else
	//	(*it)->move(dt);		
	//}
}

void Game::update(SDL_Event sdlEvent/*, float dt*/)
{	
	int mouseX, mouseY;
	if (!SDL_GetGlobalMouseState(&mouseX, &mouseY))	//mouse input
		mouse_callback(mouseX, mouseY);

	const Uint8* keys = SDL_GetKeyboardState(NULL); //keyboard input
	
	//testing code for moving cube
	if (keys[SDL_SCANCODE_RIGHT])
		box->move(0.1, glm::vec3(1, 0, 0));

	if (keys[SDL_SCANCODE_LEFT])
		box->move(0.1, glm::vec3(-1, 0, 0));

	if (keys[SDL_SCANCODE_UP])
		box->move(0.1, glm::vec3(0, 1, 0));

	if (keys[SDL_SCANCODE_DOWN])
		box->move(0.1, glm::vec3(0, -1, 0));

	if (keys[SDL_SCANCODE_Q])
		box->move(0.1, glm::vec3(0, 0, 1));

	if (keys[SDL_SCANCODE_E])
		box->move(0.1, glm::vec3(0, 0, -1));

	checkCollisions();

	//moveObjects(dt);
	player->update();

	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end(); it++)
		(*it)->update(/*dt*/);
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

	//draw here
	glUseProgram(shaderProgram);
	player->draw(shaderProgram, &mvStack, projection, NULL, camera::getEye());

	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end(); it++)
		(*it)->draw(shaderProgram, &mvStack, projection);

	mvStack.pop();
	SDL_GL_SwapWindow(window); // swap buffers
}