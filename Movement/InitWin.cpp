#include "InitWin.h"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Renderer* InitWin::get_renderer()
{
	return ren;
}

SDL_Window* InitWin::get_window()
{
	return win;
}

int InitWin::getW()
{
    return width;
}

int InitWin::getH()
{
    return height;
}

InitWin::InitWin(int width, int height)
{
    this->width = width;
    this->height = height;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

    win = SDL_CreateWindow("Movement", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (win == nullptr) std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
}

InitWin::~InitWin()
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

InitWin* InitWin::insrtance()
{
    static InitWin* w = new InitWin(1920, 1000);
    return w;
}
