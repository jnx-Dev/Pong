#pragma once

#include <SDL3/SDL.h>

class Application
{
public:
	Application();
	~Application();

	void update();
	void draw();
private:
	SDL_Window* m_window = nullptr;
	SDL_Surface* m_windowSurface = nullptr;
	SDL_Event m_windowEvent;
};