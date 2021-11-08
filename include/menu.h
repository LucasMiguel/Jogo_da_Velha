#ifndef MENU_H
#define MENU_H

namespace Menu {

    class Menu{
    private:
        std::string m_menu_list[5][2] = {
            {{"1"}, {"Jogador vs Jogador"}},
            {{"0"}, {"Jogador vs COM"}},
            {{"0"}, {"Regras"}},
            {{"0"}, {"Score"}},
            {{"0"}, {"Sair"}}
        };
        void cleanMenu();
        void setLine(int);
    public:
        Menu() {};
        int getLineSelectMenu();
        void printMenu();
        void changeLine(const int*);
    };

}
#endif // MENU_H
