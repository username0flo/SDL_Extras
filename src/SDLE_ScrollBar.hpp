#ifndef _SCROLLBAR_
#define _SCROLLBAR_

#include <iostream>
#include <SDL.h>
#include "SDL_Extras.hpp"

#define SCROLL_INT_MODE 0
#define SCROLL_FLOAT_MODE 1


namespace SDL_E
{
    union flin_value
    {
        int i_value;
        float f_value;
    };

    class ScrollBar
    {
        public:
            ScrollBar() = default;

            ScrollBar(int mode, int start, int step, int nb_vals);

            ScrollBar(int start, int step, int nb_vals);

            void change_mode(int mode);

            void set_pos(int x, int y);

            void set_size(int w, int h);

            void set_ratio(double ratio);
            
            void Draw(SDL_Renderer* renderer);

            void set_value(int value);

            void set_value(float value);

            void set_start(int start);

            void set_step(int step);

            void set_end(int end);

            int get_mode();

            flin_value get_value();
            
            void modify(SDL_Event event);


        private:
            int start = 0;
            int step = 1;
            int nb_vals;
            double circle_ratio = 4/3;
            int mode = SCROLL_INT_MODE;
            SDL_Rect bar = {10,10,100,5};
            flin_value value;

    };
}

#endif