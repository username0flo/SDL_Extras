#ifndef _PROGRESS_BAR_
#define _PROGRESS_BAR_

#include <iostream>
#include <SDL.h>
#include "SDL_Extras.hpp"

namespace SDL_E
{
    /**
     * a simple progress bar (like a loading bar) class
     */
    class ProgressBar
    {
        public:
            ProgressBar() = default;

            /**
             * \param start the minimum value (starting value)
             * \param end the maximum value (ending value)
             */
            ProgressBar(int start, int end);

            /**
             * \param start the minimum value (starting value)
             * \param end the maximum value (ending value)
             * \param width the with of the bar (in pixels)
             */
            ProgressBar(int start, int end, int width);
        
            /**
             * set the bar to a x and y position
             * \param x the x coordinate
             * \param y the y coordinate
             */
            void set_pos(int x, int y);

            /**
             * set a new size to your bar
             * \param w the width (in pixels)
             * \param h the height (in pixels)
             */
            void set_size(int w,int h);

            /**
             * set a new color to the ouline of the bar
             * \param color the new color (an SDl struct composed by r, g, b and a values)
             */
            void set_outline_color(SDL_Color color);

            /**
             * set a new color to the bar
             * \param color the new color (an SDl struct composed by r, g, b and a values)
             */
            void set_color(SDL_Color color);

            /**
             * set an end value (the maximum of the bar)
             * \param end the end value (= maximum value)
             */
            void set_end(int end);

            /**
             * set an start value (the minimum of the bar)
             * \param start the start value (= minimum value)
             */
            void set_start(int start);

            /**
             * set a new value to the bar
             * \param value a float values between start and end
             */
            void set_value(float value);

            /**
             * \return the actual progress bar value
             */
            float get_value();

            /**
             * \return the position in a SDL_Point struc with a x field and a y field
             */
            SDL_Point get_pos();

            /**
             * \return the size in a SDL_Point struc with a x field (the width) and a y field (the height)
             */
            SDL_Point get_size();

            /**
             * draw the bar 
             * \param renderer the rendering context
             */
            void Draw(SDL_Renderer* renderer);

        private:
            SDL_Color outline_color = {200,200,200,255};
            SDL_Color color = {20,255,60,255};
            SDL_Rect rect = {0,0,100,20};
            int start = 0;
            int end = 10;
            float value = (float)4.0;
    };
}


#endif