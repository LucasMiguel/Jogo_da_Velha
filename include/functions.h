#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace Functions {
    /**
     * @brief Função que irá retornar o valor da tecla digitada.
     * UP = -1 | DOWN = +1 | LEFT = +1 | RIGHT = -1
     * @return
     */
    int getKey();
    /**
     * @brief Função que limpa a tela.
     */
    void cleanWindow();

    /**
     * @brief Função que tira os espaços da esquerda
     */
    std::string ltrim(const std::string &s);

    /**
     * @brief Função que tira os espaços da direita
     */
    std::string rtrim(const std::string &s);

    /**
     * @brief Função que tira os espaços de ambos os lados
     */
    std::string trim(const std::string &s);
}

#endif // FUNCTIONS_H
