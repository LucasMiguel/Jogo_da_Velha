#ifndef TABLE_H
#define TABLE_H
#include "include/macros.h"
#include "include/templates.h"
#include "include/player.h"

namespace Table {

class Table
{
private:
    int m_table[3][3] = {-2,-1,-1,-1,-1,-1,-1,-1,-1};

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
     * @brief Função que retorna as coordenadas da célula selecionada.
     */
    void getCoordSelect(int&, int&);
    /**
     * @brief Função que move a seleção de acordo com a tecla selecionada.
     */
    void moveSelection(const int&);
    /**
     * @brief Função que irá selecionar um novo campo para seleção
     */
    void setNewSelection();

};

}

#endif // TABLE_H
