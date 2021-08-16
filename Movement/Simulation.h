#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "Ball.h"

class Simulation
{
	void Update(SDL_Renderer* ren);
	Simulation(std::vector<Ball*>* balls);
};

