#ifndef MACROS_H
#define MACROS_H


#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
    //Definição das teclas de utilização
    const unsigned int W_KEY = 119;
    const unsigned int A_KEY = 97;
    const unsigned int D_KEY = 100;
    const unsigned int S_KEY = 115;
    const unsigned int ENTER_KEY = 13;
    const unsigned int ESC_KEY = 27;
#else
    #define CLEAR "clear"
    //Definição das teclas de utilização
    const unsigned int W_KEY = 119;
    const unsigned int A_KEY = 97;
    const unsigned int D_KEY = 100;
    const unsigned int S_KEY = 115;
    const unsigned int UP_KEY = 259;
    const unsigned int DOWN_KEY = 258;
    const unsigned int LEFT_KEY = 261;
    const unsigned int RIGHT_KEY = 260;
    const unsigned int ENTER_KEY = 10;
    const unsigned int ESC_KEY = 27;
#endif

const int UP = (-1);
const int DOWN = (+1);
const int LEFT = (+1);
const int RIGHT = (-1);

/**
 * @brief Constante com a quantidade de itens no menu
 */
const int QUANT_ITENS_MENU = 5;

#endif // MACROS_H
