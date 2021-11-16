#ifndef PLAYER_VS_COM_H
#define PLAYER_VS_COM_H
#include "include/player.h"
#include "table.h"

namespace PlayCom {
class PlayCom{
private:
    Player::Player m_player_1;
    Player::Player m_player_2;
    Table::Table m_table;
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
