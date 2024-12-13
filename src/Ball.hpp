#include <random>

#include <SDL3/SDL.h>

class Ball {
public:
    Ball();
    ~Ball();

    void update(double deltaTime);
    void draw(SDL_Renderer* renderer);
private:
    SDL_Rect m_pos;
    struct m_posExact;
    struct m_velo;
};