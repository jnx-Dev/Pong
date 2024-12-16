#include "Ball.hpp"

struct m_posExact {
    float x, y;
};

struct m_velo {
    float x, y;
};

Ball::Ball(float x, float y)
{
    m_pos = { x, y, 50, 50 };
    m_posExact = { x, y };
}

Ball::~Ball() {}

void Ball::update(double deltaTime)
{

}

void Ball::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_pos);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}