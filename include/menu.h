#ifndef MENU_H
#define MENU_H

namespace Menu {

    class Menu{
    private:
        std::string m_menu_list[4][2] = {
            {{"1"}, {" - Player vs Player"}},
            {{"0"}, {" - Player vs COM"}},
            {{"0"}, {" - Score"}},
            {{"0"}, {" - Sair"}}
        };
        void cleanMenu();
        void setLine(int);
    public:
        Menu() {};
        int getLineSelectMenu();
        void printMenu();
        void changeLine(int);
    };

}
#endif // MENU_H
