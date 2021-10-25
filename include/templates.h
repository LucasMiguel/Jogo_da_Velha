#ifndef TEMPLATES_H
#define TEMPLATES_H

namespace Templates {
    /**
     * @brief Função com a tela de boas vinda ao jogo
     */
    void startMessage();    
    /**
     * @brief Função com o cabeçalho das telas
     */
    void header(const int&);
    /**
     * @brief Função para tela de vitória do jogador
     */
    void victoryMensage(const std::string&);
    /**
     * @brief Exibe a mensagem de empate
     */
    void drawMensage();
    /**
     * @brief Função com as informações
     */
    void footerInfoMenu();
    /**
     * @brief Função com as informações do tabluleiro
     */
    void footerInfoTable();
}

#endif // TEMPLATES_H

