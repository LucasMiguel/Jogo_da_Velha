#include <iostream>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_player.h"
#include "include/templates.h"

namespace PlayPlay {

    void PlayPlay::game(){
        int key = 0;
//        getPlayer(1);
//        getPlayer(2);
        while( key != ENTER_KEY){
            m_table.printTable(m_player_1);
            key = Functions::getKey();
            m_table.moveSelection(key);
        }
    }

    void PlayPlay::getPlayer(const int &num){
        std::string name;
        system(CLEAR);
        Templates::header(1);
        std::cout << "\t\t Insira o nome do " <<
        (num==1?"primeiro": "segundo") << " jogador " <<
        (num==1?"(X)":"(O)") << ":\n\n\t\t ";
        std::cin >> name;
        if(num==1){
            m_player_1.setName(name);
            m_player_1.setSymbol(1);
        }else{
            m_player_2.setName(name);
            m_player_2.setSymbol(0);
        }
    }
}
