#include <iostream>
#include <SDL.h>
#include "SDLE_Button.hpp"
#include "SDLE_collision.hpp"

//SDL_E::Button::

SDL_E::Button::Button(const Button& button)
{
    *this = button;
}

SDL_E::Button::Button(Text text): text(text)
{
    SDL_E::Button::_UpdateRect();
}


SDL_E::Button::Button(TTF_Font* font, SDL_Renderer* renderer, std::string message): text(font,renderer,message)
{
    SDL_E::Button::_UpdateRect();
}


SDL_E::Button::Button(TTF_Font* font, SDL_Renderer* renderer, std::string message, int x, int y): text(font,renderer,message)
{
    this->rect.x = x;
    this->rect.y = y;
    SDL_E::Button::_UpdateRect();
}
SDL_E::Button::Button(Text text, int x, int y): text(text)
{
    this->rect.x = x;
    this->rect.y = y;
    SDL_E::Button::_UpdateRect();
}
SDL_E::Button::~Button()
{
    this->text.~Text();
}


void SDL_E::Button::_UpdateRect()
{
    SDL_Rect temp = this->text.Get_rect();
    this->text.set_pos(this->rect.x + padx, this->rect.y + pady);
    this->rect.w = temp.w + 2* padx;
    this->rect.h = temp.h + 2* pady;
}


void SDL_E::Button::set_pad(int padx, int pady)
{
    this->padx = padx;
    this->pady = pady;
    this->_UpdateRect();

}

void SDL_E::Button::set_pos(int x, int y)
{
    this->rect.x = x;
    this->rect.y = y;
    this->_UpdateRect();
}

void SDL_E::Button::Draw()
{
    SDL_Renderer* rend = this->text.Get_renderer();
    if(this->is_click && (flag & BUTTON_ISCLICK_COLOR))
        SDL_SetRenderDrawColor(rend,(this->bg_color.r + 50)%256, (this->bg_color.g + 50)%256, (this->bg_color.b + 50)%256, this->bg_color.a);
    else
        SDL_SetRenderDrawColor(rend,this->bg_color.r, this->bg_color.g, this->bg_color.b, this->bg_color.a);
    SDL_RenderFillRect(rend,&(this->rect));
    this->text.Draw();
}


std::string SDL_E::Button::Get_message()
{
    return this->text.Get_message();
}

SDL_Color SDL_E::Button::Get_txt_color()
{
    return this->text.Get_color();
}

SDL_Color SDL_E::Button::Get_bg_color()
{
    return this->bg_color;
}

SDL_Rect SDL_E::Button::Get_rect()
{
    return this->rect;
}

void SDL_E::Button::set_txt_color(SDL_Color color)
{
    this->text.set_color(color);
}

void SDL_E::Button::set_txt_color(int r, int g, int b, int a)
{
    this->text.set_color(r,g,b,a);
}

void SDL_E::Button::set_bg_color(SDL_Color color)
{
    this->bg_color = color;
}

void SDL_E::Button::set_bg_color(int r, int g, int b, int a)
{
    this->bg_color.r = r;
    this->bg_color.g = g;
    this->bg_color.b = b;
    this->bg_color.a = a;
}

void SDL_E::Button::change_font(TTF_Font* new_font)
{
    this->text.change_font(new_font);
}

void SDL_E::Button::set_message(std::string message)
{
    this->text.set_message(message);
}

void SDL_E::Button::add_flag(int flag)
{
    this->flag |= flag;
}

void SDL_E::Button::remove_flag(int flag)
{
    this->flag &= ~flag;
}

void SDL_E::buttons_clicked(SDL_Event event, std::vector<Button> buttons)
{
    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
    {
        int x = event.button.x;
        int y = event.button.y;
        for(Button& button : buttons)
        {
            if(SDL_E::point_rect_collision(x,y,button.Get_rect()))
            {
                button.change_click_state(true);
                break;
            }
        }
    }
    else if(event.type == SDL_MOUSEBUTTONUP)
    {
        for(Button& button : buttons)
        {
            button.change_click_state(false);
        }
    }
}

void SDL_E::buttons_clicked(SDL_Event event, Button* buttons, int nb_buttons)
{
    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
    {
        int x = event.button.x;
        int y = event.button.y;
        for(int i = 0; i < nb_buttons; i++)
        {
            if(SDL_E::point_rect_collision(x,y,buttons[i].Get_rect()))
            {
                buttons[i].change_click_state(true);
                break;
            }
        }
    }
    else if(event.type == SDL_MOUSEBUTTONUP)
    {
        for(int i = 0; i < nb_buttons; i++)
        {
            buttons[i].change_click_state(false);
        }
    }
}

void SDL_E::Button::change_click_state(bool state)
{
    this->is_click = state;
}

bool SDL_E::Button::clicked()
{
    return this->is_click;
}

void SDL_E::draw_buttons(std::vector<Button> buttons)
{
    for(Button& button : buttons)
    {
        button.Draw();
    }
}

void SDL_E::draw_buttons(Button* buttons, int nb_buttons)
{
    for(int i = 0; i < nb_buttons; i++)
    {
        buttons[i].Draw();
    }
}

void SDL_E::Button::operator=(const Button& other)
{
    this->bg_color = other.bg_color;
    this->flag = other.flag;
    this->rect = other.rect;
    this->padx = other.padx;
    this->pady = other.pady;
    this->text = other.text;
}

int SDL_E::Button::Get_flags()
{
    return this->flag;
}

SDL_Point SDL_E::Button::Get_pad()
{
    SDL_Point pt = {this->padx, this->pady};
    return pt;
}