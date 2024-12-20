#pragma once
#include <iostream>

#include <SDL3/SDL.h>
#include "Ball.hpp"
#include "Paddle.hpp"

class Application
{
public:
	struct Score { int left, right; };
	Application();
	~Application();

	void loopStart();
	void update(float deltaTime);
	void draw();
	void drawRect(SDL_Renderer* renderer, SDL_FRect &rect);
	void reset();
	void checkIntersection();
	void checkScore();
private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Event m_event;

	Paddle m_paddleLeft;
	Paddle m_paddleRight;
	Ball m_ball;

	Score m_score = { 0, 0 };

	SDL_FRect m_borderTop;
	SDL_FRect m_borderBottom;
	SDL_FRect m_borderRight;
	SDL_FRect m_borderLeft;
};