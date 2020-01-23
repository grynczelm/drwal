#include "menu.hpp"
#include "window.hpp"

Menu::Menu(vector<unsigned short> sizes)
{
    m_Sizes = sizes;
}

string Menu::getTitle(unsigned short number)
{
    return options.at(number);
}

void Menu::add(string value)
{
    options.push_back(value);
    // Window(15, (xMax/2)-4, (yMax/5)+3, (xMax/4)+2, false);
}

unsigned short Menu::getSize()
{
    return options.size();
}
