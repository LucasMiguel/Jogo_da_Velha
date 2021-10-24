#ifndef PLAYER_VS_PLAYER_H
#define PLAYER_VS_PLAYER_H
#include "include/player.h"
#include "table.h"

namespace PlayPlay {
class PlayPlay{
private:
    Player::Player m_player_1;
    Player::Player m_player_2;
    Table::Table m_table;
    void getPlayer(const int&);

public:
    PlayPlay() {};
    void game();
};
}

#endif // PLAYER_VS_PLAYER_H
