#ifndef WINDOW_H_FILE
#define WINDOW_H_FILE

#include "includes.hpp"

using namespace std;

class Window
{
    private:
        WINDOW * window;
        unsigned short w_height, w_width, w_startY, w_startX;
        bool w_renderBox;
        
    public:
        string someText;

        Window(unsigned short height, unsigned short width, unsigned short startY, unsigned short startX, bool renderBox=true);

        WINDOW * getWindow();
        
        void draw(const char* text);

        void render();
};
#endif
