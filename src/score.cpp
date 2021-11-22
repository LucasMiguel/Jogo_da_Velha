#include <iostream>
#include "include/score.h"
#include "include/connection_db.h"
#include "include/templates.h"

namespace Score {

void showScore(){
    ConnectionDB::ConnectionDB conn;
    char *query = "SELECT * FROM score;";
    bool resp;
    Templates::header(1);
    std::cout << "\t\t\t================ SCORE ================\n" << std::endl;
    conn.getDatas(query);
    std::cout << "\n\n\t\t\tAperte [ENTER] para voltar ao menu\n" << std::endl;

}

}

