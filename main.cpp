#include <iostream>
#include <string>
#include "include/menu.h"
#include "include/macros.h"
#include "include/table.h"
#include "include/functions.h"
#include "include/templates.h"
#include "include/player_vs_player.h"


int main()
{

    /**
     * @brief Variável com o valor da tecla clicada
     */
    int key = 0;
        while( key != ENTER_KEY){
            Templates::startMessage();
            key = Functions::getKey();
        }
        key = 0;
    while(true){
        //Instância do objeto de jogo Player vs Player
        PlayPlay::PlayPlay playPlay;
        //Isntância do objeto do menu
        Menu::Menu menu;
        //Limpa a janela
        Functions::cleanWindow();
        //Loop do menu
        while (key != ENTER_KEY) {
            menu.printMenu();
            key = Functions::getKey();
            menu.changeLine(key);
        }
        key = 0;
        //Loop do menu
        Functions::cleanWindow();
        switch (menu.getLineSelectMenu()) {
        case 0:
            playPlay.game();
            break;
        case 1:
            std::cout << "Opcao 2 do Menu" << std::endl; break;
        case 2:
            std::cout << "Opcao 3 do Menu" << std::endl; break;
        case 3:
            std::cout << "Opcao 4 do Menu" << std::endl; break;
        default:
            Functions::cleanWindow();
            exit(0);
        }
    }
    return 0;
}


