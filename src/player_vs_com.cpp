#include <iostream>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_com.h"
#include "include/templates.h"

namespace PlayCom {

    void PlayCom::game(){
        int key = 0;
        int end = 0;
        int turn = 1;
        unsigned int coord[2];
        getPlayer(1);
        getPlayer(2);
        system(CLEAR);
        m_table.setNewSelection();
        while(end == 0){
            if(turn == 1){              //Caso seja a vez do jogador físico
                while( key != ENTER_KEY){
                    m_table.printTable((turn == 1?&m_player_1:&m_player_2));
                    key = Functions::getKey();
                    m_table.moveSelection(&key);
                }
            }else{                     //Caso seja a máquina
                comMove();
            }
            m_table.getCoordSelect(&coord[0], &coord[1]);
            if(coord[0] >= 0){
                m_table.setValue(&coord[0], &coord[1], (turn==1?X:O));
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

    void PlayCom::getPlayer(const int num){
        std::string name;
        system(CLEAR);
        Templates::header(1);
        std::cout << "\t\t Insira o nome do Jogador: ";
        std::cin >> name;
        if(num==1){
            m_player_1.setName(&name);
            m_player_1.setSymbol(X);
        }else{
            std::string nameCom = "COM";
            m_player_1.setName(&nameCom);
            m_player_1.setSymbol(O);
        }
    }

    void PlayCom::comMove(){
        unsigned int selAxiX, selAxiY;


    }
}
