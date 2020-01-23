#ifndef MENU_H_FILE
#define MENU_H_FILE

#include "includes.hpp"

using namespace std;

class Menu
{
    private:
        vector<string> options;
        vector<unsigned short> m_Sizes;
    public:
        Menu(vector<unsigned short>);
        string getTitle(unsigned short);
        void add(string);
        unsigned short getSize();
};

#endif
