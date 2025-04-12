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

            void operator=(const Vector& other);

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

            /**
             * \return the magnitude (i.e. length) of the vector
             */
            double get_magnitude();

            /**
             * \return the dot product (i.e. scalar product) between the 2 vectors
             */
            int Dot(Vector other);

            /**
             * \return the angle between the 2 vectors
             * \warning the angle is returned in radians
             */
            double get_angle(Vector other);

        private:
            int x;
            int y;
        friend std::ostream& operator<<(std::ostream& os, const Vector& vect);
    };
    std::ostream& operator<<(std::ostream& os, const Vector& vect);

    Vector operator+(const int& num, Vector& vect);

    Vector operator-(const int& num, Vector& vect);

    Vector operator*(const int& num, Vector& vect);



    class Vectorf
    {
        public:
            Vectorf() = default;

            Vectorf(double x, double y);

            Vectorf(const Vectorf& other);

            void operator=(const Vectorf& other);

            Vectorf operator+(Vectorf& other);
            Vectorf operator+(const int& num);
            void operator+=(const int& num);

            Vectorf operator-(Vectorf& other);
            Vectorf operator-(const int& num);
            void operator-=(const int& num);

            Vectorf operator*(const int& num);
            void operator*=(const int& num);

            bool operator==(Vectorf& other);
            bool operator!=(Vectorf& other);

            /**
             * set a new x,y coordinates to the vector
             * \param x the x coordinate
             * \param y the y cooordinate
             */
            void set_pos(double x, double y);

            /**
             * set a new x coordinate to the vector
             * \param x the x coordinate
             */
            void setX(double x);

            /**
             * set a new y coordinate to the vector
             * \param y the y cooordinate
             */
            void setY(double y);

            /**
             * \return the x coordinate of the vector
             */
            double GetX();

            /**
             * \return the y coordinate of the vector
             */
            double GetY();

            /**
             * add a value to the x coordinate
             * \param num the value with will be added to x coordinate
             */
            void AddX(double num);

            /**
             * add a value to the y coordinate
             * \param num the value with will be added to y coordinate
             */
            void AddY(double num);

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

            /**
             * \return the magnitude (i.e. length) of the vector
             */
            double get_magnitude();

            /**
             * \return the dot product (i.e. scalar product) between the 2 vectors
             */
            double Dot(Vectorf other);

            /**
             * \return the angle between the 2 vectors
             * \warning the angle is returned in radians
             */
            double get_angle(Vectorf other);

            /**
             * set the magnitude (i.e. length) of the vector to 1
             */
            void normalize();


        private:
            double x;
            double y;
        friend std::ostream& operator<<(std::ostream& os, const Vectorf& vect);
    };
    std::ostream& operator<<(std::ostream& os, const Vectorf& vect);

    Vectorf operator+(const int& num, Vectorf& vect);

    Vectorf operator-(const int& num, Vectorf& vect);

    Vectorf operator*(const int& num, Vectorf& vect);
}

#endif