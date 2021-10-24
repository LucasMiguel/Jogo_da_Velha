#include <iostream>
#include "include/player.h"

namespace Player {

void Player::setName(const std::string &name){
    m_name = name;
}

void Player::setSymbol(const int &symbol){
    m_symbol = symbol;
}

std::string Player::getName(){
    return m_name;
}

int Player::getSymbol(){
    return m_symbol;
}

}
