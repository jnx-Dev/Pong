#include "Application.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int PADDLE_DIS = 100;

Application::Application() : m_paddleLeft(PADDLE_DIS, SCREEN_HEIGHT/2), m_paddleRight(SCREEN_WIDTH - PADDLE_DIS, SCREEN_HEIGHT / 2), m_ball(SCREEN_HEIGHT/2, SCREEN_WIDTH/2)
{
	SDL_CreateWindowAndRenderer("Pong", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &m_window, &m_renderer);

	if (!m_window) {
		SDL_Log("SDL Window creation failed: %s", SDL_GetError());
		SDL_Quit();
		return;
	}

	if (!m_renderer) {
		SDL_Log("SDL Renderer creation failed: %s", SDL_GetError());
		SDL_Quit();
		return;
	}

	SDL_SetRenderLogicalPresentation(m_renderer, 400, 400, SDL_LOGICAL_PRESENTATION_DISABLED);
}

Application::~Application()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Application::loopStart()
{
	bool windowAlive = true;
	while (windowAlive) {
		while (SDL_PollEvent(&m_event) == 1) {
			switch (m_event.type)
			{
			case SDL_EVENT_QUIT:
				windowAlive = false;
				break;
			default:
				break;
			}

			m_paddleLeft.handleInput(m_event);
			m_paddleRight.handleInput(m_event);
		}
		
		update(1.0/60.0);
		draw();
	}
}

void Application::update(double deltaTime)
{
	m_paddleLeft.update(deltaTime);
	m_paddleRight.update(deltaTime);
	m_ball.update(deltaTime);
}

void Application::draw()
{
	SDL_RenderClear(m_renderer);

	m_paddleLeft.draw(m_renderer);
	m_paddleRight.draw(m_renderer);
	m_ball.draw(m_renderer);

	SDL_RenderPresent(m_renderer);
}