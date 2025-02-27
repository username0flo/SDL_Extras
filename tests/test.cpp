#include "../src/SDL_Extras.hpp"
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
    int i = 0;
    
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
    TTF_Font* font = TTF_OpenFont("tests/arial.ttf",20);
    

    // SDL_E::Button bouton1{font,renderer,"test1", 10, 10};
    // SDL_E::Button bouton2{font,renderer,"test2", 150, 10};
    // SDL_E::Button bouton3{font,renderer,"test3", 10, 150};
    // SDL_E::Button bouton4{font,renderer,"test4", 300, 300};
    // std::vector<SDL_E::Button> buttons{bouton1,bouton2};
    // buttons.push_back({font,renderer,"test1", 10, 10});
    // buttons.push_back({font,renderer,"test2", 150, 10});
    // buttons.push_back({font,renderer,"test3", 10, 150});
    // buttons.push_back({font,renderer,"test4", 300, 300});
    // SDL_E::Button buttons[4] = {bouton1,bouton2,bouton3,bouton4};


    SDL_E::explanation();

    bool run{true};

    // SDL_Point p1 = {10,10};
    // SDL_Point p2 = {140,20};
    // SDL_Point p3 = {90,340};

    // SDL_Point points[5] = {{89,30},{0,0},{128,33},{393,73},{89,223}};
    // SDL_E::Shape shape = {points,5};
    SDL_Color transparent = {0,0,0,0};
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);

    SDL_E::TextZone txt_zne{font,renderer,"bonjour, je fais des test random"};
    txt_zne.change_zone_size(200,400);
    txt_zne.add_flag(TEXT_LCD);
    txt_zne.set_bg_color(transparent);
    

    SDL_E::ScrollBar bar{};
    bar.change_mode(SCROLL_FLOAT_MODE);
    bar.set_pos(150,50);
    bar.set_size(400,20);
    bar.set_value((float)100.0);
    bar.set_start(0);
    bar.set_end(100);
    float last_val = bar.get_value().f_value;
    SDL_E::Text txt_val{font,renderer,std::to_string(last_val)};
    txt_val.set_pos(200,10);
    std::cout << "mode : " << bar.get_mode() << std::endl;

    SDL_Rect rct = {200,80,200,200};
    


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
            txt_zne.add_typed_chars(event);
            bar.Update(event);
            // SDL_E::buttons_clicked(event,buttons);
        }
        if(last_val != bar.get_value().f_value)
        {
            last_val = bar.get_value().f_value;
            txt_val.set_message(std::to_string(last_val));
            rct.w = 200 * (bar.get_value().f_value / 100.0);
            rct.h = 200 * (bar.get_value().f_value / 100.0);

        }
        // for(int i = 0;i < 4; i++)
        // {
        //     if(buttons[i].clicked())
        //         std::cout << "buttons clicked : " << buttons[i].Get_message() << std::endl;
        // }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        // SDL_SetRenderDrawColor(renderer,255,0,0,255);
        // SDL_E::RenderFillTriangle(renderer,p1,p2,p3);
        // SDL_SetRenderDrawColor(renderer,0,100,255,255);
        // SDL_E::RenderFillShape(renderer,shape);
        // SDL_E::draw_buttons(buttons);
        SDL_SetRenderDrawColor(renderer,0,200,140,255);
        SDL_RenderFillRect(renderer,&rct);
        txt_zne.Draw();
        txt_val.Draw();
        bar.Draw(renderer);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}