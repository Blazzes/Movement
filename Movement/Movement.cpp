#include <iostream>
#include <SDL2/SDL.h>
#include "Ball.h"
#include "InitWin.h"
#include "Rect.h"
#include <ctime>
#include <thread>
#include <mutex>

int main(int argc, char* args[])
{
    bool quit = false;
    
    srand(time(0));

    std::vector<Element*> elem;

    for (int i = 0; i < 1; i++)
    {
        SDL_Color col = { rand() % 255,rand() % 255 ,rand() % 255, 255 };
        elem.push_back(new Rect(rand() % 10 + 10, { (double)(rand() % WIN->getW()), (double)(rand() % WIN->getH()) }, { 500, 0}, { 0,0 }, col));
    }
    Uint32 fps = SDL_GetTicks();
    int count = 0;


    while (!quit)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) quit = true;
        }

        SDL_SetRenderDrawColor(WIN->get_renderer(), 0,0,0,255);
        SDL_RenderClear(WIN->get_renderer());

        for (auto i : elem) i->Update(&elem);

        for (auto i : elem) i->Render();

        SDL_RenderPresent(WIN->get_renderer());

        if (SDL_GetTicks() - fps >= 1000)
        {
            std::cout << count << std::endl;
            count = 0;
            fps = SDL_GetTicks();
        }
        count++;
    }
    return 0;
}
