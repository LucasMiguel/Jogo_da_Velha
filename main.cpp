#include <iostream>
#include <string>
#include "include/menu.h"
#include "include/macros.h"
#include "include/table.h"
#include "include/functions.h"
#include "include/templates.h"
#include "ncurses.h"

int main()
{
    /**
     * @brief Variável com o valor da tecla clicada
     */
    int key = 0;

    while( key != ENTER_KEY){
        Templates::start_message();
        key = Functions::getKey();
    }
    key = 0;
    Menu::Menu menu;
    Functions::cleanWindow();
    while (key != ENTER_KEY) {
        menu.printMenu();
        key = Functions::getKey();
        menu.changeLine(key);
    }

//    switch (menu.getLineSelectMenu()) {
//    case 0:
//        std::cout << "Opcao 1 do Menu" << std::endl; break;
//    case 1:
//        std::cout << "Opcao 2 do Menu" << std::endl; break;
//    case 2:
//        std::cout << "Opcao 3 do Menu" << std::endl; break;
//    default:
//        std::cout << "Sair" << std::endl; break;
//    }

    return 0;
}


