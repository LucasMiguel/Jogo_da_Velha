#ifndef CONNECTION_DB_H
#define CONNECTION_DB_H
#include "sqlite3.h"
#include <string>

namespace ConnectionDB {
class ConnectionDB
{
private:
    char *nameDB = "score.db";
    sqlite3 *db;
    char * zErrMsg;
    /**
     * @brief Função de Callback dos dados
     * @param NotUsed
     * @param argc
     * @param argv
     * @param azColName
     * @return
     */
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    static int callbackScore(void *NotUsed, int argc, char **argv, char **azColName);
public:
    ConnectionDB() {}
    /**
     * @brief Função para inserção de dados
     * @param query
     * @return
     */
    bool insertDatas(char *query);
    bool getDatas(char *query);
};

}

#endif // CONNECTION_DB_H
