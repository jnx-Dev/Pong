#pragma once

#include <SDL3/SDL.h>
#include "Ball.hpp"
#include "Paddle.hpp"

class Application
{
public:
	Application();
	~Application();

	void loopStart();
	void update(double deltaTime);
	void draw();
private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Event m_event;

	Paddle m_paddleLeft;
	Paddle m_paddleRight;
	Ball m_ball;
};