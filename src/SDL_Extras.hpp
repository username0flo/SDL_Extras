#ifndef __SDL_EXTRAS__
#define __SDL_EXTRAS__
#include <SDL.h>
#include <iostream>
#include <vector>
#include "SDLE_vector.hpp"
#include "SDLE_drawing.hpp"
#include "SDLE_Text.hpp"
#include "SDLE_Button.hpp"
#include "SDLE_ScrollBar.hpp"

namespace SDL_E
{

    void explanation();

    /**
     * compute the distance between 2 points
     * \param p1 the first point
     * \param p2 the second point
     * \return the distance between the 2 points
     */
    double distance(SDL_Point p1,SDL_Point p2);

    /**
     * compute the distance between 2 points
     * \param p1x the x coordinate of the first point
     * \param p1y the y coordinate of the first point
     * \param p2x the x coordinate of the second point
     * \param p2y the y coordinate of the second point
     * \return the distance between the 2 points
     */
    double distance(int p1x, int p1y, int p2x, int p2y);

    /**
     * move a rectangle by a vector
     * \param rect the rectangle
     * \param vect the vector
     */
    void move(SDL_Rect* rect, Vector& vect);

    /**
     * move a text by a vector
     * \param text the text
     * \param vect the vector
     */
    void move(Text& text, Vector& vect);

    /**
     * move a button by a vector
     * \param button the button
     * \param vect the vector
     */
    void move(Button& button, Vector& vect);

    /**
     * move a shape by a vector
     * \param shape the shape
     * \param vect the vector
     */
    void move(Shape& shape, Vector& vect);

    /**
     * move a shape by a vector
     * \param shape the shape
     * \param vect the vector
     */
    void move(std::vector<SDL_Point>& shape, Vector& vect);

    /**
     * a simple shape defined with an array of points and the size of this array
     */
    struct Shape
    {
        SDL_Point* points;
        int nb_points;
    };
}

#endif