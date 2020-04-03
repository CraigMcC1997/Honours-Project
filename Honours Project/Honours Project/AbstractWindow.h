// ##########################################
//
// This is the abstract class for the window
//
// ##########################################

#pragma once
#include "SDL.h"
#include <iostream>

class AbstractWindow
{
public:
	virtual SDL_Window* setupRC(SDL_GLContext &context) = 0;
	virtual SDL_Window* getWindow() = 0;
};