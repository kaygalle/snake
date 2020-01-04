#include "snake.hpp"
void Snake::moveDOWN()
{
    for(int i = _pos.size()-1; i > 0; i--)
    {
        _pos[i].x = _pos[i-1].x;
        _pos[i].y = _pos[i-1].y;
    }
    _pos[0].y++;
}
void Snake::moveUP()
{
    for(int i = _pos.size()-1; i > 0; i--)
    {
        _pos[i].x = _pos[i-1].x;
        _pos[i].y = _pos[i-1].y;
    }
    _pos[0].y--;
}
void Snake::moveLEFT()
{
    for(int i = _pos.size()-1; i > 0; i--)
    {
        _pos[i].x = _pos[i-1].x;
        _pos[i].y = _pos[i-1].y;
    }
    _pos[0].x--;
}
void Snake::moveRIGHT()
{
    for(int i = _pos.size()-1; i > 0; i--)
    {
        _pos[i].x = _pos[i-1].x;
        _pos[i].y = _pos[i-1].y;
    }
    _pos[0].x++;
}
void Snake::controller(int key)
{
    switch (key)
    {
    case 97:
        direction = Left;
        break;
    case 65:
        direction = Left;
    case 119:
        direction = Up;
        break;
    case 87:
        direction = Up;
        break;
    case 115:
        direction = Down;
        break;
    case 83:
        direction = Down;
        break;
    case 100:
        direction = Right;
        break;
    case 68:
        direction = Right;
        break;
    default:
        break;
    }
}
void Snake::plus()
{
    Point n (_pos[_pos.size()-1].x,_pos[_pos.size()-1].y);
        // _pos.push_back(n);
    if(direction == Up)
    {
        Point n (_pos[_pos.size()-1].x,_pos[_pos.size()-1].y+1);
        _pos.push_back(n);
    }
    else
    if(direction == Down)
    {
        Point n (_pos[_pos.size()-1].x,_pos[_pos.size()-1].y-1);
        _pos.push_back(n);
    }
    else
    if(direction == Left)
    {
        Point n (_pos[_pos.size()-1].x+1,_pos[_pos.size()-1].y);
        _pos.push_back(n);
    }
    else
    if(direction == Right)
    {
        Point n (_pos[_pos.size()-1].x-1,_pos[_pos.size()-1].y);
        _pos.push_back(n);
    }
}
void Snake::move()
{
    if(direction == Up)
    {
        usleep(200000);
        moveUP();
    }
    else
    if(direction == Down)
    {
        usleep(200000);
        moveDOWN();
    }
    else
    if(direction == Left)
    {
        usleep(160000);
        moveLEFT();
    }
    else
    if(direction == Right)
    {
        usleep(160000);
        moveRIGHT();
    }
}
