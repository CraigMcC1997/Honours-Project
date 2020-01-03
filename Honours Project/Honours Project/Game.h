#pragma once
#include "Window.h"
#include "rt3d.h"

class Game
{
private:

public:
	void init();
	void update();
	void draw(SDL_Window* window);
};