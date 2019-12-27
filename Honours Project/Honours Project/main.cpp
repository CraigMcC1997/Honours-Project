#pragma once
#include "Window.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

Window* hWindow;

void init(void)
{

}

void update(void)
{

}

void draw(SDL_Window* window)
{

}

void clean(SDL_GLContext glContext)
{
	//BASS_Free();
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(hWindow->getWindow());
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	SDL_Renderer* renderTarget = nullptr;
	SDL_GLContext glContext; // OpenGL context handle
	SDL_Event sdlEvent;  // variable to detect SDL events

	hWindow = new Window(800, 600, "Introduction Screen");

	hWindow->setupRC(glContext);
	renderTarget = nullptr;
	renderTarget = SDL_CreateRenderer(hWindow->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	init();

	cout << glGetString(GL_VERSION) << endl;
	bool running = true;
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		update();
		draw(hWindow->getWindow());
	}

	clean(glContext);
	return 0;
}