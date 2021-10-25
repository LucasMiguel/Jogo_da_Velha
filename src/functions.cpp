#include <iostream>
#include <ncurses.h>
#include "include/macros.h"

namespace Functions {

    /**
     * @brief Função para pegar o valor da tecla prescionada
     * @return o valor da tecla
     */
    int getKey(){
        //Variável com o valor da tecla clicada
        unsigned int key = 0;
        //Variável com o valor do comando escolhido
        int command = 1;
        /* Curses Initialisations */
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        key = getch();
        switch (key) {
            case W_KEY:
                command = UP_KEY;
                break;
            case UP_KEY:
                command = UP_KEY;
                break;
            case S_KEY:
                command = DOWN_KEY;
                break;
            case DOWN_KEY:
                command = DOWN_KEY;
                break;
            case D_KEY:
                command = LEFT_KEY;
                break;
            case RIGHT_KEY:
                command = RIGHT_KEY;
                break;
            case LEFT_KEY:
                command = LEFT_KEY;
                break;
            case A_KEY:
                command = RIGHT_KEY;
                break;
            case ESC_KEY:
                command = ESC_KEY;
                break;
            case ENTER_KEY:
                command = ENTER_KEY;
                break;            
        }
        endwin();
        return command;
    }

    /**
     * @brief Função que limpa a tela
     */
    void cleanWindow(){
        initscr();
        clear();
        endwin();
    }
}
