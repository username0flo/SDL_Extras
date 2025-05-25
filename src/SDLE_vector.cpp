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

void SDL_E::Vector::operator=(const Vector& other)
{
    this->x = other.x;
    this->y = other.y;
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

void SDL_E::Vector::operator+=(Vector& other)
{
    this->x += other.x;
    this->y += other.y;
}


SDL_E::Vector SDL_E::Vector::operator-(Vector& other)
{
    return Vector{this->x - other.x, this->y - other.y};
} 

SDL_E::Vector SDL_E::Vector::operator-(const int& num)
{
    return *this + (-num);
} 

void SDL_E::Vector::operator-=(Vector& other)
{
    this->x -= other.x;
    this->y -= other.y;
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

SDL_E::Vector SDL_E::operator+(const int& num, Vector& vect)
{
    return vect + num;
}

SDL_E::Vector SDL_E::operator-(const int& num, Vector& vect)
{
    return vect - num ; 
}

SDL_E::Vector SDL_E::operator*(const int& num, Vector& vect)
{
    return vect * num;
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
    return acos((double)this->Dot(other) / (this->get_magnitude() * other.get_magnitude()));
}



/*------------------------------------------------------------
Vectorf
------------------------------------------------------------*/


SDL_E::Vectorf::Vectorf(double x, double y)
{
    this->x = x;
    this->y = y;
}

SDL_E::Vectorf::Vectorf(const Vectorf& other)
{
    this->x = other.x;
    this->y = other.y;
}

void SDL_E::Vectorf::set_pos(double x, double y)
{
    this->x = x;
    this->y = y;
}

void SDL_E::Vectorf::setX(double x)
{
    this->x = x;
}

void SDL_E::Vectorf::setY(double y)
{
    this->y = y;
}

double SDL_E::Vectorf::GetX()
{
    return this->x;
}

double SDL_E::Vectorf::GetY()
{
    return this->y;
}

void SDL_E::Vectorf::Flip()
{
    (*this) *= -1.0;
}

void SDL_E::Vectorf::FlipX()
{
    this->x *= -1;
}

void SDL_E::Vectorf::FlipY()
{
    this->y *= -1;
}

void SDL_E::Vectorf::AddX(double num)
{
    this-> x += num;
}

void SDL_E::Vectorf::AddY(double num)
{
    this-> y += num;
}

double SDL_E::Vectorf::get_magnitude()
{
    return sqrt(x*x + y*y);
}

double SDL_E::Vectorf::Dot(Vectorf other)
{
    return this->x * other.x + this->y * other.y;
}

double SDL_E::Vectorf::get_angle(Vectorf other)
{
    return acos(this->Dot(other) / (this->get_magnitude() * other.get_magnitude()));
}

void SDL_E::Vectorf::normalize()
{
    double magintude = this->get_magnitude();
    this->x /= magintude;
    this->y /= magintude;
}

void SDL_E::Vectorf::operator=(const Vectorf& other)
{
    this->x = other.x;
    this->y = other.y;
}

SDL_E::Vectorf SDL_E::Vectorf::operator+(Vectorf& other)
{
    return Vectorf(this->x + other.x, this->y + other.y);
}

SDL_E::Vectorf SDL_E::Vectorf::operator+(const int& num)
{
    return Vectorf(this->x + num, this->y + num);
}

void SDL_E::Vectorf::operator+=(Vectorf& other)
{
    this->x += other.x;
    this->y += other.y;
}

SDL_E::Vectorf SDL_E::Vectorf::operator-(Vectorf& other)
{
    return Vectorf(this->x - other.x, this->y - other.y);
}

SDL_E::Vectorf SDL_E::Vectorf::operator-(const int& num)
{
    return Vectorf(this->x - num, this->y - num);
}

void SDL_E::Vectorf::operator-=(Vectorf& other)
{
    this->x -= other.x;
    this->y -= other.y;
}

SDL_E::Vectorf SDL_E::Vectorf::operator*(const int& num)
{
    return Vectorf(this->x * num, this->y *num);
}

void SDL_E::Vectorf::operator*=(const int& num)
{
    this->x *= num;
    this->y *= num;
}

bool SDL_E::Vectorf::operator==(Vectorf& other)
{
    return (this->x - other.x == 0.0 && this->y - other.y == 0.0);
}

bool SDL_E::Vectorf::operator!=(Vectorf& other)
{
    return !((*this) == other);
}


std::ostream& SDL_E::operator<<(std::ostream& os, const Vectorf& vect)
{
    os << "x: "<< vect.x << " y: " << vect.y;
    return os;
}

SDL_E::Vectorf SDL_E::operator+(const int& num, Vectorf& vect)
{
    return vect + num;
}

SDL_E::Vectorf SDL_E::operator-(const int& num, Vectorf& vect)
{
    return vect - num;
}

SDL_E::Vectorf SDL_E::operator*(const int& num, Vectorf& vect)
{
    return vect * num;
}