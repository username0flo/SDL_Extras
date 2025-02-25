#include <iostream>
#include <SDL.h>
#include "../src/SDL_Extras.hpp"
int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("test text",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,300,250,0);
    SDL_Renderer* renderer  = SDL_CreateRenderer(window,-1,0);

    TTF_Font* arial = TTF_OpenFont("tests/arial.ttf", 50); // opening a font with SDL_ttf package
    SDL_E::Text text{arial, renderer, "test", 30, 50}; // create a text with arial font, with "test" message with (30,30) coordinates
    SDL_E::Text text_lcd{arial, renderer, "test lcd", 30, 150};
    text_lcd.add_flag(TEXT_LCD); // set the flag to lcd

    // setting the lcd bazckgroud to transparent:
    SDL_Color transparent = {0,0,0,0};
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND); // to not forgot this line
    text_lcd.set_bg_color(transparent);

    text.Draw();
    text_lcd.Draw();
    SDL_RenderPresent(renderer);
    bool run = true;
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
    }
    TTF_Quit();
    SDL_Quit();
    // union flin
    // {
    //     int i;
    //     float f;
    // };

    // flin num;
    // num.i = 10;
    // std::cout << num.i << std::endl;

    // num.f = 3.1415;

    // std::cout << num.f << std::endl;


    return 0;
}