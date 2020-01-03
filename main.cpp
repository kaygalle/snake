#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>            
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "map.hpp"
#include "snake.hpp"
bool check( Map m)
{
    if(m._snake._pos[0].x == 0  || m._snake._pos[0].x == _width-1 || m._snake._pos[0].y == 0 || m._snake._pos[0].y == _height-1)
    {
        return false;
    }
    return true;
}
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
int main()
{
    Map m;
    int c=65;
    int _begin = 0;
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    newt.c_lflag &= ~ECHO;
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    time_t timer1;
    time_t timer2;
    while(check(m))
    {   
        time(&timer1);
        if(kbhit()==1)
        {    
            c=getchar();
            if(c == 'q')
                exit(1);
        }
        m._snake.controller(c);
        if(difftime(timer1, timer2) > 0.00003)
        {
             time(&timer2);
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
            
            if(c=='m')
            {
                break;
            }
        }
            system("clear");

        m.print_map();
    }
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    m.lose();

}
