#ifndef TABLE_H
#define TABLE_H
#include "include/macros.h"
#include "include/templates.h"
#include "include/player.h"

namespace Table {

class Table
{
private:
    int m_table[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    int m_table_selection[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    int m_coor_win[8][3][2]={
        {{0,0}, {0,1},{0,2}},
        {{1,0},{1,1},{1,2}},
        {{2,0},{2,1},{2,2}},
        {{0,0},{1,0},{2,0}},
        {{0,1},{1,1},{2,1}},
        {{0,2},{1,2},{2,2}},
        {{0,0},{1,1},{2,2}},
        {{0,2},{1,1},{2,0}}
    };
public:
    Table() {}
    void printTable(Player::Player&);
    /**
     * @brief Função que pega o valor da célula selecionada
     * @return O valor da célula.
     * || -2 = Seleciondada || -1 = Vazia || 0 = O || 1 = 1.
     */
    int getValue(const unsigned int&, const unsigned int&);
    /**
     * @brief Função que irá inserir o valor na célula de acordo
     * com as cordenandas e o valor.
     */
    void setValue(const unsigned int&, const unsigned int&, const int&);
    /**
     * @brief Função que pega o valor da célula selecionada
     * @return O valor da célula.
     * || -2 = Seleciondada || -1 = Vazia.
     */
    int getValueSelect(const unsigned int&, const unsigned int&);
    /**
     * @brief Função que irá inserir o valor na tabela de seleção na célula de acordo
     * com as cordenandas e o valor.
     */
    void setValueSelect(const unsigned int&, const unsigned int&, const int&);
    /**
     * @brief Função que irá limpar a tabela de seleção
     */
    void cleanTableSelect();
    /**
     * @brief Função que retorna as coordenadas da célula selecionada.
     */
    void getCoordSelect(int&, int&);
    /**
     * @brief Função que retorna as coordenadas da célula selecionada na tabela de Movimentação.
     */
    void getCoordSelectTable(int&, int&);
    /**
     * @brief Função que move a seleção de acordo com a tecla selecionada.
     */
    void moveSelection(const int&);
    /**
     * @brief Função que irá selecionar um novo campo para seleção
     * @return irá retornar 3 se não tiver mais posições, e terá dado velha
     */
    void setNewSelection();
    /**
     * @brief Função que irá checar se houve um vencedor.
     * @return O valor indicará o vencedor | 0 = Sem vencedores | 1 = Jogador 1 | 2 = Jogador 2
     */
    int checkWinner();

};

}

#endif // TABLE_H
