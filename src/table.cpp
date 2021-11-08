#include <iostream>
#include <ncurses.h>
#include "include/macros.h"
#include "include/table.h"

namespace Table {

    void Table::printTable(Player::Player *player){
        std::string value0, value1, value2;
        std::string line1 = "Vez do jogador: " + player->getName() + " ( " + (player->getSymbol()==O?"O":"X") +" )             ";
        value0 = (getValue(0,0) == -1?"  ":getValue(0,0)==-2?">#":getValue(0,0)==O?getValueSelect(0,0)==-2?">O":" O":getValueSelect(0,0)==-2?">X":" X");
        value1 = (getValue(0,1) == -1?"  ":getValue(0,1)==-2?">#":getValue(0,1)==O?getValueSelect(0,1)==-2?">O":" O":getValueSelect(0,1)==-2?">X":" X");
        value2 = (getValue(0,2) == -1?"  ":getValue(0,2)==-2?">#":getValue(0,2)==O?getValueSelect(0,2)==-2?">O":" O":getValueSelect(0,2)==-2?">X":" X");
        std::string row1 =  "||        "+value0+"  | "+value1+"  | "+value2+"         ||";
        value0 = (getValue(1,0) == -1?"  ":getValue(1,0)==-2?">#":getValue(1,0)==O?getValueSelect(1,0)==-2?">O":" O":getValueSelect(1,0)==-2?">X":" X");
        value1 = (getValue(1,1) == -1?"  ":getValue(1,1)==-2?">#":getValue(1,1)==O?getValueSelect(1,1)==-2?">O":" O":getValueSelect(1,1)==-2?">X":" X");
        value2 = (getValue(1,2) == -1?"  ":getValue(1,2)==-2?">#":getValue(1,2)==O?getValueSelect(1,2)==-2?">O":" O":getValueSelect(1,2)==-2?">X":" X");
        std::string row2 =  "||        "+value0+"  | "+value1+"  | "+value2+"         ||";
        value0 = (getValue(2,0) == -1?"  ":getValue(2,0)==-2?">#":getValue(2,0)==O?getValueSelect(2,0)==-2?">O":" O":getValueSelect(2,0)==-2?">X":" X");
        value1 = (getValue(2,1) == -1?"  ":getValue(2,1)==-2?">#":getValue(2,1)==O?getValueSelect(2,1)==-2?">O":" O":getValueSelect(2,1)==-2?">X":" X");
        value2 = (getValue(2,2) == -1?"  ":getValue(2,2)==-2?">#":getValue(2,2)==O?getValueSelect(2,2)==-2?">O":" O":getValueSelect(2,2)==-2?">X":" X");
        std::string row3 =  "||        "+value0+"  | "+value1+"  | "+value2+"         ||";


        initscr();
        int half_lines = (LINES-1)/2;
        raw();
        keypad(stdscr, TRUE);
        noecho();
        Templates::header(2);
        mvaddstr( 4, (half_lines+12),  line1.c_str());
        mvaddstr( 5, (half_lines+12),  "============== XXXXX ==============");
        mvaddstr( 6, (half_lines+12),  "||------------       ------------||");
        mvaddstr( 7, (half_lines+12),  "||                               ||");
        mvaddstr( 8, (half_lines+12),  "||            |     |            ||");
        mvaddstr( 9, (half_lines+12),  row1.c_str());
        mvaddstr( 10, (half_lines+12), "||       _____|_____|_____       ||");
        mvaddstr( 11, (half_lines+12), "||            |     |            ||");
        mvaddstr( 12, (half_lines+12), row2.c_str());
        mvaddstr( 13, (half_lines+12), "||       _____|_____|_____       ||");
        mvaddstr( 14, (half_lines+12), "||            |     |            ||");
        mvaddstr( 15, (half_lines+12), row3.c_str());
        mvaddstr( 16, (half_lines+12), "||            |     |            ||");
        mvaddstr( 17, (half_lines+12), "||                               ||");
        mvaddstr( 18, (half_lines+12), "||------------       ------------||");
        mvaddstr( 19, (half_lines+12), "============== OOOOO ==============");
        Templates::footerInfoTable();
        endwin();

    }

    int Table::getValue(const unsigned int axiX, const unsigned int axiY){
        return m_table[axiX][axiY];
    }

    void Table::setValue(const unsigned int *axiX, const unsigned int *axiY, const int value){
        m_table[*axiX][*axiY] = value;
    }

    int Table::getValueSelect(const unsigned int axiX, const unsigned int axiY){
        return m_table_selection[axiX][axiY];
    }

    void Table::setValueSelect(const unsigned int *axiX, const unsigned int *axiY, const int value){
        m_table_selection[*axiX][*axiY] = value;
    }

    void Table::cleanTableSelect(){
        for(int i=0; i<3;i++){
            for(int ii=0;ii<3;ii++){
                m_table_selection[i][ii] = -1;
            }
        }
    }

    void Table::getCoordSelectTable(unsigned int *axiX, unsigned int *axiY){
        for(unsigned int i=0; i<3;i++){
            for(unsigned int ii=0;ii<3;ii++){
                if(m_table_selection[i][ii] == -2){
                    *axiX = i;
                    *axiY = ii;
                    return;
                }
            }
        }
    }


    void Table::getCoordSelect(unsigned int *axiX, unsigned int *axiY){
        for(int i=0; i<3;i++){
            for(int ii=0;ii<3;ii++){
                if(m_table[i][ii] == -2){
                    *axiX = i;
                    *axiY = ii;
                    return;
                }
            }
        }
        *axiX = -1;
    }

    void Table::setNewSelection(){
        for(int i=0;i<3;i++){
            for(int ii=0;ii<3;ii++){
                if(m_table[i][ii] == -1){
                    m_table[i][ii] = -2;
                    cleanTableSelect();
                    m_table_selection[i][ii] = -2;
                    return;
                }
            }
        }
    }

    void Table::moveSelection(const int *key){
        unsigned int axiX, axiY;
        //Variável que irá armazenar o valor do comando (-1) ou (1)
        int command = 0;
        getCoordSelectTable(&axiX, &axiY);
        if(*key == UP_KEY || *key == DOWN_KEY){
            command = (*key==UP_KEY?UP:DOWN);
            /**
             * @brief Variável irá armazenar o valor já somada com a seleção da tecla e o valor da linha.
             */
            unsigned int axiXX = command + axiX;

            if(axiXX >= 0 && axiXX < 3){
                //Muda o valor da célula de seleção
                cleanTableSelect();                     /*Limpa a tabela de seleção*/
                setValueSelect(&axiXX, &axiY, -2);        /*Muda o valor da nova celula*/
                //Muda o valor da célula para real seleção
                if(m_table[axiXX][axiY] == -1){
                    setValue(&axiXX, &axiY, -2);          /*Muda o valor da nova celula*/
                }
                if(m_table[axiX][axiY] < 0){
                     setValue(&axiX, &axiY, -1); /*Muda o valor da antiga celula*/
                }
            }
        }
        else if(*key == LEFT_KEY || *key == RIGHT_KEY){
            command = (*key==RIGHT_KEY?RIGHT:LEFT);
            /**
             * @brief Variável irá armazenar o valor já somada com a seleção da tecla e o valor da coluna.
             */
            unsigned int axiYY = command + axiY;

            if(axiYY >= 0 && axiYY < 3){
                //Muda o valor da célula de seleção
                cleanTableSelect();                     /*Limpa a tabela de seleção*/
                setValueSelect(&axiX, &axiYY, -2);        /*Muda o valor da nova celula*/
                if(m_table[axiX][axiYY] == -1){
                    setValue(&axiX, &axiYY, -2);          /*Muda o valor da nova celula*/
                }
                if(m_table[axiX][axiY] < 0){
                    setValue(&axiX, &axiY, -1); /*Muda o valor da antiga celula*/
                }
            }
        }
    }

    int Table::checkWinner(){
        int calc = -9;
        for(int i=0;i<8;i++){
            calc = (getValue(m_coor_win[i][0][0], m_coor_win[i][0][1])) +
                    (getValue(m_coor_win[i][1][0], m_coor_win[i][1][1])) +
                    (getValue(m_coor_win[i][2][0], m_coor_win[i][2][1]));
            if(calc == 30){
                return 1;
            }else if(calc == 60){
                return 2;
            }
        }
        for(int i=0;i<3;i++){
            for(int ii=0;ii<3;ii++){
                if(m_table[i][ii] == -1){
                    return 0;
                }
            }
        }
        return 3;
    }

}
