#ifndef _SDLE_COLLISION_
#define _SDLE_COLLISION_

#include <iostream>
#include <SDL.h>
#include <vector>
#include "SDL_Extras.hpp"

namespace SDL_E
{
    /**
     * check the intersection between a point and a rectangle
     * \param pt a point (form SDL_point structure)
     * \param rect the rectangle of type SDL_Rect
     * \return `true` if the point is in the rectangle and else `false`
     */
    bool point_rect_collision(SDL_Point pt, SDL_Rect rect);

    /**
     * check the intersection between a point and a rectangle
     * \param x the x coordinates of the point
     * \param y the y coordinates of the point
     * \param rect the rectangle of type SDL_Rect
     * \return `true` if the point is in the rectangle and else `false`
     */
    bool point_rect_collision(int x, int y, SDL_Rect rect);

    
    /**
     * check the intersection between 2 rectangles
     * \param r1 the first rectangle (SDL_Rect)
     * \param r2 the second rectangle (SDL_Rect)
     * \return `true` if there are any intersection between the 2 rectagles and else `false`
     */
    bool rect_collision(SDL_Rect r1, SDL_Rect r2);

    /**
     * check the intersection between a point and a triangle
     * \param x the x coordinate of the point
     * \param y the y coordinate of the point
     * \param triangle an C like array of points
     * \return `true` if the point is in the triangle and else `false`
    */
    bool point_triangle_collision(int x, int y, SDL_Point* triangle);

    /**
     * check the intersection between a point and a triangle
     * \param x the x coordinate of the point
     * \param y the y coordinate of the point
     * \param tp1 the first point of the triangle
     * \param tp2 the second point of the triangle
     * \param tp3 the third point of the triangle
     * \return `true` if the point is in the triangle and else `false`
    */
    bool point_triangle_collision(int x, int y, SDL_Point tp1, SDL_Point tp2, SDL_Point tp3);

    /**
     * check the intersection between a point and a shape(a polygon)
     * \param x the x coordinate of the point
     * \param y the y coordinate of the point
     * \param shape struct that contains a C like array of points and the number of points
     * \return `true` if the point is in the shape and else `false`
    */
    bool point_shape_collision(int x, int y, struct Shape shape);

    /**
     * check the intersection between a point and a shape(a polygon)
     * \param x the x coordinate of the point
     * \param y the y coordinate of the point
     * \param shape a std::vector that contains points
     * \return `true` if there are any intersection between the 2 shapes and else `false`
    */
    bool point_shape_collision(int x, int y, std::vector<SDL_Point> shape);

    /**
     * check the intersection between two shapes(polygons)
     * \param shape1 the first shape (which is a struct that contains a C like array of points and the number of points)
     * \param shape2 the second shape
     * \return `true` if the point is in the triangle and else `false`
    */
    bool shape_collision(struct Shape shape1, struct Shape shape2);

    /**
     * check the intersection between two shapes(polygons)
     * \param shape1 the first shape (a std::vector that contains points)
     * \param shape2 the second shape
     * \return `true` if the point is in the triangle and else `false`
    */
    bool shape_collision(std::vector<SDL_Point> shape1, std::vector<SDL_Point> shape2);

    /**
     * check the intersection between a point and a circle
     * \param px the x coordinate of the point
     * \param py the y coordinate of the point
     * \param center a point witch is the center of the circle
     * \param radius the radius of the circle
     */
    bool point_circle_collision(int px, int py, SDL_Point center, int radius);

    /**
     * check the intersection between two circles
     * \param center1 a point witch is the center of the first circle
     * \param radius2 the radius of the first circle
     * \param center2 a point witch is the center of the second circle
     * \param radius2 the radius of the second circle
     */
    bool point_circle_collision(SDL_Point center1, int radius1, SDL_Point center2, int radius2);
}


#endif