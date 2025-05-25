#include "../src/SDL_Extras.hpp"
#include <cassert>
#include <iostream>
#include <SDL.h>
#include <array>
#include <vector>
#include <string>
#include <SDL_ttf.h>

#define WINW 600
#define WINH 400


int main(int argc, char** argv)
{  
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("Viktor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINW,WINH,0);
    if(!window)
    {
        std::cout << "erreur creation fenetre" << std::endl;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        std::cout << "erreur creation renderer" << std::endl;
    }
    TTF_Font* font = TTF_OpenFont("tests/arial.ttf",16);

    SDL_E::title();

    bool run{true};

    // all tests:

    while(run)
    {
        
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                run = false;
                break;
            }
         
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}