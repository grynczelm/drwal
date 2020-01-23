#include "window.hpp"
#include "drwal.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();

    getmaxyx(stdscr, yMax, xMax);

    string choices[4] = {"Zlecenia", "Awarie", "Magazyn", "Zmiany"};
    choicesSize = sizeof(choices) / sizeof(choices[0]);
    refresh();

    mainWin = Window(20, xMax/2, yMax/5, xMax/4).getWindow();
    menuWin = Window(3, (xMax/2)-2, (yMax/5)-1, (xMax/4)+1).getWindow();
    dataWin = Window(17, (xMax/2)-2, (yMax/5)+2, (xMax/4)+1).getWindow();

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
    curs_set(0);

    chosen = 0;
    Window lastData = menus[0];

    while (TRUE) {
        unsigned short overallLength = 2;

        lastData.render();

        for (unsigned short i=0; i<choicesSize; ++i) {
            if (chosen == i)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, 1, overallLength, choices[i].c_str());
            overallLength += choices[i].length()+4;
            wattroff(menuWin, A_REVERSE);
        }

        wrefresh(menuWin);
        pressedKey =  wgetch(menuWin);
        
        
        if (pressedKey == KEY_RIGHT && chosen < (choicesSize-1))
            ++chosen;
        if (pressedKey == KEY_LEFT && chosen > 0)
            --chosen;
        
        if (pressedKey == '\t') {
            if (chosen == (choicesSize-1)) {
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
