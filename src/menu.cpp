#include <iostream>
#include <string>
#include <ncurses.h>
#include "include/menu.h"
#include "include/templates.h"
#include "include/macros.h"


namespace Menu {
    /**
     * @brief Função que irá exibir o menu.
     */
    void Menu::printMenu(){
        //Exibe o menu no modo de ncurse
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        Templates::header(2);
        for (int i=0; i<QUANT_ITENS_MENU;i++){
            mvaddstr(9 + i, 17, (m_menu_list[i][0] == "1"? "=>": "  "));
            mvaddstr(9 + i, 20, m_menu_list[i][1].c_str());
        }
        Templates::footerInfoMenu();
        endwin();
    }

    /**
     * @brief Função que irá retornar o valor da linha do item que está selecionado.
     */
    int Menu::getLineSelectMenu(){

        for (int i=0; i < QUANT_ITENS_MENU;i++){
            if(stoi(m_menu_list[i][0]) == 1){
                return i;
            }
        }
        return 0;
    }

    /**
     * @brief Limpa todas as seleções do item do menu.
     */
    void Menu::cleanMenu(){
        for (int i=0; i < QUANT_ITENS_MENU;i++){
            m_menu_list[i][0] = "0";
        }
    }

    /**
     * @brief Seleciona o novo item do menu.
     */
    void Menu::setLine(int line){
        m_menu_list[line][0] = "1";
    }


    /**
     * @brief Função para mudança da linha
     */
    void Menu::changeLine(const int &key){
        int selectedLine = 0;
        if(key == UP_KEY || key == DOWN_KEY){
            int command = (key == UP_KEY?UP:DOWN);
            selectedLine = getLineSelectMenu();
            cleanMenu();
            int newLine = command + selectedLine;
            setLine(newLine < 0 || newLine > (QUANT_ITENS_MENU-1)? selectedLine: newLine);
        }
        return;
    }
}


