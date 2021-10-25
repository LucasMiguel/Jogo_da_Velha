#include <iostream>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_player.h"
#include "include/templates.h"

namespace PlayPlay {

    void PlayPlay::game(){
        int key = 0;
        int end = 0;
        int turn = 1;
        int coord[2];
        getPlayer(1);
        getPlayer(2);
        system(CLEAR);
        m_table.setNewSelection();
        while(end == 0){
            while( key != ENTER_KEY){
                m_table.printTable((turn == 1?m_player_1:m_player_2));
                key = Functions::getKey();
                m_table.moveSelection(key);
            }
            m_table.getCoordSelect(coord[0], coord[1]);
            if(coord[0] >= 0){
                m_table.setValue(coord[0], coord[1], (turn==1?X:O));
                end = m_table.checkWinner();
                m_table.setNewSelection();
                key = 0;
                turn = !turn;
            }else{
                m_table.setNewSelection();
                key = 0;
            }
        }
        Functions::cleanWindow();
        if(end == 1){
            while( key != ENTER_KEY){
                Templates::victoryMensage(m_player_1.getName());
                key = Functions::getKey();
            }
        }else if(end == 2){
            while( key != ENTER_KEY){
                Templates::victoryMensage(m_player_2.getName());
                key = Functions::getKey();
            }
        }
        else{
            while( key != ENTER_KEY){
                Templates::drawMensage();
                key = Functions::getKey();
            }
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
            m_player_1.setSymbol(X);
        }else{
            m_player_2.setName(name);
            m_player_2.setSymbol(O);
        }
    }
}
