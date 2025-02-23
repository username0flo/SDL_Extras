#include "SDL_Extras.hpp"
#include "SDLE_vector.hpp"
#include "SDLE_drawing.hpp"
#include "SDLE_Text.hpp"
#include "SDLE_Button.hpp"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <cmath>

void SDL_E::explanation()
{
    //(v) logo: SDL EXTRAS
    std::cout << "  _____ _____  _         ________   _________ _____             _____ \n / ____|  __ \\| |       |  ____\\ \\ / /__   __|  __ \\     /\\    / ____|\n| (___ | |  | | |       | |__   \\ V /   | |  | |__) |   /  \\  | (___  \n \\___ \\| |  | | |       |  __|   > <    | |  |  _  /   / /\\ \\  \\___ \\ \n ____) | |__| | |____   | |____ / . \\   | |  | | \\ \\  / ____ \\ ____) |\n|_____/|_____/|______|  |______/_/ \\_\\  |_|  |_|  \\_\\/_/    \\_\\_____/ " << std::endl;
    std::cout << "here are quick explanation of what is SDL_Extras, this function was created also to fill the SDL_E.hpp file with other things than includes\nso SDL_Extras is a extras librairy based on SDL graphic library\nthis library was created to add features to SDL like:\n\tVectors (in math not std::vectors)\n\tbuttons\n\ttext (using SDL_TTF package)\n\ttext zone (wich is a user modifable text)" << std::endl;
}

double SDL_E::distance(SDL_Point p1,SDL_Point p2)
{
    return SDL_E::distance(p1.x,p1.y,p2.x,p2.y);
}

double SDL_E::distance(int p1x, int p1y, int p2x, int p2y)
{
    return sqrt(pow(p1x - p2x,2) + pow(p1y - p2y,2));
}

void SDL_E::move(SDL_Rect* rect, Vector& vect)
{
    rect->x += vect.GetX();
    rect->y += vect.GetY();
}

void SDL_E::move(Text& text, Vector& vect)
{
    SDL_Rect temp = text.Get_rect();
    text.set_pos(temp.x + vect.GetX(), temp.y + vect.GetY());
}

void SDL_E::move(Button& button, Vector& vect)
{
    SDL_Rect temp = button.Get_rect();
    button.set_pos(temp.x + vect.GetX(), temp.y + vect.GetY());
}

void SDL_E::move(Shape& shape, Vector& vect)
{
    for(int i = 0; i < shape.nb_points; i++)
    {
        shape.points[i].x += vect.GetX();
        shape.points[i].y += vect.GetY();
    }
}

void SDL_E::move(std::vector<SDL_Point>& shape, Vector& vect)
{
    for(size_t i = 0; i < shape.size(); i++)
    {
        shape[i].x += vect.GetX();
        shape[i].y += vect.GetY();
    }
}