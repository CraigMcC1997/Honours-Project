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
	grid = new Grid(1200, 800, 50, 100);

	//randomly placing the boxes
	srand(time(NULL));
	for (auto i = 0; i < 10; i++) {
		glm::vec3 position = glm::vec3(rand() % 60, rand() % 20, rand() % 30);
		
		boxes[i] = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), 
			position, textures[0]);

		boxes[i]->init();
		gameEntities.push_back(boxes[i]);
		grid->registerObj(boxes[i]);
	}

	for (auto i = 0; i < 10; i++) {
		glm::vec3 position = glm::vec3(rand() % 60, rand() % 20, rand() % 30);
		cone[i] = new Cone(glm::vec3(1.0f, 1.0f, 1.0f),
			position, textures[2]);
		cone[i]->init();
		gameEntities.push_back(cone[i]);
		grid->registerObj(cone[i]);
	}

	for (auto i = 0; i < 10; i++) {
		glm::vec3 position = glm::vec3(rand() % 60, rand() % 20, rand() % 30);
		
		ball[i] = new Sphere(glm::vec3(2.0f, 2.0f, 2.0f), 
			position, textures[2]);
		ball[i]->init();
		gameEntities.push_back(ball[i]);
		grid->registerObj(ball[i]);
	}

	for (auto i = 0; i < 10; i++) {
		glm::vec3 position = glm::vec3(rand() % 60, rand() % 20, rand() % 30);

		cylinder[i] = new Cylinder(glm::vec3(2.5f, 2.5f, 2.5f),
			position, textures[2]);
		cylinder[i]->init();
		gameEntities.push_back(cylinder[i]);
		grid->registerObj(cylinder[i]);
	}

	/*cone[0] = new Cone(glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(7.0f, 0.0f, 0.0f), textures[2]);
	cone[0]->init();
	gameEntities.push_back(cone[0]);
	grid->registerObj(cone[0]);*/

	player->init();

	box = new Cube(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), textures[0]);
	box->init();
	gameEntities.push_back(box);
	grid->registerObj(box);

	ball[0]->init();
	gameEntities.push_back(ball[0]);
	grid->registerObj(ball[0]);
	
	ball[1]->init();
	gameEntities.push_back(ball[1]);
	grid->registerObj(ball[1]);

	cylinder[0]->init();
	gameEntities.push_back(cylinder[0]);
	grid->registerObj(cylinder[0]);

	cylinder[1]->init();
	gameEntities.push_back(cylinder[1]);
	grid->registerObj(cylinder[1]);
	
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
	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end() - 1; ++it)
	{
		//dynamic cast first object here //
		Cube* cube1 = dynamic_cast<Cube*> (*it);
		if (cube1 != nullptr)
		{
			vector<Shape*> objs = grid->getNeighbours(cube1);//gameEntities;

			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1)
				{
					//dynamic cast second object here //
					Cube* cube2 = dynamic_cast<Cube*> (*it1);
					if (cube2 != nullptr)
					{
						if (gjk->performDetection(*&cube1->getHull(), *&cube2->getHull()))
						{
							//Collision response
							cube2->changeTexture(textures[1]);
						}
					}

					//dynamic cast third object here //
					Cone* cone = dynamic_cast<Cone*> (*it1);
					if (cone != nullptr)
					{
						if (gjk->performDetection(*&cone->getHull(), *&cube1->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							cube1->changeTexture(textures[1]);
							cone->changeTexture(textures[3]);
						}
					}

					Sphere* sphere1 = dynamic_cast<Sphere*>(*it1);
					if (sphere1 != nullptr)
					{
						if (gjk->performDetection(*&sphere1->getHull(), *&cube1->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							sphere1->changeTexture(textures[3]);
							cube1->changeTexture(textures[1]);
						}
					}

					Cylinder* cylinder1 = dynamic_cast<Cylinder*>(*it1);
					if (cylinder1 != nullptr)
					{
						if (gjk->performDetection(*&cylinder1->getHull(), *&cube1->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							cylinder1->changeTexture(textures[3]);
							cube1->changeTexture(textures[1]);
						}
					}
				}
			}
		}
	}




	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end() - 1; ++it)
	{
		//dynamic cast first object here //
		Cone* cone1 = dynamic_cast<Cone*> (*it);
		if (cone1 != nullptr)
		{
			vector<Shape*> objs = grid->getNeighbours(cone1);//gameEntities;

			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1)
				{
					//dynamic cast second object here //
					Cone* cone2 = dynamic_cast<Cone*> (*it1);
					if (cone2 != nullptr)
					{
						if (gjk->performDetection(*&cone1->getHull(), *&cone2->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							//cube1->changeTexture(textures[1]);
							cone1->changeTexture(textures[3]);
							cone2->changeTexture(textures[3]);
						}
					}
					Sphere* sphere1 = dynamic_cast<Sphere*>(*it1);
					if (sphere1 != nullptr)
					{
						if (gjk->performDetection(*&sphere1->getHull(), *&cone1->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							sphere1->changeTexture(textures[3]);
							cone1->changeTexture(textures[3]);
						}
					}
					Cylinder* cylinder1 = dynamic_cast<Cylinder*>(*it1);
					if (cylinder1 != nullptr)
					{
						if (gjk->performDetection(*&cylinder1->getHull(), *&cone1->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							cylinder1->changeTexture(textures[3]);
							cone1->changeTexture(textures[3]);
						}
					}
				}
			}
		}
	}


	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end() - 1; ++it)
	{
		//dynamic cast first object here //
		Sphere* sphere = dynamic_cast<Sphere*> (*it);
		if (sphere != nullptr)
		{
			vector<Shape*> objs = grid->getNeighbours(sphere);//gameEntities;

			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1)
				{
					//dynamic cast second object here //
					Sphere* sphere2 = dynamic_cast<Sphere*> (*it1);
					if (sphere2 != nullptr)
					{
						if (gjk->performDetection(*&sphere->getHull(), *&sphere2->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							//cube1->changeTexture(textures[1]);
							sphere->changeTexture(textures[3]);
							sphere2->changeTexture(textures[3]);
						}
					}

					Cylinder* cylinder = dynamic_cast<Cylinder*> (*it1);
					if (cylinder != nullptr)
					{
						if (gjk->performDetection(*&sphere->getHull(), *&cylinder->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							//cube1->changeTexture(textures[1]);
							sphere->changeTexture(textures[3]);
							cylinder->changeTexture(textures[3]);
						}
					}
				}
			}
		}
	}

	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end() - 1; ++it)
	{
		//dynamic cast first object here //
		Cylinder* cylinder = dynamic_cast<Cylinder*> (*it);
		if (cylinder != nullptr)
		{
			vector<Shape*> objs = grid->getNeighbours(cylinder);//gameEntities;

			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1)
				{
					//dynamic cast second object here //
					Cylinder* cylinder2 = dynamic_cast<Cylinder*> (*it1);
					if (cylinder2 != nullptr)
					{
						if (gjk->performDetection(*&cylinder->getHull(), *&cylinder2->getHull()))
						{
							//Collision response
							//Sound::playSample(samples[0]);
							//cube1->changeTexture(textures[1]);
							cylinder->changeTexture(textures[3]);
							cylinder2->changeTexture(textures[3]);
						}
					}
				}
			}
		}
	}
}

void Game::moveObjects()
{
	//for (vector<Shape*>::iterator it = gameEntities.begin(); 
	//	it < gameEntities.end(); it++)
	//{
	//	if ((*it)->getPosition().x > 10 ||
	//		(*it)->getPosition().y > 10 ||
	//		(*it)->getPosition().z > 10)
	//		(*it)->updateVelocity(-(*it)->getVelocity());
	//	else
	//	(*it)->move();		
	//}
}

void Game::update(SDL_Event sdlEvent)
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

	//moveObjects(dt);
	player->update();

	//Clear grid here
	grid->clearGrid();

	for (vector<Shape*>::iterator it = gameEntities.begin(); it < gameEntities.end(); it++)
	{
		(*it)->update();
		
		//Register object to grid here
		grid->registerObj(*it);
	}
	checkCollisions();
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