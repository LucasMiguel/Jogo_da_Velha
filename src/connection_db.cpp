#include <iostream>
#include <filesystem>
#include <unistd.h>
#include "curses.h"
#include "include/connection_db.h"
#include "include/templates.h"


namespace ConnectionDB {
int ConnectionDB::callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int ConnectionDB::callbackScore(void *NotUsed, int argc, char **argv, char **azColName) {

    std::cout << "\t\tJogador 1: " << (argv[1] ? argv[1] : "NULL") << std::endl;
    std::cout << "\t\tJogador 2: " << (argv[2] ? argv[2] : "NULL") << std::endl;
    std::cout << "\t\tVencedor: " << (argv[3] ? argv[3] : "NULL") << std::endl;
    std::cout << "\t\tData\\Hora: " << (argv[4] ? argv[4] : "NULL") << std::endl;
    std::cout << "\t\t=========================================================== " << std::endl;
    return 0;
}

bool ConnectionDB::insertDatas(std::string *query){
    int rc;
    //Cria a tabela caso não tenha sido criada
    createTable();
    rc = sqlite3_open(nameDB, &db);
    mvaddstr(-3, 2, "Abrindo banco ...");
    if(rc){
//        std::cout << "Erro: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }else{
        mvaddstr(-3, 2, "Aberto");
        //Faz a inserção da query no banco de dados
        rc = sqlite3_exec(db, query->c_str(), callback, 0, &zErrMsg);
        if(rc == SQLITE_OK){
            return true;
        }else{
//            std::cout << "Erro: " << zErrMsg << std::endl;
            return false;
        }
    }
    sqlite3_close(db);
}

bool ConnectionDB::createTable(){
    int rc;
    std::string query = "CREATE TABLE score ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "player_1 VARCHAR(20),"
                  "player_2 VARCHAR(20),"
                  "winner VARCHAR(20),"
                  "data DATETIME DEFAULT CURRENT_TIMESTAMP);";
    rc = sqlite3_open(nameDB, &db);
    if(rc){
        std::cout << "\n\n\nErro: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }else{
        //Faz a inserção da query no banco de dados
        rc = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);
        if(rc == SQLITE_OK){
            return true;
        }else{
            return false;
        }
    }
    sqlite3_close(db);
}

bool ConnectionDB::getDatas(char *query){
    int rc;
    rc = sqlite3_open(nameDB, &db);    
    const char* data = "Retorno do callback";
    if(rc){
        std::string text = sqlite3_errmsg(db);
        mvaddstr(-3, 2, text.c_str());
        //        std::cout << "\n\n\nErro: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }else{
        //Faz a inserção da query no banco de dados
        rc = sqlite3_exec(db, query, callbackScore, (void*)data, &zErrMsg);
        if(rc == SQLITE_OK){
            return true;
        }else{
            std::cout << "\n\n\nErro: " << zErrMsg << std::endl;
            return false;
        }
    }
    sqlite3_close(db);
}

}
