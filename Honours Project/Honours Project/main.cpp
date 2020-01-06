#pragma once
#include "Game.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

Game* game;

void init(void)
{
	game = new Game();
	game->init();
}

void update(SDL_Event sdlEvent)
{
	game->update(sdlEvent);
}

void draw(SDL_Window* window)
{
	game->draw(window);
}

void clean(SDL_GLContext glContext, Window* hWindow)
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

	Window* hWindow;
	hWindow = new Window(800, 600, "Honours Project");

	hWindow->setupRC(glContext);
	renderTarget = nullptr;
	renderTarget = SDL_CreateRenderer(hWindow->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << glGetString(GL_VERSION) << endl;

	init();

	bool running = true;
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		update(sdlEvent);
		draw(hWindow->getWindow());
	}
	clean(glContext, hWindow);
	return 0;
}