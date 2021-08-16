#include "Simulation.h"

void Simulation::Update(SDL_Renderer* ren)
{
	SDL_RenderPresent(ren);
}

Simulation::Simulation(std::vector<Ball*>* balls)
{

}