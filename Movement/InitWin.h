#pragma once
#include <SDL2/SDL.h>

#define WIN InitWin::insrtance()

class InitWin
{
public:
    SDL_Renderer* get_renderer();
    SDL_Window* get_window();
    int getW();
    int getH();
    ~InitWin();
    static InitWin* insrtance();
private:
    InitWin(int width, int height);
    SDL_Window* win;
    SDL_Renderer* ren;
    int width;
    int height;
};
