#ifndef __SDLE_VECTOR__
#define __SDLE_VECTOR__

#include <SDL.h>
// #include "SDL_Extras.hpp"
#include <iostream>

namespace SDL_E
{
    /**
     * a simple class that represent a mathematic 2D vector (can be also use as a point)
     */
    class Vector
    {
        public:
            Vector() = default;
            /**
             * \param x the x coordinates
             * \param y the y coordinates
             */
            Vector(int x, int y);
            Vector operator+(Vector& other);
            Vector operator+(const int& num);
            void operator+=(const int& num);

            Vector operator-(Vector& other);
            Vector operator-(const int& num);
            void operator-=(const int& num);

            Vector operator*(const int& num);
            void operator*=(const int& num);

            bool operator==(Vector& other);
            bool operator!=(Vector& other);

            /**
             * \return the x coordinate of the vector
             */
            int GetX();

            /**
             * \return the y coordinate of the vector
             */
            int GetY();

            /**
             * change the x coordinate of the vector
             * \param num the value of the x coordinate
             */
            void ChangeX(int num);

            /**
             * change the y coordinate of the vector
             * \param num the value of the y coordinate
             */
            void ChangeY(int num);

            /**
             * add a value to the x coordinate
             * \param num the value with will be added to x coordinate
             */
            void AddX(int num);

            /**
             * add a value to the y coordinate
             * \param num the value with will be added to y coordinate
             */
            void AddY(int num);

            /**
             * transform the vector into its opposite, it's equivalent to vector *= -1
             */
            void Flip();

            /**
             * change the vector's x coordinate to its opposite value, is like an axial symetry by the y axis
             */
            void FlipX();

            /**
             * change the vector's y coordinate to its opposite value, is like an axial symetry by the x axis
             */
            void FlipY();
        private:
            int x;
            int y;
        friend std::ostream& operator<<(std::ostream& os, const Vector& vect);
    };
    std::ostream& operator<<(std::ostream& os, const Vector& vect);
}

#endif