#include <stdio.h>
#include <curses.h>
#include <iostream>

#include "map.hpp"
#include "snake.hpp"
bool check( Map m)
{
    if(m._snake._pos[0].x == 0 || m._snake._pos[0].x == _width || m._snake._pos[0].y == 0 || m._snake._pos[0].y == _height)
    {
        return false;
    }
    return true;
}
int main()
{
    Map m;
    char r;
    int _begin = 0;
    while(check(m))
    {
        initscr();
	    raw();
	    keypad(stdscr, TRUE);
	    noecho();
        do
        {
            r=getch();
            m._snake.controller(r);
            m.make_borders();    
            m.draw_snake();
            m.draw_eat();
            if((m._eat_x == m._snake._pos[0].x && m._eat_y == m._snake._pos[0].y)|| _begin == 0)
            {
                m.init_eat();
                if(_begin != 0)
                {
                    m._snake.plus();
                }
                _begin = 1;
            }
            m._snake.move();
            m.print_map();
            if(r=='m')
            {
                break;
            }
        }
        while(r!=int('q'));
        endwin();
    }
    m.lose();
}