#include <iostream>
#include "include/templates.h"
#include "include/macros.h"

namespace Templates {

    /**
     * @brief Função com a tela de boas vinda ao jogo
     */
    void start_message()
    {
         std::cout << "\n";
         std::cout << "\t\t         ======== +++ =========" << std::endl;
         std::cout << "\t\t        |                      |" << std::endl;
         std::cout << "\t\t        |       Bem Vindo      |" << std::endl;
         std::cout << "\t\t        |    Ao jogo da velha  |" << std::endl;
         std::cout << "\t\t        |                      |" << std::endl;
         std::cout << "\t\t         ======== +++ =========\n\n\n\n" << std::endl;
         std::cout << "\t\t    Pressione [Enter] para continuar ... " << std::endl;
         std::cin.get();
    }

    /**
     * @brief Função com o cabeçalho das telas
     */
    void header()
    {
         system(CLEAR);
         std::cout << "\t\t========= ################### ============= " << std::endl;
         std::cout << "\t\t             JOGO DA VELHA               " << std::endl;
         std::cout << "\t\t========= ################### ============= \n\n" << std::endl;
    }


}
