#ifndef PLAYER_H
#define PLAYER_H

namespace Player {
class Player{
private:
    std::string m_name;
    unsigned int m_symbol;
public:
    Player(){};
    /**
     * @brief Função que irá inserir o nome do jogador
     */
    void setName(const std::string*);
    /**
     * @brief Função que irá inserir o simbolo do jogador
     * 0 = 2 || 1 = X
     */
    void setSymbol(const int);
    /**
     * @brief Função para pegar o nome do jogador
     * @return Nome do jogador
     */
    std::string getName();
    /**
     * @brief Função para pegar o simbolo do jogador
     * @return O symbolo em inteiro
     */
    int getSymbol();

};
}

#endif // PLAYER_H
