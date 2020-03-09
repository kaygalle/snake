#ifndef START_HPP
#define START_HPP
#include <iostream>


#include "map.hpp"
#include "snake.hpp"

class Start
{
    public:
        Start();
        Map m;
        bool check(Map m);
        void game();
};
#endif
