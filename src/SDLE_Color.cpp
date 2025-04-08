#include <iostream>
#include <SDL.h>
#include <string>
#include <cmath>
#include <sstream>
#include "SDL_Extras.hpp"
#include "SDLE_Color.hpp"


SDL_Color SDL_E::HSL_to_RGB(int hue, double saturation, double lightness)
{
    if(saturation == 0.0)
    {
        Uint8 greyscale = (Uint8)(lightness * 255.0);
        SDL_Color rgb_color = {greyscale,greyscale,greyscale,255};
        return rgb_color;
    }
    double temp1;
    if(lightness < 0.5)
        temp1 = lightness * (1.0 + saturation);
    else
        temp1 = lightness + saturation - lightness * saturation;
    
    double temp2 = 2.0 * lightness - temp1;

    double h = (double)(hue) / 360.0;

    double tempr = h + 0.333; // 0.333 ~= 1/3 (but we don't need a lot of precision)
    if(tempr > 1.0)
        tempr -= 1.0;
    
    double tempg = h;

    double tempb = h - 0.333;
    if(tempb < 0.0)
        tempb += 1.0;
    
    double r,g,b;

    if(6 * tempr < 1)
        r = temp2 + (temp1 - temp2)* 6 * tempr;
    else if(2 * tempr < 1)
        r = temp1;
    else if(3* tempr < 2)
        r = temp2 + (temp1 - temp2) * (0.6666 - tempr)* 6;
    else
        r = temp2;
    
    if(6 * tempg < 1)
        g = temp2 + (temp1 - temp2)* 6 * tempg;
    else if(2 * tempg < 1)
        g = temp1;
    else if(3* tempg < 2)
        g = temp2 + (temp1 - temp2) * (0.6666 - tempg)* 6;
    else
        g = temp2;
    
    if(6 * tempb < 1)
        b = temp2 + (temp1 - temp2)* 6 * tempb;
    else if(2 * tempb < 1)
        b = temp1;
    else if(3* tempb < 2)
        b = temp2 + (temp1 - temp2) * (0.6666 - tempb)* 6;
    else
        b = temp2;

    SDL_Color rgb_color = {(Uint8)round(r * 255.0),(Uint8)round(g * 255.0),(Uint8)round(b * 255.0),255};

    return rgb_color;
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