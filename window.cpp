#include "window.hpp"

Window::Window()
{

}

Window::Window(unsigned short height, unsigned short width, unsigned short startY, unsigned short startX, bool renderBox)
{
    w_height = height;
    w_width = width;
    w_startY = startY;
    w_startX = startX;
    w_renderBox = renderBox;

    render();
}

vector<unsigned short> Window::getSize()
{
    return vector<unsigned short>{w_height, w_width, w_startY, w_startX};
}

WINDOW * Window::getWindow()
{
    return window;
}

void Window::draw(const char* text)
{
    someText = text;
}

void Window::render()
{
    window = newwin(w_height, w_width, w_startY, w_startX);
    if (w_renderBox)
        box(window, 0, 0);
    wrefresh(window);

    mvwprintw(window, 1, 1, someText.c_str());
    wrefresh(window);
}
