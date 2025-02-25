#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include "SDLE_Text.hpp"
#include <string>

SDL_E::Text::Text(TTF_Font* font,SDL_Renderer* renderer, std::string message)
{
    this->renderer = renderer;
    this->font = font;
    this->message = message;
    this->rect.x = 0;
    this->rect.y = 0;

    this->_LoadTexture();
}

SDL_E::Text::Text(TTF_Font* font, SDL_Renderer* renderer, std::string message, int x, int y)
{
    this->renderer = renderer;
    this->font = font;
    this->message = message;
    this->rect.x = x;
    this->rect.y = y;

    this->_LoadTexture();
}

SDL_E::Text::Text(const SDL_E::Text& other)
{
    *this = other;
}

SDL_E::Text::~Text()
{
    SDL_DestroyTexture(this->texture);
}

std::string SDL_E::Text::Get_message()
{
    return this->message;
}

SDL_Color SDL_E::Text::Get_color()
{
    return this->text_color;
}

SDL_Color SDL_E::Text::Get_bg_color()
{
    return this->bg_color;
}

SDL_Rect SDL_E::Text::Get_rect()
{
    return this->rect;
}

SDL_Texture* SDL_E::Text::Get_texture()
{
    return this->texture;
}

SDL_Renderer* SDL_E::Text::Get_renderer()
{
    return this->renderer;
}

int SDL_E::Text::Get_flags()
{
    return this->flags;
}

void SDL_E::Text::_LoadTexture()
{
    SDL_DestroyTexture(texture);
    SDL_Surface* temp;
    if(flags & TEXT_LCD)
        temp = TTF_RenderUTF8_LCD(this->font, (this->message).c_str(),this->text_color, this->bg_color);
    else
        temp = TTF_RenderUTF8_Solid(this->font, (this->message).c_str(),this->text_color);
    if(temp == nullptr)
    {
        std::cerr << "error..." << std::endl;
        //TODO: throw an error
        return;
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer,temp);
    SDL_FreeSurface(temp);
    SDL_QueryTexture(this->texture,NULL,NULL, &(this->rect.w), &(this->rect.h));
}

void SDL_E::Text::Draw()
{
    SDL_RenderCopy(renderer,this->texture,NULL,&(this->rect));
}

void SDL_E::Text::set_pos(int x, int y)
{
    this->rect.x = x;
    this->rect.y = y;

}

void SDL_E::Text::set_color(SDL_Color color)
{
    this->text_color = color;
    this->_LoadTexture();
}

void SDL_E::Text::set_color(int r, int g, int b, int a)
{
    this->text_color.r = r;
    this->text_color.g = g;
    this->text_color.b = b;
    this->text_color.a = a;
    this->_LoadTexture();
}

void SDL_E::Text::set_bg_color(SDL_Color color)
{
    this->bg_color = color;
    this->_LoadTexture();
}

void SDL_E::Text::set_bg_color(int r, int g, int b, int a)
{
    this->bg_color.r = r;
    this->bg_color.g = g;
    this->bg_color.b = b;
    this->bg_color.a = a;
    this->_LoadTexture();
}

void SDL_E::Text::change_font(TTF_Font* new_font)
{
    if(this->font != new_font)
    {
        this->font = new_font;
        this->_LoadTexture();
    }
}

void SDL_E::Text::set_message(std::string message)
{
    if(this->message != message)
    {
        this->message = message;
        this->_LoadTexture();
    }
}

void SDL_E::Text::add_flag(int flag)
{
    this->flags |= flag;
    this->_LoadTexture();
}

void SDL_E::Text::remove_flag(int flag)
{
    this->flags &= ~flag;
    this->_LoadTexture();
}

TTF_Font* SDL_E::Text::Get_Font()
{
    return this->font;
}


void SDL_E::Text::operator=(const Text& other)
{
    this->font = other.font;
    this->renderer = other.renderer;
    this->message = other.message;
    this->rect = other.rect;
    this->text_color = other.text_color;

    this->_LoadTexture();
    
}

/*----------------------------------------------------------------------------------------*/
// TEXT ZONE
/*----------------------------------------------------------------------------------------*/

void SDL_E::TextZone::change_zone_size(int w, int h)
{
    this->zone_rect.w = w;
    this->zone_rect.h = h;
    this->_LoadTexture();
}


void SDL_E::TextZone::change_zone_pos(int x, int y)
{
    this->zone_rect.x = x;
    this->zone_rect.y = y;
}


void SDL_E::TextZone::_LoadTexture()
{
    SDL_DestroyTexture(texture);
    if(this->message == "")
    {
        texture = NULL;
        return;
    }
    SDL_Surface* temp;
    if(this->flags & TEXT_LCD)
        temp = TTF_RenderUTF8_LCD_Wrapped(this->font, (this->message).c_str(),this->text_color,this->bg_color,this->zone_rect.w - this->zone_rect.x);
    else
        temp = TTF_RenderUTF8_Solid_Wrapped(this->font, (this->message).c_str(),this->text_color,this->zone_rect.w - this->zone_rect.x);
    if(temp == nullptr)
    {
        std::cerr << "error..." << std::endl;
        //TODO: throw an error
        return;
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer,temp);
    SDL_FreeSurface(temp);
    SDL_QueryTexture(this->texture,NULL,NULL, &(this->rect.w), &(this->rect.h));
}

void SDL_E::TextZone::add_typed_chars(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_RETURN)
        this->message += "\n";
    
        else if(event.key.keysym.sym == SDLK_TAB)
            this->message += "    ";
    
        else if(event.key.keysym.sym == SDLK_BACKSPACE)
        {
            if(this->message.size() >= 1)
                this->message.pop_back();
        }
        // else if(event.key.keysym.sym == SDLK_LEFT)
        //     this->cursor--;
        // else if(event.key.keysym.sym == SDLK_RIGHT)
        // this->cursor--;

    }

    std::string txt = event.text.text;
    for(const char car : txt)
    {
        if(isprint(car))
            this->message += car;
    }
    this->_LoadTexture();

}

void SDL_E::TextZone::Draw()
{
    SDL_Rect* src_rect = NULL;
    SDL_Rect* dest_rect = &(this->rect);
    if(this->zone_rect.h < this->rect.h)
    {
        SDL_Rect temp_rect = {0,this->rect.h - this->zone_rect.h, this->zone_rect.w,this->zone_rect.h};
        dest_rect = &(this->zone_rect);
        src_rect = &temp_rect;
    }
        
    SDL_RenderCopy(renderer,this->texture,src_rect,dest_rect);
}