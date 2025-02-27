#include <iostream>
#include <SDL.h>
#include <vector>
#include "SDLE_collision.hpp"
#include "SDL_Extras.hpp"


bool SDL_E::point_rect_collision(SDL_Point pt, SDL_Rect rect)
{
    return SDL_E::point_rect_collision(pt.x, pt.y, rect);
}

bool SDL_E::point_rect_collision(int x, int y, SDL_Rect rect)
{
    return x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h;
}

bool SDL_E::rect_collision(SDL_Rect r1, SDL_Rect r2)
{
    return SDL_E::point_rect_collision(r1.x, r1.y, r2) ||
           SDL_E::point_rect_collision(r1.x + r1.w, r1.y, r2) ||
           SDL_E::point_rect_collision(r1.x, r1.y + r1.h, r2) ||
           SDL_E::point_rect_collision(r1.x + r1.w, r1.y + r1.h, r2);
}

bool SDL_E::point_triangle_collision(int x, int y, SDL_Point* triangle)
{
    return point_triangle_collision(x, y, triangle[0], triangle[1], triangle[2]);
}

bool SDL_E::point_triangle_collision(int x, int y, SDL_Point tp1, SDL_Point tp2, SDL_Point tp3)
{
    // to check this collision we compute the area of each subtriangle formed with the point we check and 2 points in the triangle
    // if the sum of the area of the 3 subtriangles is equal to the area of the main triangle: the point is in the triangle

    // to compute the area we use the formula: abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
    int amain = abs((tp2.x - tp1.x)*(tp3.y - tp1.y) - (tp3.x - tp1.x)*(tp2.y - tp1.y)); // area of the main triangle
    int a1 = abs((tp1.x - x)*(tp2.y - y) - (tp2.x - x)*(tp1.y - y)); // triangle made with: (x,y), tp1, tp2
    int a2 = abs((tp2.x - x)*(tp3.y - y) - (tp3.x - x)*(tp2.y - y)); // triangle made with: (x,y), tp2, tp3
    int a3 = abs((tp3.x - x)*(tp1.y - y) - (tp1.x - x)*(tp3.y - y)); // triangle made with: (x,y), tp3, tp1
    return (a1 + a2 + a3) == amain;

}


bool SDL_E::point_shape_collision(int x, int y, Shape shape)
{
    for(int i = 0; i < shape.nb_points - 2; i++)
    {
        if(point_triangle_collision(x,y,shape.points[0],shape.points[i+1],shape.points[i+2]))
            return true;
    }
    return false;
}

bool SDL_E::point_shape_collision(int x, int y, std::vector<SDL_Point> shape)
{
    for(size_t i = 0; i < shape.size() - 2; i++)
    {
        if(point_triangle_collision(x,y,shape[0],shape[i+1],shape[i+2]))
            return true;
    }
    return false;
}

bool SDL_E::shape_collision(struct Shape shape1, struct Shape shape2)
{
    for(int i = 0; i < shape1.nb_points; i++)
    {
        if(point_shape_collision(shape1.points[i].x,shape1.points[i].y,shape2))
        {
            return true;
        }
    }
    return false;
}

bool SDL_E::shape_collision(std::vector<SDL_Point> shape1, std::vector<SDL_Point> shape2)
{
    for(size_t i = 0; i < shape1.size(); i++)
    {
        if(point_shape_collision(shape1[i].x,shape1[i].y,shape2))
        {
            return true;
        }
    }
    return false;
}

bool SDL_E::point_circle_collision(int px, int py, SDL_Point center, int radius)
{
    return distance(px,py,center.x, center.y) <= radius;
}

bool SDL_E::circle_collision(SDL_Point center1, int radius1, SDL_Point center2, int radius2)
{
    return distance(center1, center2) <= radius1 + radius2;
}