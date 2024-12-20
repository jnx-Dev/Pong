#include <random>
#include <iostream>

#include <SDL3/SDL.h>

class Ball {
public:
    struct velocity { float x, y; };
    Ball(float x, float y);
    ~Ball();

    void init(char scorer);
    void update(float deltaTime);
    void draw(SDL_Renderer* renderer);
    void invertVelo(char target);
    const SDL_FRect* getPos();
    void setPos(float x, float y);
private:
    SDL_FRect m_pos;
    velocity m_velo;
    float m_initPosX;
    float m_initPosY;
};