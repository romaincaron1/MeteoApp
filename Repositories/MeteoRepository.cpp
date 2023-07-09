//
// Created by Romain Caron on 04/07/2023.
//

#include "MeteoRepository.h"

MeteoRepository::MeteoRepository() {

}

int MeteoRepository::save(const Meteo& meteo) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppMeteo (humidity, precipitation, temperature, wind_speed, cloud_quantity) VALUES (" +
                        std::to_string(meteo.getHumidity()) +
                        ", " + std::to_string(meteo.getPrecipitation()) +
                        ", " + std::to_string(meteo.getTemperature().value) +
                        ", " + std::to_string(meteo.getWindSpeed().value) +
                        ", " + std::to_string(meteo.getCloudQuantity()) +
                        ") RETURNING id";

    pqxx::result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the Meteo.");
}

Meteo MeteoRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, humidity, precipitation, temperature, wind_speed, cloud_quantity "
                        "FROM AppMeteo "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No threshold found with id " + std::to_string(id));
    }

    int meteoId = result[0][0].as<int>();
    int humidity = result[0][1].as<int>();
    int precipitation = result[0][2].as<int>();
    int temperatureValue = result[0][3].as<int>();
    Temperature temperature((short)temperatureValue, TemperatureUnit::CELSIUS);
    int windSpeedValue = result[0][4].as<int>();
    WindSpeed windSpeed((short)windSpeedValue, WindSpeedUnit::KPH);
    int cloudQuantity = result[0][5].as<int>();

    Meteo meteo(humidity, precipitation, temperature, windSpeed, cloudQuantity);
    meteo.setId(meteoId);

    return meteo;
}

void MeteoRepository::update(const Meteo& meteo) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "UPDATE AppMeteo SET "
                        "humidity = " + std::to_string(meteo.getHumidity()) +
                        ", precipitation = " + std::to_string(meteo.getPrecipitation()) +
                        ", temperature = " + std::to_string(meteo.getTemperature().value) +
                        ", wind_speed = " + std::to_string(meteo.getWindSpeed().value) +
                        ", cloud_quantity = " + std::to_string(meteo.getCloudQuantity()) +
                        " WHERE id = " + std::to_string(meteo.getId());

    dbConnection->execute(query);
}

bool MeteoRepository::remove(const Meteo &meteo) {
    auto dbConnection = DatabaseConnection::getInstance();
    try {
        std::string query = "DELETE FROM AppMeteo WHERE id = " + std::to_string(meteo.getId());
        dbConnection->execute(query);
        return true;
    } catch (std::exception &e) {
        return false;
    }
}
