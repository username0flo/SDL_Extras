#ifndef __SDLE_TEXT__
#define __SDLE_TEXT__

/**
 * to use this package tou must have installed the sdl_ttf package
 * you can download it here: https://github.com/libsdl-org/SDL_ttf
 */

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

#define TEXT_SOLID 0 // 0b00000000
#define TEXT_LCD   1 // 0b00000001

namespace SDL_E
{
    class Text
    {
        public:
            Text() = default;
            Text(TTF_Font* font, SDL_Renderer* renderer, std::string message);
            Text(TTF_Font* font, SDL_Renderer* renderer , std::string message, int x, int y);
            Text(const Text& other);
            ~Text();

            void operator=(const Text& other);

            /**
             * \return the string that text show
             */
            std::string Get_message();

            /**
             * \return the color of the text
             */
            SDL_Color Get_color();

            /**
             * \return the color of the background (used only with LCD rendering)
             */
            SDL_Color Get_bg_color();

            /**
             * use this method to get the position or the size of the text
             * \return the rectangle of the text
             */
            SDL_Rect Get_rect();

            /**
             * use this method if you want to render text with rotation
             * \return the texture wich is render when the text is draw
             */
            SDL_Texture* Get_texture();

            /**
             * \return the rendering context where the text is drawed
             */
            SDL_Renderer* Get_renderer();

            /**
             * \return the font wich is use to render the text
             */
            TTF_Font* Get_Font();

            /**
             * draw the text in a renderer(added during call of contructor)
             */
            void Draw();

            /**
             * set a new position for the text
             * \param x the x coordinate
             * \param y the y coordinate
             */
            void set_pos(int x, int y);

            /**
             * change the text color
             * \param color new text color
             */
            void set_color(SDL_Color color);

            /**
             * change the text color
             * \param r the red proportion
             * \param g the green proportion
             * \param b the blue proportion
             * \param a the alpha proportion, which is transparence don't forget to call `SDL_SetRenderDrawBlendMode` to change the alpha option
             */
            void set_color(int r, int g, int b, int a);

            /**
             * change the background color
             * /!\ used only with LCD rendering (you can set a transperent color)
             * \param color new text color
             */
            void set_bg_color(SDL_Color color);

            /**
             * change the background color
             * /!\ used only with LCD rendering (you can set a transperent color)
             * \param r the red proportion
             * \param g the green proportion
             * \param b the blue proportion
             * \param a the alpha proportion, which is transparence don't forget to call `SDL_SetRenderDrawBlendMode` to change the alpha option
             */
            void set_bg_color(int r, int g, int b, int a);

            /**
             * change the font used to render the text
             * /!\ the text class just use the font but you have to open and free it outside of the class
             * \param new_font the new font used to render the text
             */
            void change_font(TTF_Font* new_font);

            /**
             * change the message of the text
             * \param message the new message
             */
            void set_message(std::string message);

            /**
             * to know if a flag is in the flags int you just have to check the condition: (flags | YOUR_FLAG)
             * \return the actual int where all the flag are stored
             */
            int Get_flags();

            /**
             * you can add flag wich are:
             * - `BUTTON_ISCLICK_COLOR` when button is click the bg change color
             * \param flag one flag or more OR together (ex: FLAG1 | FLAG2)
             */
            void add_flag(int flag);

            /**
             * you can remove flag wich are:
             * - `BUTTON_ISCLICK_COLOR` when button is click the bg change color
             * \param flag one flag or more OR together (ex: FLAG1 | FLAG2)
             */
            void remove_flag(int flag);

            /**
             * this is function to update the texture, it is alredy call when we need to use it so don't use it
             */
            void _LoadTexture();
        protected:
            SDL_Renderer* renderer;
            TTF_Font* font;
            std::string message = "";
            SDL_Texture* texture = nullptr;
            SDL_Rect rect = {0,0,0,0};
            unsigned int flags = TEXT_SOLID;
            SDL_Color text_color = {255,255,255,255};
            SDL_Color bg_color = {0,0,0,255}; // used only with TEXT_LCD
            
    };

    class TextZone : public Text
    {
        using Text::Text;

        public:
            void change_zone_size(int w, int h);
            void change_zone_pos(int x, int y);
            void add_typed_chars(SDL_Event event);
            void _LoadTexture();
            void Draw();
        private:
            SDL_Rect zone_rect = {0,0,0,0};
            std::string::iterator cursor = message.begin();
    };
}

#endif