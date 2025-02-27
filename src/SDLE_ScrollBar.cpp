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

    SDL_E::RenderFillCircle(renderer,
                        this->get_circle_x(),
                        this->get_circle_y(),
                        this->get_circle_radius());

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
    if(event.type == SDL_MOUSEBUTTONUP)
        this->is_hold = false;
    
    if(event.type == SDL_MOUSEMOTION && this->is_hold)
    {
        int mousex = std::clamp(event.button.x, this->bar.x, this->bar.x + this->bar.w);
        this->value = _update_value(*this,mousex);
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mousex = event.button.x;
        int mousey = event.button.y;
        SDL_Point pt = {this->get_circle_x(), this->get_circle_y()};
        if(point_circle_collision(mousex, mousey, pt, this->get_circle_radius()))
        {
            mousex = std::clamp(event.button.x, this->bar.x, this->bar.x + this->bar.w);
            this->is_hold = true;
            this->value = _update_value(*this,mousex);
        }
        if(point_rect_collision(mousex,mousey,this->bar))
        {
            this->value = _update_value(*this,mousex);
        }
    }
}

SDL_E::flin_value _update_value(SDL_E::ScrollBar& srllbar, int mousex)
{
    SDL_E::flin_value value;
    SDL_Rect bar = srllbar.get_rect();
    int end = srllbar.get_end();
    if((srllbar.get_mode() & 1) == SCROLL_INT_MODE)
    {
        double step_size = bar.w / end;
        int relative_pos = mousex - bar.x;
        int index = (int)SDL_round(relative_pos / step_size);
        value.i_value = index + srllbar.get_start();
    }
    else
    {
        value.f_value = (float)(mousex - bar.x) * ((float)end / (float)bar.w);
    }
    return value;

}

int SDL_E::ScrollBar::get_circle_x()
{
    double val;
    if((mode & 1) == SCROLL_FLOAT_MODE)
    {
        val = (this->value.f_value - this->start) * this->bar.w / this->nb_vals;
    }
    else
    {
        int step_size = (int)(this->bar.w / this->nb_vals);
        val  = (float)(this->value.i_value - this->start)* step_size/this->step;
    }
    return this->bar.x + val;
}

int SDL_E::ScrollBar::get_circle_y()
{
    return this->bar.y + (this->bar.h /2);
}

int SDL_E::ScrollBar::get_circle_radius()
{
    return (int)((float)(this->bar.h) * (this->circle_ratio /2));
}

SDL_Rect SDL_E::ScrollBar::get_rect()
{
    return this->bar;
}

int SDL_E::ScrollBar::get_start()
{
    return this->start;
}

int SDL_E::ScrollBar::get_step()
{
    return this->step;
}

int SDL_E::ScrollBar::get_end()
{
    return this->nb_vals;
}