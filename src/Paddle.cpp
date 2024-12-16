#include "Paddle.hpp"

Paddle::Paddle(float xPos, float yPos)
{
    m_pos = { xPos, yPos, 50, 150 };
}

Paddle::~Paddle() {}

void Paddle::handleInput(const SDL_Event &event)
{
    switch (event.type) {
        case SDL_EVENT_KEY_DOWN:
            const bool* state = SDL_GetKeyboardState(nullptr);

            if (m_pos.x < 500)
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
            else if (m_pos.x > 500)
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

void Paddle::update(double deltaTime)
{
    if (m_directionState < 0)
    {
        if (m_yExact > 0)
        {
            m_yExact -= 5.0 * deltaTime;
            m_pos.y = m_yExact;
        }
    }
    else if (m_directionState > 0)
    {
        if (m_yExact > 0) {
            m_yExact += 5.0 * deltaTime;
            m_pos.y = m_yExact;
        }
    }
}

void Paddle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_pos);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}