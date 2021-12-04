#include <iostream>
#include <ncurses.h>
#include "include/templates.h"
#include "include/macros.h"
#include "include/table.h"

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
    void victoryMensage(const std::string &player, int symbol, std::string values[][3])
    {
        std::string line =  "||       _____|_____|_____       ||\t\t  "+ player + (symbol == X? " [X] ": " [O] ");
        std::string row1 =  "||        "+values[0][0]+"  | "+values[0][1]+"  | "+values[0][2]+"         || ||                           ||";
        std::string row2 =  "||        "+values[1][0]+"  | "+values[1][1]+"  | "+values[1][2]+"         || ||                           ||";
        std::string row3 =  "||        "+values[2][0]+"  | "+values[2][1]+"  | "+values[2][2]+"         || ||                           ||";

        initscr();
        int half_lines = ((LINES - 1))/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        header(2);
        mvaddstr( 4, (half_lines),  "============== XXXXX ==============");
        mvaddstr( 5, (half_lines),  "||------------       ------------|| ||---------- XXXX -----------||");
        mvaddstr( 6, (half_lines),  "||                               || ||         PARABENS          ||");
        mvaddstr( 7, (half_lines),  "||            |     |            || ||---------- OOOOO ----------||");
        mvaddstr( 8, (half_lines),  row1.c_str());
        mvaddstr( 9, (half_lines),  "||       _____|_____|_____       || ||          VITORIA          ||");
        mvaddstr( 10, (half_lines), "||            |     |            || ||         DO JOGADOR        ||");
        mvaddstr( 11, (half_lines), row2.c_str());
        mvaddstr( 12, (half_lines), line.c_str());
        mvaddstr( 13, (half_lines), "||            |     |            || ||                           ||");
        mvaddstr( 14, (half_lines), row3.c_str());
        mvaddstr( 15, (half_lines), "||            |     |            || ||                           ||");
        mvaddstr( 16, (half_lines), "||                               || ||                           ||");
        mvaddstr( 17, (half_lines), "||------------       ------------|| ||                           ||");
        mvaddstr( 18, (half_lines), "============== OOOOO ===============================================");
        mvaddstr((LINES - 4), 0,"\t\t         Pressione [Enter] para continuar ... ");
        endwin();
    }

    /**
     * @brief Função com a tela de vitório
     */
    void drawMensage(std::string values[][3])
    {
        std::string row1 =  "||        "+values[0][0]+"  | "+values[0][1]+"  | "+values[0][2]+"         || ||                           ||";
        std::string row2 =  "||        "+values[1][0]+"  | "+values[1][1]+"  | "+values[1][2]+"         || ||                           ||";
        std::string row3 =  "||        "+values[2][0]+"  | "+values[2][1]+"  | "+values[2][2]+"         || ||                           ||";
        initscr();
        int half_lines = ((LINES - 1))/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        header(2);
        mvaddstr( 4, (half_lines),  "============== XXXXX ==============");
        mvaddstr( 5, (half_lines),  "||------------       ------------|| ||---------- XXXX -----------||");
        mvaddstr( 6, (half_lines),  "||                               || ||         QUE PENA          ||");
        mvaddstr( 7, (half_lines),  "||            |     |            || ||---------- OOOOO ----------||");
        mvaddstr( 8, (half_lines),  row1.c_str());
        mvaddstr( 9, (half_lines),  "||       _____|_____|_____       || ||          ACABOU           ||");
        mvaddstr( 10, (half_lines), "||            |     |            || ||        EM EMPATE          ||");
        mvaddstr( 11, (half_lines), row2.c_str());
        mvaddstr( 12, (half_lines), "||       _____|_____|_____       || ||                           ||");
        mvaddstr( 13, (half_lines), "||            |     |            || ||                           ||");
        mvaddstr( 14, (half_lines), row3.c_str());
        mvaddstr( 15, (half_lines), "||            |     |            || ||                           ||");
        mvaddstr( 16, (half_lines), "||                               || ||                           ||");
        mvaddstr( 17, (half_lines), "||------------       ------------|| ||                           ||");
        mvaddstr( 18, (half_lines), "============== OOOOO ===============================================");
        mvaddstr((LINES - 4), 0,"\t\t         Pressione [Enter] para continuar ... ");
        endwin();
    }


    /**
     * @brief Função com os dados de navegação do MENU
     */
    void footerInfoMenu(){
        mvaddstr((LINES - 2), 2, "\t\tUse [W, S] ou as SETAS para navegar || [ENTER] para selecionar");
        mvaddstr((LINES - 1), 2, "\t     Powered by Lucas Miguel - https://github.com/LucasMiguel ");
    }
    /**
     * @brief Função com os dados de navegação do MENU
     */
    void footerInfoTable(){
        mvaddstr((LINES - 2), 2, "\t\tUse [W, S, A, D] ou as SETAS para navegar || [ENTER] para selecionar");
        mvaddstr((LINES - 1), 2, "\t       Powered by Lucas Miguel - https://github.com/LucasMiguel ");
    }


}
