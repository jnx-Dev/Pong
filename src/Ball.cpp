#include "Ball.hpp"

const float RADIUS = 50.0f;
const float VELOCITY = 2.0f;

Ball::Ball(float x, float y)
{
    m_pos = { 0, 0, RADIUS, RADIUS };
    m_pos.x = x - m_pos.w;
    m_pos.y = y - m_pos.h;

    m_initPosX = m_pos.x;
    m_initPosY = m_pos.y;

    m_velo = { VELOCITY, VELOCITY/2.0f};
}

Ball::~Ball() {}

void Ball::init()
{
    setPos(m_initPosX, m_initPosY);
}

void Ball::update(float deltaTime)
{
    m_pos.x += m_velo.x * deltaTime;
    m_pos.y += m_velo.y * deltaTime;
}

void Ball::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_pos);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Ball::invertVelo(char target)
{
    switch (target)
    {
    case 'x':
        m_velo.x *= -1;
        break;
    case 'y':
        m_velo.y *= -1;
        break;
    default:
        break;
    }
}


const SDL_FRect* Ball::getPos()
{
    return &m_pos;
}

void Ball::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

void Ball::randVeloIncrease()
{

}