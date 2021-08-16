#pragma once
#include <SDL2/SDL.h>
#include "Elements.h"
#include "InitWin.h"
#include <thread>

class Ball : 
	public Element
{
public:
	Ball(int radius, Vector2i position, Vector2i velocity, Vector2i acceleration, SDL_Color color);
	void Update(std::vector<Element*>* el) override;
	void Render() override;
private:
	int radius;
};