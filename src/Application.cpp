#include "Application.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Application::Application()
{
	m_window = SDL_CreateWindow("Pong", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!m_window) {
		SDL_Log("SDL Window creation failed: %s", SDL_GetError());
		SDL_Quit();
		return;
	}

	m_windowSurface = SDL_GetWindowSurface(m_window);
	if (!m_windowSurface) {
		SDL_Log("SDL Window Surface creation failed: %s", SDL_GetError());
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return;
	}
}

Application::~Application()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Application::update()
{
	bool windowAlive = true;
	while (windowAlive) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
				case SDL_EVENT_QUIT:
					windowAlive = false;
					break;
				default:
					break;
			}
		}

		draw();
	}
}

void Application::draw()
{
	SDL_UpdateWindowSurface(m_window);
	SDL_Delay(16);
}