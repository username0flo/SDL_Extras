#include <SDL.h>
#include <cmath>
#include "SDLE_vector.hpp"
#include "SDL_Extras.hpp"
#include <iostream>

SDL_E::Vector::Vector(int x, int y)
{
    this->x = x;
    this->y = y;
}


std::ostream& SDL_E::operator<<(std::ostream& os, const SDL_E::Vector& vect)
{
    os << "x: "<< vect.x << " y: " << vect.y;
    return os;
}

SDL_E::Vector SDL_E::Vector::operator+(Vector& other)
{
    return Vector{this->x + other.x, this->y + other.y};
} 

SDL_E::Vector SDL_E::Vector::operator+(const int& num)
{
    return Vector{this->x + num, this->y + num};
} 

void SDL_E::Vector::operator+=(const int& num)
{
    this->x += num;
    this->y += num;
}


SDL_E::Vector SDL_E::Vector::operator-(Vector& other)
{
    return Vector{this->x - other.x, this->y - other.y};
} 

SDL_E::Vector SDL_E::Vector::operator-(const int& num)
{
    return *this + (-num);
} 

void SDL_E::Vector::operator-=(const int& num)
{
    *this += -num;
}

bool SDL_E::Vector::operator==(SDL_E::Vector& other)
{
    return (other.x == this->x && other.y == this->y);
}

bool SDL_E::Vector::operator!=(SDL_E::Vector& other)
{
    return !(*this == other);
}

SDL_E::Vector SDL_E::Vector::operator*(const int& num)
{
    return Vector{this->x *num, this->y *num};
} 

void SDL_E::Vector::operator*=(const int& num)
{
    this->x *= num;
    this->y *= num;
}

int SDL_E::Vector::GetX()
{
    return this->x;
}

int SDL_E::Vector::GetY()
{
    return this->y;
}

void SDL_E::Vector::Flip()
{
    (*this) *= -1;
}

void SDL_E::Vector::FlipX()
{
    this->x *= -1;
}

void SDL_E::Vector::FlipY()
{
    this->y *= -1;
}

void SDL_E::Vector::ChangeX(int num)
{
    this-> x = num;
}

void SDL_E::Vector::ChangeY(int num)
{
    this-> y = num;
}

void SDL_E::Vector::AddX(int num)
{
    this-> x += num;
}

void SDL_E::Vector::AddY(int num)
{
    this-> y += num;
}

double SDL_E::Vector::get_magnitude()
{
    return sqrt(x*x + y*y);
}

int SDL_E::Vector::Dot(Vector other)
{
    return this->x * other.x + this->y * other.y;
}

double SDL_E::Vector::get_angle(Vector other)
{
    return this->Dot(other) / (this->get_magnitude() * other.get_magnitude());
}

