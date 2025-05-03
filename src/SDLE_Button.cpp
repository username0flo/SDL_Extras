#include <iostream>
#include <SDL.h>
#include "SDLE_Button.hpp"
#include "SDLE_collision.hpp"

//SDL_E::Button::

SDL_E::Button::Button(const Button& button)
{
    *this = button;
}

SDL_E::Button::Button(TTF_Font* font, SDL_Renderer* renderer, std::string message, int x, int y)
{
    this->font = font;
    this->renderer = renderer;
    this->message = message;
    this->Text::_LoadTexture();
    this->bg_rect.x = x;
    this->bg_rect.y = y;
    SDL_E::Button::_UpdateRect();
}

SDL_E::Button::Button(Text text, int x, int y) : Text(text)
{
    this->Text::_LoadTexture();
    this->bg_rect.x = x;
    this->bg_rect.y = y;
    SDL_E::Button::_UpdateRect();
}

SDL_E::Button::~Button()
{
    this->Text::~Text();
}


void SDL_E::Button::_UpdateRect()
{
    SDL_Rect temp = this->Text::Get_rect();
    this->Text::set_pos(this->bg_rect.x + padx, this->bg_rect.y + pady);
    this->bg_rect.w = temp.w + 2* padx;
    this->bg_rect.h = temp.h + 2* pady;
}


void SDL_E::Button::set_pad(int padx, int pady)
{
    this->padx = padx;
    this->pady = pady;
    this->_UpdateRect();

}

void SDL_E::Button::set_pos(int x, int y)
{
    this->bg_rect.x = x;
    this->bg_rect.y = y;
    this->_UpdateRect();
}

void SDL_E::Button::Draw()
{
    if(this->is_click && ((this->flags & BUTTON_COLOR_MODE) == BUTTON_ISCLICK_COLOR))
        SDL_SetRenderDrawColor(this->renderer,(this->bg_color.r + 50)%256, (this->bg_color.g + 50)%256, (this->bg_color.b + 50)%256, this->bg_color.a);
    else
        SDL_SetRenderDrawColor(this->renderer,this->bg_color.r, this->bg_color.g, this->bg_color.b, this->bg_color.a);
    SDL_RenderFillRect(this->renderer,&(this->bg_rect));
    this->Text::Draw();
}

SDL_Color SDL_E::Button::Get_txt_color()
{
    return this->text_color;
}

SDL_Color SDL_E::Button::Get_bg_color()
{
    return this->bg_color;
}

SDL_Rect SDL_E::Button::Get_rect()
{
    return this->bg_rect;
}

void SDL_E::Button::set_txt_color(SDL_Color color)
{
    this->Text::set_color(color);
}

void SDL_E::Button::set_txt_color(int r, int g, int b, int a)
{
    this->Text::set_color(r,g,b,a);
}

void SDL_E::Button::set_txt_bg_color(SDL_Color color)
{
    this->Text::set_color(color);
}

void SDL_E::Button::set_txt_bg_color(int r, int g, int b, int a)
{
    this->Text::set_color(r,g,b,a);
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

void SDL_E::Button::add_flag(int flag)
{
    this->Text::add_flag(flag);
}

void SDL_E::Button::remove_flag(int flag)
{
    this->Text::remove_flag(flag);
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
    this->is_click &= 0xff << 1;
    this->is_click |= state &1;
}

bool SDL_E::Button::clicked()
{
    return this->is_click &1;
}

bool SDL_E::Button::just_clicked()
{
    if(this->is_click &1)
    {
        if(this->is_click &2)
        {
            this->is_click &= (0xff<<2) |1; // this mask: 11111101
            return false;
        }
        this->is_click |= 2;
        return true;
    }
    return false;
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
    this->Text::operator=(other);
    this->bg_color = other.bg_color;
    this->bg_rect = other.bg_rect;
    this->padx = other.padx;
    this->pady = other.pady;
}

SDL_Point SDL_E::Button::Get_pad()
{
    SDL_Point pt = {this->padx, this->pady};
    return pt;
}