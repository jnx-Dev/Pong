#include "Application.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PADDLE_DIS = 100;
const int BORDER_MARGIN = 5;

const float DELTATIME = 0.02f; // 1.0f/50.0f

Application::Application() : m_paddleLeft(PADDLE_DIS, SCREEN_HEIGHT/2), m_paddleRight(SCREEN_WIDTH - PADDLE_DIS, SCREEN_HEIGHT/2),
							 m_ball(SCREEN_HEIGHT/2, SCREEN_WIDTH/2)
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

	SDL_SetRenderLogicalPresentation(m_renderer, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_LOGICAL_PRESENTATION_DISABLED);

	m_borderTop = { 0, 0, SCREEN_WIDTH, BORDER_MARGIN };
	m_borderBottom = { 0, SCREEN_HEIGHT - 5, SCREEN_WIDTH, BORDER_MARGIN };
	m_borderRight = { SCREEN_WIDTH - BORDER_MARGIN, 0, BORDER_MARGIN, SCREEN_HEIGHT };
	m_borderLeft = { 0, 0, 5, SCREEN_HEIGHT };
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
		
		update(DELTATIME);
		draw();
	}
}

void Application::update(float deltaTime)
{
	m_paddleLeft.update(deltaTime);
	m_paddleRight.update(deltaTime);
	m_ball.update(deltaTime);
}

void Application::draw()
{
	SDL_RenderClear(m_renderer);

	drawRect(m_renderer, m_borderTop);
	drawRect(m_renderer, m_borderBottom);
	drawRect(m_renderer, m_borderRight);
	drawRect(m_renderer, m_borderLeft);

	m_paddleLeft.draw(m_renderer);
	m_paddleRight.draw(m_renderer);
	m_ball.draw(m_renderer);

	SDL_RenderPresent(m_renderer);

	checkIntersection();
}

void Application::drawRect(SDL_Renderer* renderer, SDL_FRect &rect)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Application::reset()
{
	m_paddleLeft.init();
	m_paddleRight.init();
	m_ball.init();
}

void Application::checkIntersection()
{
	if (SDL_HasRectIntersectionFloat(m_paddleLeft.getPos(), m_ball.getPos()) ||
		SDL_HasRectIntersectionFloat(m_paddleRight.getPos(), m_ball.getPos()))
	{
		m_ball.invertVelo('x');
	}

	if (SDL_HasRectIntersectionFloat(&m_borderTop, m_ball.getPos()) ||
		SDL_HasRectIntersectionFloat(&m_borderBottom, m_ball.getPos()))
	{
		m_ball.invertVelo('y');
	}

	if (SDL_HasRectIntersectionFloat(&m_borderLeft, m_ball.getPos()))
	{
		m_score.right++;
		checkScore();
	}
	else if (SDL_HasRectIntersectionFloat(&m_borderRight, m_ball.getPos()))
	{
		m_score.left++;
		checkScore();
	}
}

void Application::checkScore()
{
	if (m_score.left < 10 && m_score.right < 10)
	{
		reset();
	}
	else if (m_score.left >= 10)
	{
		
	}
	else if (m_score.right >= 10)
	{

	}
}