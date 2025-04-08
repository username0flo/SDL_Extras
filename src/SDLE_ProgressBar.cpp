
#include <iostream>
#include <SDL.h>
#include "SDLE_ProgressBar.hpp"

SDL_E::ProgressBar::ProgressBar(int start, int end)
{
    this->start = start;
    this->end = end;
}

SDL_E::ProgressBar::ProgressBar(int start, int end, int width)
{
    this->start = start;
    this->end = end;
    this->rect.w = width;
}

        
void SDL_E::ProgressBar::set_pos(int x, int y)
{
    this->rect.x = x;
    this->rect.y = y;
}

void SDL_E::ProgressBar::set_size(int w,int h)
{
    this->rect.w = w;
    this->rect.h = h;
}

void SDL_E::ProgressBar::set_outline_color(SDL_Color color)
{
    this->outline_color = color;
}

void SDL_E::ProgressBar::set_color(SDL_Color color)
{
    this->color = color;
}

void SDL_E::ProgressBar::set_end(int end)
{
    this->end = end;
}

void SDL_E::ProgressBar::set_start(int start)
{
    this->start = start;
}

void SDL_E::ProgressBar::set_value(float value)
{
    this->value  = value;
}


float SDL_E::ProgressBar::get_value()
{
    return this->value;
}

SDL_Point SDL_E::ProgressBar::get_pos()
{
    SDL_Point pos = {this->rect.x, this->rect.y};
    return pos;
}

SDL_Point SDL_E::ProgressBar::get_size()
{
    SDL_Point size = {this->rect.w, this->rect.h};
    return size;
}

void SDL_E::ProgressBar::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    int prog_width = (int)(((this->value - (double)this->start) / (double)(this->end - this->start)) * (double)this->rect.w);
    SDL_Rect prog_rect = {this->rect.x, this->rect.y, prog_width, this->rect.h};
    SDL_RenderFillRect(renderer, &prog_rect);

    SDL_SetRenderDrawColor(renderer, this->outline_color.r, this->outline_color.g, this->outline_color.b, this->outline_color.a);
    SDL_RenderDrawRect(renderer, &(this->rect));
}
