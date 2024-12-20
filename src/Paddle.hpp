#include <SDL3/SDL.h>

class Paddle {
public:
    Paddle(float xPos, float yPos);
    ~Paddle();

    void init();
    void update(float deltaTime);
    void draw(SDL_Renderer* renderer);
    void handleInput(const SDL_Event &event);
    const SDL_FRect* getPos();
    void setPosY(float y);
private:
    SDL_FRect m_pos;
    int m_directionState;
    float m_initPosY;
};