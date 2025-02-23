#include <iostream>
#include <vector>
#include "SDL_Extras.hpp"
#include <SDL.h>
#include "SDLE_drawing.hpp"
#include "SDLE_collision.hpp"
#include <algorithm>

void SDL_E::RenderFillCircle(SDL_Renderer* renderer,int x, int y, int radius)
{
    for(int i{x-radius}; i < (x+radius); i++)
    {
        for(int j{y-radius}; j < (y+radius); j++)
        {
            if(SDL_E::distance(i,j,x,y) <= radius)
            {
                SDL_RenderDrawPoint(renderer,i,j);
            }
        }
    }
}

void SDL_E::RenderFillCircle(SDL_Renderer* renderer, SDL_Point pt, int radius)
{
    SDL_E::RenderFillCircle(renderer, pt.x, pt.y, radius);
}

//using midpoint algorithm (frow wikipedia)
void SDL_E::RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    int oct_x{0};
    int oct_y{radius};
    int t1{int(radius / 16)};
    int t2;

    while(oct_x < oct_y)
    {
        SDL_RenderDrawPoint(renderer, x + oct_x, y + oct_y);
        SDL_RenderDrawPoint(renderer, x - oct_x, y + oct_y);
        SDL_RenderDrawPoint(renderer, x + oct_x, y - oct_y);
        SDL_RenderDrawPoint(renderer, x - oct_x, y - oct_y);
        SDL_RenderDrawPoint(renderer, x + oct_y, y + oct_x);
        SDL_RenderDrawPoint(renderer, x - oct_y, y + oct_x);
        SDL_RenderDrawPoint(renderer, x + oct_y, y - oct_x);
        SDL_RenderDrawPoint(renderer, x - oct_y, y - oct_x);
        oct_x++;
        t1 += oct_x;
        t2 = t1 - oct_y;
        if(t2 >= 0)
        {
            t1 = t2;
            oct_y--;
        }
    }
}

void SDL_E::RenderDrawCircle(SDL_Renderer* renderer, SDL_Point pt, int radius)
{
    SDL_E::RenderDrawCircle(renderer, pt.x, pt.y, radius);
}

void SDL_E::RenderDrawTriangle(SDL_Renderer* renderer, SDL_Point p1, SDL_Point p2, SDL_Point p3)
{
    SDL_E::RenderDrawTriangle(renderer, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

void SDL_E::RenderDrawTriangle(SDL_Renderer* renderer, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
    SDL_RenderDrawLine(renderer, p1x, p1y, p2x, p2y);
    SDL_RenderDrawLine(renderer, p2x, p2y, p3x, p3y);
    SDL_RenderDrawLine(renderer, p3x, p3y, p1x, p1y);
}

void SDL_E::RenderFillTriangle(SDL_Renderer* renderer, SDL_Point p1, SDL_Point p2, SDL_Point p3)
{
    int max_x = std::max(std::max(p1.x,p2.x), p3.x);
    int max_y = std::max(std::max(p1.y,p2.y), p3.y);

    int min_x = std::min(std::min(p1.x,p2.x), p3.x);
    int min_y = std::min(std::min(p1.y,p2.y), p3.y);

    //SDL_Rect out_rect = {min_x, min_y, max_x - min_x, max_y - min_y};
    
    for(int i = min_x; i < max_x; i++)
    {
        for(int j = min_y; j < max_y; j++)
        {
            if(SDL_E::point_triangle_collision(i,j,p1,p2,p3))
            {
                SDL_RenderDrawPoint(renderer,i,j);
            }
        }
    }
}



void SDL_E::RenderFillShape(SDL_Renderer* renderer, struct Shape shape)
{
    for(int i = 0; i < shape.nb_points - 2; i++)
    {
        RenderFillTriangle(renderer,shape.points[0],shape.points[i+1],shape.points[i+2]);
    }
}
void SDL_E::RenderFillShape(SDL_Renderer* renderer, std::vector<SDL_Point> shape)
{
    for(size_t i = 0; i < shape.size() - 2; i++)
    {
        RenderFillTriangle(renderer,shape[0],shape[i+1],shape[i+2]);
    }
}

void SDL_E::RenderDrawShape(SDL_Renderer* renderer, struct Shape shape)
{
    SDL_RenderDrawLines(renderer,shape.points, shape.nb_points);
}

void SDL_E::RenderDrawShape(SDL_Renderer* renderer, std::vector<SDL_Point> shape)
{
    int shape_size = shape.size();
    for(int i = 0; i < shape_size -1; i++)
    {
        SDL_RenderDrawLine(renderer,shape[i].x, shape[i].y, shape[i+1].x, shape[i+1].y);
    }
    SDL_RenderDrawLine(renderer,shape[0].x, shape[0].y, shape[shape_size-1].x, shape[shape_size-1].y);
}