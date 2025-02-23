#ifndef __SDLE_DRAWING__
#define __SDLE_DRAWING__

#include <iostream>
#include <vector>
#include "SDL_Extras.hpp"
#include "SDLE_collision.hpp"
#include <SDL.h>

namespace SDL_E
{
    /**
     * draw a simple filled circle
     * \param renderer the rendering context
     * \param x the x coordinate of the center
     * \param y the y coordinate of the center
     * \param radius the radius of the circle 
     */
    void RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius);

    /**
     * draw a simple filled circle
     * \param renderer the rendering context
     * \param pt a point which is the center of the circle
     * \param radius the radius of the circle 
     */
    void RenderFillCircle(SDL_Renderer* renderer, SDL_Point pt, int radius);

    /**
     * draw a simple non-filled circle
     * \param renderer the rendering context
     * \param x the x coordinate of the center
     * \param y the y coordinate of the center
     * \param radius the radius of the circle 
     */
    void RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius);

    /**
     * draw a simple non-filled circle
     * \param renderer the rendering context
     * \param pt a point which is the center of the circle
     * \param radius the radius of the circle 
     */
    void RenderDrawCircle(SDL_Renderer* renderer, SDL_Point pt, int radius);

    /**
     * draw a simple triangle
     * \param renderer the rendering context
     * \param p1 the first point of the triangle
     * \param p2 the second point of the triangle
     * \param p3 the third point of the triangle
     */
    void RenderDrawTriangle(SDL_Renderer* renderer, SDL_Point p1, SDL_Point p2, SDL_Point p3);
    void RenderDrawTriangle(SDL_Renderer* renderer, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);

    /**
     * draw a simple filled
     * \param renderer the rendering context
     * \param p1 the first point of the triangle
     * \param p2 the second point of the triangle
     * \param p3 the third point of the triangle
     */
    void RenderFillTriangle(SDL_Renderer* renderer, SDL_Point p1, SDL_Point p2, SDL_Point p3);

    /**
     * draw a simple shape(polygon)
     * \param renderer the rendering context
     * \param shape struct that contains a C like array of points and the number of points
     */
    void RenderDrawShape(SDL_Renderer* renderer, struct Shape shape);

    /**
     * draw a simple shape(polygon)
     * \param renderer the rendering context
     * \param shape a std::vector that contains points
     */
    void RenderDrawShape(SDL_Renderer* renderer, std::vector<SDL_Point> shape);

    /**
     * draw a simple filled shape(polygon)
     * \param renderer the rendering context
     * \param shape struct that contains a C like array of points and the number of points
     */
    void RenderFillShape(SDL_Renderer* renderer, struct Shape shape);

    /**
     * draw a simple filled shape(polygon)
     * \param renderer the rendering context
     * \param shape a std::vector that contains points
     */
    void RenderFillShape(SDL_Renderer* renderer, std::vector<SDL_Point> shape);
}

#endif