#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <ncurses.h>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_com.h"
#include "include/templates.h"
#include "include/connection_db.h"

namespace PlayCom {

    void PlayCom::game(){
        ///Instância da classe de comunicação com o banco de dados
        ConnectionDB::ConnectionDB conn;
        ///Variável que irá armazenar o valor que será mandado para o banco
        std::string query;
        int key = 0;
        int end = 0;
        int turn = 1;
        std::string valuesEndPlay[3][3];
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
            }
            //Caso seja a máquina
            else{
                comMove();
            }
            //Pega as coordenadas da célula da tabela de seleção
            m_table.getCoordSelectTable(&coord[0], &coord[1]);
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
        for(int i=0; i<3; i++){
            for (int ii=0; ii<3;ii++){
                valuesEndPlay[i][ii] = m_table.returnValuePlayer(i, ii);
            }
        }
        if(end == 1){
            query = "INSERT INTO score (player_1, player_2, winner) VALUES('" + m_player_1.getName() + "', '" + m_player_2.getName() + "', '" + m_player_1.getName()+ "');";
            conn.insertDatas(&query);
            while( key != ENTER_KEY){
                Templates::victoryMensage(m_player_1.getName(), 1, valuesEndPlay);
                key = Functions::getKey();
            }
        }else if(end == 2){
            query = "INSERT INTO score (player_1, player_2, winner) VALUES('" + m_player_1.getName() + "', '" + m_player_2.getName() + "', '" + m_player_2.getName()+ "');";
            conn.insertDatas(&query);
            while( key != ENTER_KEY){
                Templates::victoryMensage(m_player_2.getName(), 2, valuesEndPlay);
                key = Functions::getKey();
            }
        }
        else{
            while( key != ENTER_KEY){
                Templates::drawMensage(valuesEndPlay);
                key = Functions::getKey();
            }
        }

    }

    void PlayCom::getPlayer(const int num){
        std::string name;
        system(CLEAR);
        if(num==1){
            Templates::header(1);
            std::cout << "\t\t Insira o nome do Jogador: \n\n\t\t ";
            getline(std::cin, name);
            //Tira os espaços em branco do começo e final do nome
            name = Functions::trim(name);
            //Teste para saber se o realmente foi inserido um valor
            if(name.length() != 0){
                m_player_1.setName(&name);
                m_player_1.setSymbol(X);
            }else{
                PlayCom::getPlayer(num);
            }
        }else{
            std::string nameCom = "Marvim[COM]";
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
