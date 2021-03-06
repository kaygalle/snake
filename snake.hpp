#ifndef SNAKE_HPP
#define SNAKE_HPP

#define _height 10
#define _width 30

#include <time.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "point.hpp"

class Snake
{
    public:
    enum direct
    {
        Up,
        Down,
        Right,
        Left
    };
    direct direction;
    std::vector <Point> _pos;
    Snake()
    {
        Point m(_width/2,_height/2);
        _pos.push_back(m);
    };
    void moveUP();
    void moveDOWN();
    void moveRIGHT();
    void moveLEFT();
    void move();
    void plus();
    void controller(int key);
};
#endif
