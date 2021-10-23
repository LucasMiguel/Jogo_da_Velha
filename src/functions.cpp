#include <iostream>
#include <ncurses.h>
#include "include/macros.h"

namespace Functions {

    /**
     * @brief Função para pegar o valor da tecla prescionada
     * @return o valor da tecla
     */
    int getKey(){
        Menu::Menu menu;
        //Variável com o valor da tecla clicada
        unsigned int key = 0;
        //Variável com o valor do comando escolhido
        int command = 0;
        /* Curses Initialisations */
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        key = getch();
        switch (key) {
            case W_KEY:
                command = UP;
                break;
            case UP_KEY:
                command = UP;
                break;
            case S_KEY:
                command =DOWN;
                break;
            case DOWN_KEY:
                command =DOWN;
                break;
            case A_KEY:
                command = LEFT;
                break;
            case LEFT_KEY:
                command = LEFT;
                break;
            case D_KEY:
                command = RIGHT;
                break;
            case RIGHT_KEY:
                command = RIGHT;
                break;
            case ESC_KEY:
                command = ESC_KEY;
                break;
            case ENTER_KEY:
                command = ENTER_KEY;
                break;
            default:
                command = 0;
                break;
        }
        endwin();
        return command;
    }
}
