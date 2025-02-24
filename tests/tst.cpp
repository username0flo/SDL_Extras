#include <iostream>

int main()
{
    union flin
    {
        int i;
        float f;
    };

    flin num;
    num.i = 10;
    std::cout << num.i << std::endl;

    num.f = 3.1415;

    std::cout << num.f << std::endl;


    return 0;
}