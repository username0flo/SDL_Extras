#include "../src/SDL_Extras.hpp"
#include <iostream>
#include <SDL.h>
#include <array>
#include <SDL_ttf.h>

#define WINW 600
#define WINH 400

#define font_rate 700
#define nb_font 4

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

    bool run{true};

    std::array<int,5> sizes{15,20,25,30,40};

    TTF_Font* arial = TTF_OpenFont("tests/arial.ttf",sizes[0]);
    TTF_Font* comic = TTF_OpenFont("tests/comic.ttf",sizes[0]);
    TTF_Font* impact = TTF_OpenFont("tests/impact.ttf",sizes[0]);
    TTF_Font* MTCORSVA = TTF_OpenFont("tests/MTCORSVA.ttf",sizes[0]);

    std::array<TTF_Font*,nb_font> fonts{arial, comic, impact, MTCORSVA};

    int index = 0;
    int index2 = 0;


    SDL_E::Text texte_test{arial,renderer,"texte de test",30,30};

    size_t t1 = SDL_GetTicks64();

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
        if((SDL_GetTicks64() - t1) >= font_rate)
        {
            index++;
            index %= nb_font;
            if(index == 0)
            {
                index2++;
                index2 %= 5;
                for(const auto &font : fonts)
                {
                    TTF_SetFontSize(font,sizes[index2]);
                }
            }
            texte_test.change_font(fonts[index]);
            t1 = SDL_GetTicks64();
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        texte_test.Draw();
        // SDL_Rect temp = texte_test.Get_rect();
        // SDL_RenderDrawRect(renderer,&temp);
        SDL_RenderPresent(renderer);
    }
    for(const auto font : fonts)
    {
        TTF_CloseFont(font);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}