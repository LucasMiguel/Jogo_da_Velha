#ifndef MACROS_H
#define MACROS_H


#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
    //Definição das teclas de utilização
    const int W_KEY = 119;
    const int A_KEY = 97;
    const int D_KEY = 100;
    const int S_KEY = 115;
    const int ENTER_KEY = 13;
    const int ESC_KEY = 27;
#else
    #define CLEAR "clear"
    //Definição das teclas de utilização
    const int W_KEY = 119;
    const int A_KEY = 97;
    const int D_KEY = 100;
    const int S_KEY = 115;
    const int UP_KEY = 259;
    const int DOWN_KEY = 258;
    const int LEFT_KEY = 261;
    const int RIGHT_KEY = 260;
    const int ENTER_KEY = 10;
    const int ESC_KEY = 27;
#endif


const int UP = (-1);
const int DOWN = (+1);
const int LEFT = (-1);
const int RIGHT = (+1);

/**
 * @brief Constante com a quantidade de itens no menu
 */
const int QUANT_ITENS_MENU = 4;

#endif // MACROS_H
