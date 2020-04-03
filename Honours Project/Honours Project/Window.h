// ##########################################################
//
// This class handles the window data using the SDL2 library
//
// ##########################################################

#pragma once
#include "AbstractWindow.h"

class Window : public AbstractWindow
{
private:
	SDL_Window* window;
	int height;
	int width;
	const char* windowName;
public:
	Window(int w, int h, const char* name) :
		width(w), height(h), windowName(name) {}

	virtual ~Window() {}
	SDL_Window* setupRC(SDL_GLContext &context);
	SDL_Window* getWindow();
};