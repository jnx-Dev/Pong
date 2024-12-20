#include "Paddle.hpp"

const float PADDLE_WIDTH = 50.0f;
const float PADDLE_HEIGHT = 150.0f;

Paddle::Paddle(float xPos, float yPos)
{
    m_pos = { xPos, yPos, PADDLE_WIDTH, PADDLE_HEIGHT };
    m_directionState = 0;
    m_initPosY = yPos;
}

Paddle::~Paddle() {}

void Paddle::init()
{
    setPosY(m_initPosY);
    m_directionState = 0;
}

void Paddle::handleInput(const SDL_Event &event)
{
    switch (event.type) {
        case SDL_EVENT_KEY_DOWN:
            const bool* state = SDL_GetKeyboardState(nullptr);

            if (m_pos.x < 400)
            {
                if (state[SDL_SCANCODE_W])
                {
                    m_directionState = 1;
                }
                else if (state[SDL_SCANCODE_S])
                {
                    m_directionState = -1;
                }
            }
            else if (m_pos.x > 400)
            {
                if (state[SDL_SCANCODE_UP])
                {
                    m_directionState = 1;
                }
                else if (state[SDL_SCANCODE_DOWN])
                {
                    m_directionState = -1;
                }
            }
    }
}

void Paddle::update(float deltaTime)
{
    if (m_directionState > 0)
    {
        if (m_pos.y > 0)
        {
            m_pos.y -= 5.0f * deltaTime;
        }
    }
    else if (m_directionState < 0)
    {
        if (m_pos.y < 600 - m_pos.h)
        {
            m_pos.y += 5.0f * deltaTime;
        }
    }
}

void Paddle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_pos);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

const SDL_FRect* Paddle::getPos()
{
    return &m_pos;
}

void Paddle::setPosY(float y)
{
    m_pos.y = y;
}