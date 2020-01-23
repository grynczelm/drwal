#include "window.hpp"
#include "menu.hpp"
#include "drwal.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();

    getmaxyx(stdscr, yMax, xMax);

    refresh();

    mainWin = Window(20, xMax/2, yMax/5, xMax/4).getWindow();
    menuWin = Window(3, (xMax/2)-2, (yMax/5)-1, (xMax/4)+1).getWindow();

    Window dataObj;
    dataObj = Window(17, (xMax/2)-2, (yMax/5)+2, (xMax/4)+1);

    dataWin = dataObj.getWindow();

    Menu menu = Menu(dataObj.getSize());

    menu.add("Zlecenia");
    menu.add("Awarie");
    menu.add("Magazyn");
    menu.add("Zmiany");

    //menu.add("Zlecenia", new Zlecenie());
    //menu.add("Awarie", new Awarie());
    //menu.add("Magazyn", new Magazyn());
    //menu.add("Zmiany", new Zmiany());

    menuSize = menu.getSize();

    Window menuZlecenia = Window(15, (xMax/2)-4, (yMax/5)+3, (xMax/4)+2, false);
    menuZlecenia.draw("Menu zleceń");
    
    Window menuAwarie = Window(15, (xMax/2)-4, (yMax/5)+3, (xMax/4)+2, false);
    menuAwarie.draw("Świetne menu awarii");
    
    Window menuMagazyn = Window(15, (xMax/2)-4, (yMax/5)+3, (xMax/4)+2, false);
    menuMagazyn.draw("Obsługa stanów magazynowych");
    
    Window menuZmiany = Window(15, (xMax/2)-4, (yMax/5)+3, (xMax/4)+2, false);
    menuZmiany.draw("Dzień dobry, Pracowniku!");

    vector<Window> menus = {menuZlecenia, menuAwarie, menuMagazyn, menuZmiany};

    keypad(menuWin, true);
    keypad(dataWin, true);
    curs_set(0);

    chosen = 0;
    Window lastData = menus[0];

    while (TRUE) {
        unsigned short overallLength = 2;

        lastData.render();

        for (unsigned short i=0; i<menuSize; ++i) {
            if (chosen == i)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, 1, overallLength, menu.getTitle(i).c_str());
            overallLength += menu.getTitle(i).length()+4;
            wattroff(menuWin, A_REVERSE);
        }

        wrefresh(menuWin);
        pressedKey =  wgetch(menuWin);
        
        
        if (pressedKey == KEY_RIGHT && chosen < (menuSize-1))
            ++chosen;
        if (pressedKey == KEY_LEFT && chosen > 0)
            --chosen;
        
        if (pressedKey == '\t') {
            if (chosen == (menuSize-1)) {
                chosen = 0;
            } else {
                ++chosen;
            }
        }
        
        if (pressedKey == KEY_RIGHT || pressedKey == KEY_LEFT || pressedKey == '\t') {
            delwin(lastData.getWindow());
            lastData = menus[chosen];
        }

        if (pressedKey == 'q')
            break;
    }

    //getch();
    endwin();

    return 0;
}
