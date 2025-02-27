#ifndef _SCROLLBAR_
#define _SCROLLBAR_

#include <iostream>
#include <SDL.h>
#include "SDL_Extras.hpp"

#define SCROLL_INT_MODE 0
#define SCROLL_FLOAT_MODE 1


namespace SDL_E
{
    /**
     * a simple union of a flaot and an int used in the ScrollBar class
     */
    union flin_value
    {
        int i_value;
        float f_value;
    };

    /**
     * a scroll bar widget class that can be used in two mods:
     * - first, the step int mod:
     *  it's a basic scroll bar wih defined values spaced by a step value, when you move the scroll the selector goes to a defined value
     * it is define by a stazrt value, a step between each value and the nuber of steps in the bar
     * (for example : a bar start at 2 with a step of 3 and 4 values haves these defined values: [2,5,8,11])
     * this mode is associated with the flag `SCROLL_INT_MODE` (it is the default mode)
     * - also there is the float mode scroll bar:
     * in this case the scroll bar have a value related to its position in the bar 
     * it is defined by a start value and a end value (it is the same variable as nb_val)
     * this mode is associated with the flag `SCROLL_FLOAT_MODE`
     */
    class ScrollBar
    {
        public:
            ScrollBar() = default;

            /**
             * \param mode an flag designed the mode, it can be: `SCROLL_FLOAT_MODE` or `SCROLL_INT_MODE` (default is int mode)
             * \param start the start value of the srcoll bar
             * \param step the size of the step between values in th scroll bar (no useful in float mode)
             * \param nb_vals the numbers of values spaced by step in int mode or he end value in float mode
             */
            ScrollBar(int mode, int start, int step, int nb_vals);

            /**
             * \param start the start value of the srcoll bar
             * \param step the size of the step between values in th scroll bar (no useful in float mode)
             * \param nb_vals the numbers of values spaced by step in int mode or he end value in float mode
             */
            ScrollBar(int start, int step, int nb_vals);

            /**
             * change the mode used by the srcoll bar it can be:
             * - the step int mod:
             *  it's a basic scroll bar wih defined values spaced by a step value, when you move the scroll the selector goes to a defined value
             * it is define by a stazrt value, a step between each value and the nuber of steps in the bar
             * (for example : a bar start at 2 with a step of 3 and 4 values haves these defined values: [2,5,8,11])
             * this mode is associated with the flag `SCROLL_INT_MODE` (it is the default mode)
             * - the float mode scroll bar:
             * in this case the scroll bar have a value related to its position in the bar 
             * it is defined by a start value and a end value (it is the same variable as nb_val)
             * this mode is associated with the flag `SCROLL_FLOAT_MODE`
             * \warning when you change to an another mode a part of the value you have set have not the same signification
             * it recomanded to re initialize new values
             * \param mode the mode flag, it can be `SCROLL_INT_MODE` or `SCROLL_FLOAT_MODE`
             */
            void change_mode(int mode);

            /**
             * change the position of your bar
             * \param x the x coordinate
             * \param y the y coordinate
             */
            void set_pos(int x, int y);

            /**
             * change the size of your bar
             * \param w the width
             * \param h the height
             */
            void set_size(int w, int h);

            /**
             * change the size of the circle (wich is the selector)
             * \param ratio the ratio of the diameter of the circle by the bar height
             * (example: a ratio of 1.5 the circle is 1.5 bigger than the bar height)
             */
            void set_ratio(double ratio);
            
            /**
             * draw your scroll bar in a rendering context
             * \param renderer th rendering context
             */
            void Draw(SDL_Renderer* renderer);

            /**
             * set a value to the scroll bar 
            */
            void set_value(int value);

            /**
             * set a value to the scroll bar 
            */
            void set_value(float value);

            /**
             * set the start value
             * \param start the start value
            */
            void set_start(int start);

            /**
             * set the step value
             * \param step the step value
             * \warning this method is used only with `SCROLL_INT_MODE`
            */
            void set_step(int step);

            /**
             * set the end value
             * \param end the end value
             * \warning this value is the end value with `SCROLL_FLOAT_MODE` and the number of values separated by steps in `SCROLL_INT_MODE`
            */
            void set_end(int end);

            /**
             * \return the mode of the scroll bar
             */
            int get_mode();

            /**
             * \return the vqalue of the scroll bar
             * \warning this methos return an union of float and int with repectively i_value and f_value field
             */
            flin_value get_value();

            SDL_Rect get_rect();

            int get_start();

            int get_step();

            int get_end();

            int get_circle_x();

            int get_circle_y();

            int get_circle_radius();
            
            /**
             * this method update the state of the scroll bar
             * you must call this method in your event gestionary
             * \param event the current `SDL_Event` struct
             */
            void Update(SDL_Event event);

        private:
            int start = 0;
            int step = 1;
            int nb_vals;
            double circle_ratio = 4.0/3.0;
            int mode = SCROLL_INT_MODE;
            bool is_hold = false;
            SDL_Rect bar = {10,10,100,5};
            flin_value value;

    };
}

SDL_E::flin_value _update_value(SDL_E::ScrollBar& srllbar, int mousex);
#endif