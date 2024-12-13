#include <SDL3/SDL.h>

class Paddle {
public:
    Paddle();
    ~Paddle();

    void update(double deltaTime);
    void draw(SDL_Renderer* renderer);
    void handleInput(const SDL_Event &event);
private:
    SDL_Rect m_pos;
    double m_yExact = 0.0;
    int m_directionState = 0;
};