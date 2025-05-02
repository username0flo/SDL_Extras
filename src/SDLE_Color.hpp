#ifndef SDL_E_COLOR
#define SDL_E_COLOR

#include <iostream>
#include <SDL.h>
#include <string>
#include "SDL_Extras.hpp"

namespace SDL_E
{

    struct HSL
    {
        int h;
        double s;
        double l_v;
    };

    using HSV = HSL;

    /**
     * convert a HSL entry to RGB
     * \param hue the angle for the hue (between 0 and 360)
     * \param saturation a percentage between 0 and 1 
     * \param lightness a percentage between 0 and 1 
     * \return a rgb value equivalent to HSL
     */
    SDL_Color HSL_to_RGB(int hue, double saturation, double lightness);

    /**
     * convert a HSV entry to RGB
     * \param hue the angle for the hue (between 0 and 360)
     * \param saturation a percentage between 0 and 1 
     * \param value a percentage between 0 and 1 
     * \return a rgb value equivalent to HSV
     */
    SDL_Color HSV_to_RGB(int hue, double saturation, double value);

    /**
     * convert a RGB entry to HSL
     * \param r the amount of red
     * \param g the amount of green
     * \param b the amount of blue
     * \return a HSL value equivalent to RGB
     * \warning this fuction return a SDL_E struct name HSL and have fields `h`(int),`s`(double),and `l_v`(double) (same struct for HSV)
     */
    HSL RGB_to_HSL(int r, int g, int b);

    /**
     * convert a RGB entry to HSV
     * \param r the amount of red
     * \param g the amount of green
     * \param b the amount of blue
     * \return a HSV value equivalent to RGB
     * \warning this fuction return a SDL_E struct name HSV and have fields `h`(int),`s`(double),and `l_v`(double) (same struct for HSL)
     */
    HSV RGB_to_HSV(int r, int g, int b);

    /**
     * convert a hexadacimal notation string to RBG
     * \param hex_color your color in hexadecimal format (RGB or RGBA '#' at the beginig is accepted)
     * \return a SDL_Color struct that code RGBA values with 4 fields: r, g, b and a
     */
    SDL_Color hex_to_RGB(std::string hex_color);

    /**
     * convert rgb (or rgba) to a string in hexadecimal format: (RGB)
     * \param r the amont of red (max 255)
     * \param g the amont of green (max 255)
     * \param b the amont of blue (max 255)
     * \return a string that is hexadecimal representation of the color
     */
    std::string RGB_to_hex(int r, int g, int b);

    /**
     * convert rgba to a string in hexadecimal format: (RGBA)
     * \param r the amont of red (max 255)
     * \param g the amont of green (max 255)
     * \param b the amont of blue (max 255)
     * \param a the transparency (opaque : 255)
     * \return a string that is hexadecimal representation of the color
     */
    std::string RGB_to_hex(int r, int g, int b, int a);
}

#endif