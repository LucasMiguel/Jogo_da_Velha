#ifndef TABLE_H
#define TABLE_H
#include <string>
#include "macros.h"
#include "templates.h"
#include "player.h"


namespace Table {

class Table
{
private:
    ///Variável que armazena as jogadas já efetuadas
    int m_table[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}; //-1 = Vazio || 10 = X || 20 = O
    ///Variável que armazena a seleção para a próxima jogada
    int m_table_selection[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}; // -1 = Sem seleção || -2 = Com seleção
    ///Variável com a combinações de coordenadas de possíveis vitórias
    unsigned int m_coor_win[8][3][2]={
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
    /**
    * @brief Construtor
    */
    Table() {}
    /**
     * @brief Imprime a tabela na tela
     */
    void printTable(Player::Player*);
    /**
     * @brief Função que retorna a string para o campo.
     * @param axiX - Coordenada em X.
     * @param axiY - Coordenada em Y.
     * @return - A string que irá no campo.
     */
    std::string returnValueField(int axiX, int axiY);
    /**
     * @brief Função que retorna a string para o campo da matriz de jogadas.
     * @param axiX - Coordenada em X.
     * @param axiY - Coordenada em Y.
     * @return - A string que irá no campo.
     */
    std::string returnValuePlayer(int axiX, int axiY);
    /**
     * @brief Função que pega o valor da célula selecionada
     * @return O valor da célula.
     * || -2 = Seleciondada || -1 = Vazia || 0 = O || 1 = 1.
     */
    int getValue(const unsigned int, const unsigned int);
    /**
     * @brief Função que irá inserir o valor na célula de acordo
     * com as cordenandas e o valor.
     */
    void setValue(const unsigned int*, const unsigned int*, const int);
    /**
     * @brief Função que pega o valor da célula selecionada
     * @return O valor da célula.
     * || -2 = Seleciondada || -1 = Vazia.
     */
    int getValueSelect(const unsigned int, const unsigned int);
    /**
     * @brief Função que irá inserir o valor na tabela de seleção na célula de acordo
     * com as cordenandas e o valor.
     */
    void setValueSelect(const unsigned int* axiX, const unsigned int*, const int);
    /**
     * @brief Função que irá limpar a tabela de seleção
     */
    void cleanTableSelect();
    /**
     * @brief Função que retorna as coordenadas da célula selecionada.
     */
    void getCoordSelect(unsigned int*, unsigned int*);
    /**
     * @brief Função que retorna as coordenadas da célula selecionada na tabela de Movimentação.
     */
    void getCoordSelectTable(unsigned int*, unsigned int*);
    /**
     * @brief Função que move a seleção de acordo com a tecla selecionada.
     */
    void moveSelection(const int*);
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
    /**
     * @brief Função que irá verificar se o 'O' está para ganhar
     * @param identificador se é o 'X' ou 'O'.
     * @return o index da linha de vitória. Se retornar -1 é que não existe
     */
    int checkWillWin(int symbol);    
    /**
     * @brief Função que irá retornar a coordenada vazia para se poder fazer o movimento
     * @param aixX - Valor da coordenada em X
     * @param aixY - Valor da coordenada em Y
     * @param index - Valor do index da tabela de possibilidades de vitórias
     */
    void coordEmpty(unsigned int* aixX, unsigned int* aixY, int index);
    /**
     * @brief Função que irá retornar a melhor jogada para o computador.
     * @param axiX - retorno da coo rdenada X
     * @param axiY - retorno da coordenada Y
     */
    void choiseBestPlay(unsigned int* axiX, unsigned int* axiY);

};

}

#endif // TABLE_H
