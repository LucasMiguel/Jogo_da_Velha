#include <iostream>
#include "ncurses.h"
#include "include/templates.h"
#include "include/macros.h"

namespace Templates {

    /**
     * @brief Função com a tela de boas vinda ao jogo
     */
    void start_message()
    {
        initscr();
        int half_lines = ((LINES - 1))/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        mvaddstr( 1, (half_lines+12), "============== XXXXX ================");
        mvaddstr( 2, (half_lines+12), "||------------       --------------||");
        mvaddstr( 3, (half_lines+12), "||                                 ||");
        mvaddstr( 4, (half_lines+12), "||                                 ||");
        mvaddstr( 5, (half_lines+12), "||            Bem Vindo            ||");
        mvaddstr( 6, (half_lines+12), "||         Ao jogo da velha!!      ||");
        mvaddstr( 7, (half_lines+12), "||                                 ||");
        mvaddstr( 8, (half_lines+12), "||                                 ||");
        mvaddstr( 9, (half_lines+12), "||------------       --------------||");
        mvaddstr( 10,(half_lines+12), "============== OOOOO ================");
        mvaddstr((LINES - 4), 0,"\t\t         Pressione [Enter] para continuar ... ");
        endwin();
    }

    /**
     * @brief Função com o cabeçalho das telas
     * @param choise - Indica qual o tipo de impressão | 1 = cout | 2 = ncurse
     */
    void header(const int &choise)
    {
        switch (choise) {
            case 1:
                std::cout << "\t\t========= ################### ============= " << std::endl;
                std::cout << "\t\t             JOGO DA VELHA                  " << std::endl;
                std::cout << "\t\t========= ################### ============= \n\n" << std::endl;
                break;
            case 2:
                mvaddstr(1,2, "\t\t================ ################### ================");
                mvaddstr(2,2, "\t\t----------------                     ----------------");
                mvaddstr(3,2, "\t\t                    JOGO DA VELHA                    ");
                mvaddstr(4,2, "\t\t----------------                     ----------------");
                mvaddstr(5,2, "\t\t================ ################### ================\n\n");
                break;
        }
    }
    /**
     * @brief Função com os dados de navegação do MENU
     */
    void footerInfoMenu(){
        mvaddstr((LINES - 2), 2, "\t\tUse [W, A, S, D] para navegar e [ENTER] para selecionar");
        mvaddstr((LINES - 1), 2, "\t\t             Powered by Lucas Miguel                   ");
    }


}
