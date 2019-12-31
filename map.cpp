#include "map.hpp"

Map::Map(){};
void Map::print_map()
{
    for(int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            std::cout << _map [i][j];
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
    draw(_eat_x,_eat_y,'e');
}
void Map::init_eat()
{
    Eat n;
    draw(n.x,n.y,'o');
    _eat_x = n.x;
    _eat_y = n.y;
}

void Map::lose()
{
        std::cout << ("    #    ##### ###### #####") << std::endl;
        std::cout << ("   #    #   # #      #    ") << std::endl;
        std::cout << ("  #    #   # ###### #####") << std::endl;
        std::cout << (" #    #   #      # #    ") << std::endl;
        std::cout << ("#### ##### ###### #####") << std::endl;
}