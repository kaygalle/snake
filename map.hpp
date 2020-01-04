#ifndef MAP_HPP
#define MAP_HPP

#define _height 10
#define _width 30

#include <iostream>

#include "snake.hpp"

class Map
{
    public:
    Map();
    Snake _snake;
    int _eat_x;
    int _eat_y;
    void make_borders();
    void print_map();
    void draw(int x, int y, char symbol);
    void draw_snake();  
    void init_eat();
    void draw_eat();
    void lose();  
    private:
    char _map [_height][_width];
};
class Eat: Map
{
    public:
    int x;
    int y;
    Eat()
    {
        init_eat();
    };
    void init_eat()
    {
        x = (rand() * time(0)) % (_width-2)+1;
        y = (rand() * time(0)) % (_height-2)+1;
        for(size_t i = 0; i <_snake._pos.size(); i++)
        {
            if(_snake._pos[i].x == x && _snake._pos[i].y == y)
            {
                init_eat();
            }
        }
    };
};
#endif
