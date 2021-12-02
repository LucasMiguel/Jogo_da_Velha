#include <iostream>
#include "curses.h"
#include "include/templates.h"
#include "include/macros.h"

namespace Templates {

    /**
     * @brief Função com a tela de boas vinda ao jogo
     */
    void startMessage()
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
                std::cout << "\t\t================ ################### ================" << std::endl;
                std::cout << "\t\t                    JOGO DA VELHA                    "  << std::endl;
                std::cout << "\t\t================ ################### ================\n\n" << std::endl;
                break;
            case 2:
                mvaddstr(0,2, "\t\t================ ################### ================");
                mvaddstr(1,2, "\t\t                    JOGO DA VELHA                    ");
                mvaddstr(2,2, "\t\t================ ################### ================\n\n");
                break;
        }
    }

    /**
     * @brief Função com a tela de vitório
     */
    void victoryMensage(const std::string &player)
    {
        std::string line = "\t" + player;
        initscr();
        int half_lines = ((LINES - 1))/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        header(2);
        mvaddstr( 4, (half_lines+12), "================ XXXXX ==================");
        mvaddstr( 5, (half_lines+12), "||--------------       ----------------||");
        mvaddstr( 6, (half_lines+12), "||                                     ||");
        mvaddstr( 7, (half_lines+12), "||             PARABENS !!!!           ||");
        mvaddstr( 8, (half_lines+12), "||                                     ||");
        mvaddstr( 9, (half_lines+12), "||--------------       ----------------||");
        mvaddstr( 10,(half_lines+12), "================ OOOOO ==================");
        mvaddstr( 13,(half_lines+12), "          VITORIA DO JOGADOR             ");
        mvaddstr( 14, (half_lines+12), line.c_str());
        mvaddstr((LINES - 4), 0,"\t\t         Pressione [Enter] para continuar ... ");
        endwin();
    }

    /**
     * @brief Função com a tela de vitório
     */
    void drawMensage()
    {
        initscr();
        int half_lines = ((LINES - 1))/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        header(2);
        mvaddstr( 4, (half_lines+12), "================ XXXXX ==================");
        mvaddstr( 5, (half_lines+12), "||--------------       ----------------||");
        mvaddstr( 6, (half_lines+12), "||                                     ||");
        mvaddstr( 7, (half_lines+12), "||             QUE PENA !!!!           ||");
        mvaddstr( 8, (half_lines+12), "||                                     ||");
        mvaddstr( 9, (half_lines+12), "||--------------       ----------------||");
        mvaddstr( 10,(half_lines+12), "================ OOOOO ==================");
        mvaddstr( 13,(half_lines+12), "             FICOU EMPATADO              ");
        mvaddstr((LINES - 4), 0,"\t\t         Pressione [Enter] para continuar ... ");
        endwin();
    }


    /**
     * @brief Função com os dados de navegação do MENU
     */
    void footerInfoMenu(){
        mvaddstr((LINES - 2), 2, "\t\tUse [W, S] para navegar || [ENTER] para selecionar");
        mvaddstr((LINES - 1), 2, "\t    Powered by Lucas Miguel - https://github.com/LucasMiguel ");
    }
    /**
     * @brief Função com os dados de navegação do MENU
     */
    void footerInfoTable(){
        mvaddstr((LINES - 2), 2, "\t\tUse [W, S, A, D] para navegar || [ENTER] para selecionar");
        mvaddstr((LINES - 1), 2, "\t    Powered by Lucas Miguel - https://github.com/LucasMiguel ");
    }


}
