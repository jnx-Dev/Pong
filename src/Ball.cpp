#include "Ball.hpp"

const float RADIUS = 50.0f;
const float VELOCITY = 2.0f;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(1, 5);

Ball::Ball(float x, float y)
{
    m_pos = { x - RADIUS, y - RADIUS, RADIUS, RADIUS };

    m_initPosX = m_pos.x;
    m_initPosY = m_pos.y;

    m_velo = { VELOCITY, VELOCITY/2 };
}

Ball::~Ball() {}

void Ball::init(char scorer)
{
    setPos(m_initPosX, m_initPosY);
    if (scorer == 'l')
    {
        m_velo = { VELOCITY, VELOCITY/2 };
    }
    else if (scorer == 'r')
    {
        m_velo = { -VELOCITY, VELOCITY/2 };
    }
    else
    {
        m_velo = { VELOCITY, VELOCITY/2 };
    }
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
    float rndNr = distr(gen);

    if (m_velo.x * ((rndNr / 10) + 1) > 7.0f)
    {
        rndNr = 1.0f;
    }

    switch (target)
    {
    case 'x':
        m_velo.x *= -1 * ((rndNr/10) + 1);
        break;
    case 'y':
        m_velo.y *= -1 * ((rndNr /10) + 1);
        break;
    default:
        break;
    }

    std::cout << "x: " << m_velo.x << ", y: " << m_velo.y << std::endl;
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