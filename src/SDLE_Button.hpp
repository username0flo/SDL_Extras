#ifndef __SDLE_BUTTON__
#define __SDLE_BUTTON__

#include <iostream>
#include <SDL.h>
#include "SDLE_Text.hpp"
#include <vector>

#define BUTTON_ISCLICK_COLOR 0x00000001


namespace SDL_E
{
    class Button
    {
        public:
            Button() = default;
            Button(const Button& button);
            Button(Text text);
            Button(TTF_Font* font, SDL_Renderer* renderer, std::string message);
            Button(TTF_Font* font, SDL_Renderer* renderer, std::string message, int x, int y);
            Button(Text text, int x, int y);
            ~Button();

            void operator=(const Button& other);

            /**
             * \return the string that text show
             */
            std::string Get_message();

            /**
             * \return the color of the text
             */
            SDL_Color Get_txt_color();

            /**
             * \return the backgroud color of the button
             */
            SDL_Color Get_bg_color();

            /**
             * this fuction can be used to get the position or the size of the rectangle
             * \return the rectangle of the button
             */            
            SDL_Rect Get_rect();

            /**
             * to know if a flag is in the flags int you just have to check the condition: (flags | YOUR_FLAG)
             * \return the actual int where all the flag are stored
             */
            int Get_flags();

            /**
             * \return a SDL_Point with x = padx and y = pady
             */
            SDL_Point Get_pad();

            /**
             * set the padding(space between text and rectangle) of your button, by default it is to 5px
             * \param padx the padding in the x axis
             * \param pady the padding in the y axis 
             */
            void set_pad(int padx, int pady);

            /**
             * set a new position to the button
             * \param x the x coordinate
             * \param y the y coordinate
             */
            void set_pos(int x, int y);

            /**
             * change the text color
             * \param color new text color
             */
            void set_txt_color(SDL_Color color);

            /**
             * change the text color
             * \param r the red proportion
             * \param g the green proportion
             * \param b the blue proportion
             * \param a the alpha proportion, which is transparence don't forget to call `SDL_SetRenderDrawBlendMode` to change the alpha option
             */
            void set_txt_color(int r, int g, int b, int a);

            /**
             * change the background color
             * \param color new background color
             */
            void set_bg_color(SDL_Color color);

            /**
             * change the background color
             * \param r the red proportion
             * \param g the green proportion
             * \param b the blue proportion
             * \param a the alpha proportion, which is transparence don't forget to call `SDL_SetRenderDrawBlendMode` to change the alpha option
             */
            void set_bg_color(int r, int g, int b, int a);

            /**
             * change the font used to render the text
             * /!\ the button class just use the font but you have to open and free it outside of the class
             * \param new_font the new font used to render the text
             */
            void change_font(TTF_Font* new_font);

            /**
             * change the message of the text
             * \param message the new message
             */
            void set_message(std::string message);

            /**
             * draw the button in a renderer(added during call of contructor)
             */
            void Draw();

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

            void change_click_state(bool state);

            /**
             * get the state of the button (if is clicked or not)
             * you have to call buttons_clicked function to update the state of the button
             * you can also chage manualy this state with the method: change_click_state
             * caution a button is clicked until the mouse is up
             */
            bool clicked();

            // Do not work
            // /**
            //  * get the state of the button (if is just_clicked (during 1 frame) or not)
            //  * you have to call buttons_clicked function to update the state of the button
            //  * you can also chage manualy this state with the method: change_click_state
            //  */
            // bool just_clicked();
            

            void _UpdateRect();
        private:
            Text text;
            SDL_Rect rect = {0,0,0,0};
            SDL_Color bg_color = {255,0,0,255};
            int padx = 5;
            int pady = 5;
            bool is_click = false;
            // bool is_just_click = false; // can't use (same as click)
            int flag = BUTTON_ISCLICK_COLOR;
    };
    /**
     * a simple event gestionnary that check if buttons are clicked
     * this function have to be placed in the defalut event gestionnary (with SDL_Poll_Event)
     * \param event the actual event
     * \param buttons a std::vector containing buttons
     */
    void buttons_clicked(SDL_Event event, std::vector<Button> buttons);

    /**
     * a simple event gestionnary that check if buttons are clicked
     * this function have to be placed in the defalut event gestionnary (with SDL_Poll_Event)
     * \param event the actual event
     * \param buttons a C like array of buttons
     * \param nb_buttons the number of buttons in the array
     */
    void buttons_clicked(SDL_Event event, Button* buttons, int nb_buttons);

    /**
     * draw all the button in the vector buttons are drawed in the order of the buttons 
     * \param button a std::vector containing buttons
     */
    void draw_buttons(std::vector<Button> buttons);

    /**
     * draw all the button in the vector buttons are drawed in the order of the buttons  
     * \param buttons a C like array of buttons
     * \param nb_buttons the number of buttons in the array
    */
    void draw_buttons(Button* buttons, int nb_buttons);
}


#endif