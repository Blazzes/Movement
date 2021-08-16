#pragma once
#include "Elements.h"
class Rect :
    public Element
{
public:
    Rect(int size, Vector2i pos, Vector2i vel, Vector2i acc, SDL_Color col);
    void Update(std::vector<Element*>* el) override;
    void Render() override;
private:
    int size;
};

