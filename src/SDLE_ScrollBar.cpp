#include <iostream>
#include <SDL.h>
#include <algorithm>
#include "SDLE_ScrollBar.hpp"
#include "SDL_Extras.hpp"

SDL_E::ScrollBar::ScrollBar(int start, int step, int nb_vals)
{
    this->start = start;
    this->step = step;
    this->nb_vals = nb_vals;
}

SDL_E::ScrollBar::ScrollBar(int mode, int start, int step, int nb_vals)
{
    this->start = start;
    this->step = step;
    this->nb_vals = nb_vals;
    this->mode = mode;
}

void SDL_E::ScrollBar::set_pos(int x, int y)
{
    this->bar.x = x;
    this->bar.y = y;
}

void SDL_E::ScrollBar::set_size(int w, int h)
{
    this->bar.w = w;
    this->bar.h = h;
}

void SDL_E::ScrollBar::set_start(int start)
{
    this->start = start;
}

void SDL_E::ScrollBar::set_end(int end)
{
    this->nb_vals = end;
}

void SDL_E::ScrollBar::set_step(int step)
{
    this->step = step;
}

void SDL_E::ScrollBar::set_ratio(double ratio)
{
    this->circle_ratio = ratio;
}

void SDL_E::ScrollBar::change_mode(int mode)
{
    this->mode &= ~1;
    this->mode |= mode;
}

int SDL_E::ScrollBar::get_mode()
{
    return this->mode;
}

void SDL_E::ScrollBar::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,255,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&(this->bar));

    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    float val;
    if((mode & 1) == SCROLL_FLOAT_MODE)
    {
        val = (this->value.f_value - this->start) * this->bar.w / this->nb_vals;
    }
    else
    {
        int step_size = (int)(this->bar.w / this->nb_vals);
        val  = (float)(this->value.i_value - this->start)* step_size/this->step;
    }
    SDL_E::RenderFillCircle(renderer,
                        this->bar.x + val,
                        this->bar.y + (int)(this->bar.h / 2),
                        (int)((float)(this->bar.h) * (this->circle_ratio /2)));

}

void SDL_E::ScrollBar::set_value(int value)
{
    if((mode & 1) == SCROLL_INT_MODE)
        this->value.i_value = value;
    else
        this->value.f_value = value;
}

void SDL_E::ScrollBar::set_value(float value)
{
    if((mode & 1) ==  SCROLL_FLOAT_MODE)
        this->value.f_value = value;
    else
        this->value.i_value = (int)value;
}

SDL_E::flin_value SDL_E::ScrollBar::get_value()
{
    return this->value;
}

void SDL_E::ScrollBar::Update(SDL_Event event)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mousex = event.button.x;
        int mousey = event.button.y;
        if(point_rect_collision(mousex,mousey,this->bar))
        {
            if((this->mode & 1) == SCROLL_INT_MODE)
            {
                double step_size = this->bar.w / this->nb_vals;
                int relative_pos = mousex - this->bar.x;
                int index = (int)SDL_round(relative_pos / step_size);
                this->value.i_value = index + start;
            }
            else
            {
                this->value.f_value = (float)(mousex - this->bar.x) * ((float)this->nb_vals / (float)this->bar.w);
            }
        }
    }
}