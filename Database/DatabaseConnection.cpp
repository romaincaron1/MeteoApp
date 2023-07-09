#include "DatabaseConnection.h"

DatabaseConnection* DatabaseConnection::instance = nullptr;

DatabaseConnection::DatabaseConnection() {
    try {
        auto* C = new pqxx::connection("dbname=meteo user=postgres password=romain hostaddr=127.0.0.1 port=5432");
        if (C->is_open()) {
            std::cout << "Opened database successfully: " << C->dbname() << std::endl;
            this->currentConnection = C;
        } else {
            std::cout << "Can't open database" << std::endl;
            delete C;
        }
    } catch (const pqxx::broken_connection& e) {
        std::cerr << "Broken connection error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

DatabaseConnection* DatabaseConnection::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseConnection();
    }
    return instance;
}

DatabaseConnection::~DatabaseConnection() {
    if (isConnected()) {
        currentConnection->close();
    }
}

bool DatabaseConnection::isConnected() const {
    return currentConnection != nullptr && currentConnection->is_open();
}

pqxx::result DatabaseConnection::execute(const std::string& query) {
    pqxx::work transaction(*currentConnection);
    pqxx::result result;

    try {
        result = transaction.exec(query);
        transaction.commit();
    } catch (const std::exception& e) {
        transaction.abort();
        throw;
    }

    return result;
}
