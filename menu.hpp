#ifndef MENU_HPP
#define MENU_HPP

#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <cstdlib>
#define _width 30
#define _height 10

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

class Menu
{
    public:
    Menu();
    int t=0;
    char _menu[_height][_width];
    std::string start = "#           >START<          #";
    std::string ex = "#            EXIT            #";
    void init_menu();
    void print_menu();    
    char getch();
    int  move_arrow();
};
#endif
