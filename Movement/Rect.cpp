#include "Rect.h"
#include "InitWin.h"
Rect::Rect(int size, Vector2i pos, Vector2i vel, Vector2i acc, SDL_Color col) : Element(pos, vel, acc, col), size(size)
{
}

void Rect::Update(std::vector<Element*>* el)
{
    setPosition(getPosition() + getVelocity());
    //setVelocity(getVelocity() * 0.98);

    auto pos = getPosition();
    auto vel = getVelocity();

    if (pos.x + size >= WIN->getW() - 50 && vel.x > 0 || pos.x - size <= 50 && vel.x < 0)
    {
        setVelocity(Vector2i(-vel.x, vel.y));
    }

    if (pos.y - size <= 50 && vel.y < 0 || pos.y + size >= WIN->getH() - 50 && vel.y > 0)
    {
        setVelocity(Vector2i(vel.x, -vel.y));
    }
}

void Rect::Render()
{
	SDL_SetRenderDrawColor(WIN->get_renderer(), getColor().r, getColor().g, getColor().b, getColor().a);
	SDL_Rect r = {getPosition().x - size /2, getPosition().y - size/2, size, size};
	SDL_RenderFillRect(WIN->get_renderer(), &r);
}
