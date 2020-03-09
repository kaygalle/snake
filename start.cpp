#include "start.hpp"
#include "kbhit.hpp"

Start::Start(){};
bool Start::check(Map m)
{
    for(size_t i = 1; i < m._snake._pos.size(); i++)
    {
        if(m._snake._pos[0].x == m._snake._pos[i].x && m._snake._pos[0].y == m._snake._pos[i].y)
        {
            return false;
        }
    }
    if(m._snake._pos[0].x == 0  || m._snake._pos[0].x == _width-1 || m._snake._pos[0].y == 0 || m._snake._pos[0].y == _height-1)
    {
        return false;
    }
    return true;
}
//int Start::kbhit(void)
//{
//  struct termios oldt, newt;
//  int ch;
//  int oldf;
//
//  tcgetattr(STDIN_FILENO, &oldt);
//  newt = oldt;
//  newt.c_lflag &= ~(ICANON | ECHO);
//  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
//  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
//  ch = getchar();
//  if(ch != EOF)
//  {
//    ungetc(ch, stdin);
//    return 1;
//  }
//  return 0;
//}
void Start::game()
{
    int key;
    int prevkey;
    int _begin = 0;
    while(check(m))
    {   
        if(kbhit()==1)
        {   
            key=getchar();
        }
        if(key!=prevkey)
        {
            m._snake.controller(key);
        }
        prevkey=key;
        m.make_borders();
        m.draw_snake();
        if((m._eat_x == m._snake._pos[0].x && m._eat_y == m._snake._pos[0].y)|| _begin == 0)
        {
            m.init_eat();
            if(_begin != 0)
            {
                m._snake.plus();
            }
            _begin = 1;
        }
        m.draw_eat();
        m._snake.move();
        system("clear");
        m.print_map();
   }
   m.lose();
}
