#ifndef START_HPP
#define START_HPP
#include <iostream>

#include <stdio.h>
#include <cstdlib>
#include <termios.h>            
#include <unistd.h>
#include <fcntl.h>
#include "map.hpp"
#include "snake.hpp"
#include <algorithm>        

class Start
{
    public:
        Start();
        Map m;
        int kbhit();
        bool check(Map m);
        void game();
};
#endif
