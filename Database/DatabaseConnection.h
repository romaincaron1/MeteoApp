#ifndef METEO_DATABASECONNECTION_H
#define METEO_DATABASECONNECTION_H

#include <pqxx/pqxx>
#include <iostream>

#include <stdexcept>

using namespace pqxx;

class DatabaseConnection {
private:
    static DatabaseConnection* instance;
    pqxx::connection* currentConnection;
    DatabaseConnection();
public:
    static DatabaseConnection* getInstance();
    ~DatabaseConnection();
    bool isConnected() const;
    pqxx::result execute(const std::string& query);
};

#endif //METEO_DATABASECONNECTION_H
