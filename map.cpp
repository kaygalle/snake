#include "map.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define PINK    "\033[95m"      /* Gray */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

Map::Map(){};
void Map::print_map()
{
    for(int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            if(_map[i][j] == '*')
            {
                std::cout << GREEN << _map[i][j];
                std::cout << RESET;
            }
            else
            if(_map[i][j] == '@')
            {
                std::cout << PINK << _map[i][j];
                std::cout << RESET;
            }
            else
            {
                std::cout << RED <<  YELLOW << _map [i][j];
                std::cout << RESET;
            }
        }
        std::cout << std::endl;
    }
}
void Map::make_borders()
{
    for(int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            if(i == 0 || i == _height-1 || j == 0 || j == _width -1)
            {
                _map[i][j] = '#';
            }
            else
            {
               _map[i][j] = ' ';
            }
        }
    }
}
void Map::draw(int x,int y,char _symbol)
{
    for(int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            if(i == y && j == x)
            {
                _map[i][j] = _symbol;
            }
        }
    }
}
void Map::draw_snake()
{
    for(size_t i = 0; i < _snake._pos.size(); i++)
    {
        draw(_snake._pos[i].x,_snake._pos[i].y,'*');
    }
}
void Map::draw_eat()
{
    draw(_eat_x,_eat_y,'@');
}
void Map::init_eat()
{
    Eat n;
    draw(n.x,n.y,'@');
    _eat_x = n.x;
    _eat_y = n.y;
}

void Map::lose()
{
        std::cout << RED;
        std::cout << std::endl;
        std::cout << ("    #    ##### ###### #####") << std::endl;
        std::cout << ("   #    #   # #      #    ") << std::endl;
        std::cout << ("  #    #   # ###### #####") << std::endl;
        std::cout << (" #    #   #      # #    ") << std::endl;
        std::cout << ("#### ##### ###### #####") << std::endl;
}
