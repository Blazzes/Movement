#include "Ball.h"

Ball::Ball(int radius, Vector2i position, Vector2i velocity, Vector2i acceleration, SDL_Color color) : Element(position, velocity, acceleration, color),
	radius(radius)
{
    
}

void Ball::Update(std::vector<Element*>* el)
{
    setPosition(getPosition() + getVelocity());
    //setVelocity(getVelocity() * 0.95);

    auto pos = getPosition();
    auto vel = getVelocity();

    if (pos.x + radius >= WIN->getW() - 50 && vel.x > 0 || pos.x - radius <= 50 && vel.x < 0)
    {
        setVelocity(Vector2i(-vel.x, vel.y));
    }

    if (pos.y - radius <= 50 && vel.y < 0 || pos.y + radius >= WIN->getH() - 50 && vel.y > 0)
    {
        setVelocity(Vector2i(vel.x, -vel.y));
    }
}

void Ball::Render()
{
    SDL_SetRenderDrawColor(WIN->get_renderer(), getColor().r, getColor().g, getColor().b, getColor().a);
    int x = getPosition().x;
    int y = getPosition().y;
    for (int i = x - radius; i < x + radius + 1; ++i)
    {
        for (int j = y - radius; j < y + radius + 1; ++j)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
            {
                SDL_RenderDrawPoint(WIN->get_renderer(), i, j);
            }
        }
    }
}