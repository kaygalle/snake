#include "menu.hpp"
Menu::Menu()
{
    std::system("clear");
};
void Menu::print_menu()
{
    std::cout << YELLOW;
    for(int i = 0; i < _height; i++)
    {
        for(int j = 0; j < _width; j++)
        {
           if(i == 3)
           {
               std::cout << start;
               j=_width;
           }
           else
           if(i == 5)
           {
               std::cout << ex;
               j=_width;
           }
           else
           {
               std::cout << _menu[i][j];
           }
        }
        std::cout << std::endl;
    }
    std::cout << RESET;
}
void Menu::init_menu()
{
    for(int i = 0; i < _height; i++)
    {
        for(int j = 0; j < _width;j++)
        {
            if(i == 0 || j == 0 || i == _height-1 || j == _width - 1)
            {
                _menu[i][j]= '#';
            }
            else
            {
                _menu[i][j] = ' ';
            }
        }
    }
}
char Menu::getch() {
char buf = 0;
struct termios old = {0};
if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
old.c_lflag &= ~ICANON;
old.c_lflag &= ~ECHO;
old.c_cc[VMIN] = 1;
old.c_cc[VTIME] = 0;
if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
if (read(0, &buf, 1) < 0)
    perror ("read()");
old.c_lflag |= ICANON;
old.c_lflag |= ECHO;
if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror ("tcsetattr ~ICANON");
return (buf);
}
int Menu::move_arrow()
{
    char c = getch();
    if(c == 'w')
    {
        start = "#           >START<          #";
        ex    = "#            EXIT            #";
        t = 0;
        std::system("clear");
        print_menu();
        move_arrow();
    }
    else
    if(c == 's')
    {
        start = "#            START           #";
        ex    = "#           >EXIT <          #";
        t = 1;
        std::system("clear");
        print_menu();
        move_arrow();
    }
    else
    if(c == 10)
    {
        if(t == 1) 
        {
            return 1;
        }
        else
        if(t == 0)
        {
            return 0;
        }
    }
}
