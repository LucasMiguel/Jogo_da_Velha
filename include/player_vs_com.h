#ifndef PLAYER_VS_COM_H
#define PLAYER_VS_COM_H
#include "player.h"
#include "table.h"

namespace PlayCom {
class PlayCom{
private:
    Player::Player m_player_1;
    Player::Player m_player_2;
    Table::Table m_table;
    ///Variável que irá determinar a dificuldade
    /// 1 = Fácil || 2 = Médio || 3 = Difícil
    int difficulty;
    /**
     * @brief Função que irá pegar a dificuldade escolhida.
     */
    void getDifficulty();
    /**
     * @brief Função que irá pegaro o nome do jogador
     * @param num = Qual o numero do jogador 1 | 2
     */
    void getPlayer(const int);
    /**
     * @brief Função que irá fazer o movimento do computador
     */
    void comMove();    
public:
    PlayCom() {};
    void game();
};
}

#endif // PLAYER_VS_COM_H
