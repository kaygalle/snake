#include <iostream>
#include "menu.hpp"
#include "start.hpp"
int main()
{
    Menu menu;
    menu.init_menu();
    menu.print_menu();
    int t = menu.move_arrow();
    if(t == 0)
    {
        Start start;
        start.game();
    }
    else
    if(t == -1)
    {
        t=menu.move_arrow();
    }
    else
    if(t == 1)
    {
    }
}
