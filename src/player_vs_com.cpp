#include <iostream>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_com.h"
#include "include/templates.h"
#include "ncurses.h"

namespace PlayCom {

    void PlayCom::game(){
        int key = 0;
        int end = 0;
        int turn = 1;
        unsigned int coord[2];
        //Pega os nomes do jogador
        getPlayer(1);
        //Adiciona o segundo como a máquina
        getPlayer(2);
        system(CLEAR);
        //Coloca a seleção no primeiro campo vazio
        m_table.setNewSelection();
        while(end == 0){
            //Caso seja a vez do jogador físico
            if(turn == 1){
                while( key != ENTER_KEY){
                    m_table.printTable((turn == 1?&m_player_1:&m_player_2));
                    key = Functions::getKey();
                    m_table.moveSelection(&key);
                }
                //Pega a seleção da tabela real
                m_table.getCoordSelect(&coord[0], &coord[1]);
            }
            //Caso seja a máquina
            else{
                comMove();
                //Pega as coordenadas da célula da tabela de seleção
                m_table.getCoordSelectTable(&coord[0], &coord[1]);
            }
            //Faz a jogada de acordo com o campo com a seleção
            mvaddstr((LINES - 3), 25, std::to_string(coord[0]).c_str());
            mvaddstr((LINES - 3), 29, std::to_string(coord[1]).c_str());
            if(coord[0] >= 0){
                //Muda o valor de seleção para o valor do jogador
                m_table.setValue(&coord[0], &coord[1], (turn==1?X:O));
                //Checa se teve um ganhador
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
        if(num==1){
            Templates::header(1);
            std::cout << "\t\t Insira o nome do Jogador: ";
            std::cin >> name;
            m_player_1.setName(&name);
            m_player_1.setSymbol(X);
        }else{
            std::string nameCom = "COM";
            m_player_2.setName(&nameCom);
            m_player_2.setSymbol(O);
        }
    }

    void PlayCom::comMove(){
        ///Variável que irá o retorno das funções de checagem de pré vencedor
        int index = -1;
        unsigned int axiX, axiY;
        //Limpa a tabela de seleção.
        m_table.cleanTableSelect();
        //Teste para saber se o COM está preste a ganhar
        index = m_table.checkWillWin(O);
        if(index != -1){                            //Significa que existe uma linha com a possibilidade de vitória
            m_table.coordEmpty(&axiX, &axiY, index);
            m_table.setValueSelect(&axiX, &axiY, -2);
        }else{
            //Teste para saber se o Jogador está preste a ganhar
            index = m_table.checkWillWin(X);
            if(index != -1){                            //Significa que existe uma linha com a possibilidade de vitória
                m_table.coordEmpty(&axiX, &axiY, index);
                m_table.setValueSelect(&axiX, &axiY, -2);
            }else{
                //Caso nenhuma das opções anteriores retorne algo, ele escolhe a melhor jogada
                m_table.choiseBestPlay(&axiX, &axiY);
                m_table.setValueSelect(&axiX, &axiY, -2);
            }
        }
    }

}
