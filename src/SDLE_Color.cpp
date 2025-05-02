#include <iostream>
#include <SDL.h>
#include <string>
#include <cmath>
#include <sstream>
#include "SDL_Extras.hpp"
#include "SDLE_Color.hpp"

SDL_Color SDL_E::HSL_to_RGB(int hue, double saturation, double lightness)
{
    double chroma = (1 - fabs(2.0*lightness -1)) * saturation;

    double H = hue / 60.0;
    double X = chroma * (1 - fabs(fmod(H, 2.0) -1));

    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    if(H >= 0.0 && H < 1.0)
    {
        r = chroma;
        g = X;
    }
    else if(H < 2.0)
    {
        r = X;
        g = chroma;
    }
    else if(H < 3.0)
    {
        g = chroma;
        b = X;
    }
    else if(H < 4.0)
    {
        g = X;
        b = chroma;
    }
    else if(H < 5.0)
    {
        r = X;
        b = chroma;
    }
    else if(H < 6.0)
    {
        r = chroma;
        b = X;
    }

    double m = lightness - (chroma /2.0);

    SDL_Color color = {(Uint8)(round(255.0* (r+m))),(Uint8)(round(255.0* (g+m))),(Uint8)(round(255.0* (b+m))),255};
    return color;
}

SDL_Color SDL_E::HSV_to_RGB(int hue, double saturation, double value)
{
    double chroma = saturation * value;
    double H = hue / 60.0;
    double X = chroma * (1 - fabs(fmod(H, 2.0) -1));

    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    if(H >= 0.0 && H < 1.0)
    {
        r = chroma;
        g = X;
    }
    else if(H < 2.0)
    {
        r = X;
        g = chroma;
    }
    else if(H < 3.0)
    {
        g = chroma;
        b = X;
    }
    else if(H < 4.0)
    {
        g = X;
        b = chroma;
    }
    else if(H < 5.0)
    {
        r = X;
        b = chroma;
    }
    else if(H < 6.0)
    {
        r = chroma;
        b = X;
    }

    double m = value - chroma;
    SDL_Color color = {(Uint8)(round(255.0* (r+m))),(Uint8)(round(255.0* (g+m))),(Uint8)(round(255.0* (b+m))),255};
    return color;

}

SDL_E::HSL SDL_E::RGB_to_HSL(int r, int g, int b)
{
    int max =  std::max(std::max(r,g),b);


    double red = (double)(r)/255.0;
    double green = (double)(g)/255.0;
    double blue = (double)(b)/255.0;

    double x_max = std::max(std::max(red,green),blue);
    double x_min = std::min(std::min(red,green),blue);

    double chroma = x_max - x_min;

    double L = (x_max + x_min) /2.0;

    int hue;
    if(chroma == 0.0)
        hue = 0;
    
    else if(max == r)
    {
        hue = (int)round(60.0 * fmod((green - blue)/chroma,6));
    }
    else if(max == g)
    {
        hue = (int)round(60.0 * (((blue - red)/chroma) +2));
    }
    else
    {
        hue = (int)round(60.0 * (((red - green)/chroma) +4));
    }
    

    double saturation;

    if(L == 0.0 || L == 1.0)
    {
        saturation = 0.0;
    }
    else
    {
        saturation = (2.0 * (x_max - L)) / (1.0 - fabs(2.0*L -1));
    }
    HSL color = {hue,saturation,L};
    return color;
}

SDL_E::HSV SDL_E::RGB_to_HSV(int r, int g, int b)
{
    int max =  std::max(std::max(r,g),b);


    double red = (double)(r)/255.0;
    double green = (double)(g)/255.0;
    double blue = (double)(b)/255.0;

    double value = std::max(std::max(red,green),blue);
    double x_min = std::min(std::min(red,green),blue);

    double chroma = value - x_min;

    int hue;
    if(chroma == 0.0)
        hue = 0;
    
    else if(max == r)
    {
        hue = (int)round(60.0 * fmod((green - blue)/chroma,6));
    }
    else if(max == g)
    {
        hue = (int)round(60.0 * (((blue - red)/chroma) +2));
    }
    else
    {
        hue = (int)round(60.0 * (((red - green)/chroma) +4));
    }
    

    double saturation;

    if(value == 0.0)
    {
        saturation = 0.0;
    }
    else
    {
        saturation = chroma / value;
    }
    HSV color = {hue,saturation,value};
    return color;
}

SDL_Color SDL_E::hex_to_RGB(std::string hex_color)
{
    std::string hex_str;
    if(hex_color[0] == '#')
    {
        hex_str = hex_color.substr(1);
    }
    else
        hex_str = hex_color;
    
    SDL_Color color = {0,0,0,255};
    unsigned long value =  std::strtoul(hex_str.c_str(),NULL,16);

    if(hex_str.length() == 6)
    {
        color.r = (Uint8)(value >> 16);
        color.g = (Uint8)((value >> 8) & 0xff);
        color.b = (Uint8)(value & 0xff);
    }
    else if(hex_str.length() == 8)
    {
        color.r = (Uint8)(value >> 24);
        color.g = (Uint8)((value >> 16) & 0xff);
        color.b = (Uint8)((value >> 8) & 0xff);
        color.a = (Uint8)(value & 0xff);
    }


    return color;
}

std::string SDL_E::RGB_to_hex(int r, int g, int b)
{
    std::ostringstream hex_str;
    hex_str << std::hex << r << g << b;
    return hex_str.str();
}

std::string SDL_E::RGB_to_hex(int r, int g, int b, int a)
{
    std::ostringstream hex_str;
    hex_str << std::hex << a;
    return RGB_to_hex(r,g,b) + hex_str.str();
}