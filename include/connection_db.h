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
    /**
     * @brief Função de Callback dos getDados
     * @param NotUsed
     * @param argc
     * @param argv
     * @param azColName
     * @return
     */
    static int callbackScore(void *NotUsed, int argc, char **argv, char **azColName);
    /**
     * @brief Função que irá criar um banco de dados
     * @return Se já tiver criado ele irá retornar false
     */
    bool createTable();
public:
    ConnectionDB() {}
    /**
     * @brief Função para inserção de dados
     * @param query
     * @return
     */
    bool insertDatas(std::string *query);
    /**
     * @brief Função que irá retornar os valores do banco
     * @param query
     * @return
     */
    bool getDatas(char *query);
};

}

#endif // CONNECTION_DB_H
