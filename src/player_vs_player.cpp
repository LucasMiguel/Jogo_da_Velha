#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "include/macros.h"
#include "include/functions.h"
#include "include/player_vs_player.h"
#include "include/templates.h"
#include "include/connection_db.h"


namespace PlayPlay {

    void PlayPlay::game(){
        ///Instância da classe de comunicação com o banco de dados
        ConnectionDB::ConnectionDB conn;
        ///Variável que irá armazenar o valor que será mandado para o banco
        std::string query;
        int key = 0;
        int end = 0;
        int turn = 1;
        unsigned int coord[2];
        //Pega os nomes dos jogadores
        getPlayer(1);
        getPlayer(2);
        system(CLEAR);
        //Coloca a seleção no primeiro campo vazio
        m_table.setNewSelection();
        while(end == 0){
            while( key != ENTER_KEY){
                m_table.printTable((turn == 1?&m_player_1:&m_player_2));
                key = Functions::getKey();
                m_table.moveSelection(&key);
            }
            m_table.getCoordSelectTable(&coord[0], &coord[1]);
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
            query = "INSERT INTO score (player_1, player_2, winner) VALUES('" + m_player_1.getName() + "', '" + m_player_2.getName() + "', '" + m_player_1.getName()+ "');";
            conn.insertDatas(&query);
            while( key != ENTER_KEY){
                Templates::victoryMensage(m_player_1.getName());
                key = Functions::getKey();
            }
        }else if(end == 2){
            query = "INSERT INTO score (player_1, player_2, winner) VALUES('" + m_player_1.getName() + "', '" + m_player_2.getName() + "', '" + m_player_2.getName()+ "');";
            conn.insertDatas(&query);
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

    void PlayPlay::getPlayer(const int num){
        std::string name;
        system(CLEAR);
        Templates::header(1);
        std::cout << "\t\t Insira o nome do " <<
        (num==1?"primeiro": "segundo") << " jogador " <<
        (num==1?"(X)":"(O)") << ":\n\n\t\t ";
        fflush(stdin);
        getline(std::cin, name);
        //Tira os espaços em branco do começo e final do nome
        name = Functions::trim(name);
        //Teste para saber se o realmente foi inserido um valor
        if(name.length() != 0){
            if(num==1){
                m_player_1.setName(&name);
                m_player_1.setSymbol(X);
            }else{
                m_player_2.setName(&name);
                m_player_2.setSymbol(O);
            }
        }else{
            PlayPlay::getPlayer(num);
        }
    }
}
