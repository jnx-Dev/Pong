#include <random>

#include <SDL3/SDL.h>

class Ball {
public:
    struct posExact { float x, y; };
    struct velocity { float x, y; };
    Ball(float x, float y);
    ~Ball();

    void update(double deltaTime);
    void draw(SDL_Renderer* renderer);
private:
    SDL_FRect m_pos;
    posExact m_posExact = { 0, 0 };
    velocity m_velo = { 0, 0 };
};