#include <iostream>
#include "include/table.h"


void Table::printTable(){

    std::cout << "   ======================" << std::endl;
    std::cout << "   ||      |     |      ||" << std::endl;
    std::cout << " 3 ||   "<< ((table[0][0] == -1)? " ": ((table[0][0] == -1) == 0? "O":"X"))<< "   |  "<< ((table[0][1] == -1)? " ": ((table[0][1] == -1) == 0? "O":"X"))<< "  |   "<< ((table[0][0] == -1)? " ": ((table[0][2] == -1) == 0? "O":"X"))<< "  ||" << std::endl;
    std::cout << "   || _____|_____|_____ ||" << std::endl;
    std::cout << "   ||      |     |      ||" << std::endl;
    std::cout << " 2 ||   "<< ((table[1][0] == -1)? " ": ((table[1][0] == -1) == 0? "O":"X"))<< "   |  "<< ((table[1][1] == -1)? " ": ((table[1][1] == -1) == 0? "O":"X"))<< "  |   "<< ((table[0][0] == -1)? " ": ((table[1][2] == -1) == 0? "O":"X"))<< "  ||" << std::endl;
    std::cout << "   || _____|_____|_____ ||" << std::endl;
    std::cout << "   ||      |     |      ||" << std::endl;
    std::cout << " 1 ||   "<< ((table[2][0] == -1)? " ": ((table[2][0] == -1) == 0? "O":"X"))<< "   |  "<< ((table[2][1] == -1)? " ": ((table[2][1] == -1) == 0? "O":"X"))<< "  |   "<< ((table[0][0] == -1)? " ": ((table[2][2] == -1) == 0? "O":"X"))<< "  ||" << std::endl;
    std::cout << "   ||      |     |      ||" << std::endl;
    std::cout << "   =======================" << std::endl;
    std::cout << "        A     B      C    " << std::endl;

}
