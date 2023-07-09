//
// Created by Romain Caron on 02/07/2023.
//

#include "ThresholdRepository.h"

ThresholdRepository::ThresholdRepository() {}

int ThresholdRepository::save(const Threshold& threshold) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppThreshold (temperature_min, temperature_max, wind_speed_min, wind_speed_max, humidity_min, humidity_max, precipitation_min, precipitation_max) VALUES (" +
                        std::to_string(threshold.getTemperatureMin()->value) + ", " +
                        std::to_string(threshold.getTemperatureMax()->value) + ", " +
                        std::to_string(threshold.getWindSpeedMin()->value) + ", " +
                        std::to_string(threshold.getWindSpeedMax()->value) + ", " +
                        (threshold.getHumidityMin().has_value() ? std::to_string(*threshold.getHumidityMin()) : "") + ", " +
                        (threshold.getHumidityMax().has_value() ? std::to_string(*threshold.getHumidityMax()) : "") + ", " +
                        (threshold.getPrecipitationMin().has_value() ? std::to_string(*threshold.getPrecipitationMin()) : "") + ", " +
                        (threshold.getPrecipitationMax().has_value() ? std::to_string(*threshold.getPrecipitationMax()) : "") + ") RETURNING id";

    result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the Threshold.");
}


Threshold ThresholdRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, temperature_min, temperature_max, wind_speed_min, wind_speed_max, humidity_min, humidity_max, precipitation_min, precipitation_max "
                        "FROM AppThreshold "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No threshold found with id " + std::to_string(id));
    }

    int thresholdId = result[0][0].as<int>();
    // Temperature min
    int temperatureMinValue = result[0][1].as<int>();
    Temperature temperatureMin((short)temperatureMinValue, CELSIUS);
    std::optional<Temperature> optionalTemperatureMin(temperatureMin);

    // Temperature max
    int temperatureMaxValue = result[0][2].as<int>();
    Temperature temperatureMax((short)temperatureMaxValue, CELSIUS);
    std::optional<Temperature> optionalTemperatureMax(temperatureMax);

    // Wind speed min
    int windSpeedMinValue = result[0][3].as<int>();
    WindSpeed windSpeedMin((short)windSpeedMinValue, KPH);
    std::optional<WindSpeed> optionalWindSpeedMin(windSpeedMin);

    // Wind speed max
    int windSpeedMaxValue = result[0][4].as<int>();
    WindSpeed windSpeedMax((short)windSpeedMaxValue, KPH);
    std::optional<WindSpeed> optionalWindSpeedMax(windSpeedMax);

    // Humidity min
    int humidityMinValue = result[0][5].as<int>();
    auto humidityMin = (uint8_t)humidityMinValue;

    // Humidity max
    int humidityMaxValue = result[0][6].as<int>();
    auto humidityMax = (uint8_t)humidityMaxValue;

    // Precipitation min
    int precipitationMinValue = result[0][7].as<int>();
    auto precipitationMin = (uint8_t)precipitationMinValue;

    // Precipitation max
    int precipitationMaxValue = result[0][8].as<int>();
    auto precipitationMax = (uint8_t)precipitationMaxValue;

    Threshold threshold(optionalTemperatureMin, optionalTemperatureMax, optionalWindSpeedMin, optionalWindSpeedMax, humidityMin, humidityMax, precipitationMin, precipitationMax);
    threshold.setId(thresholdId);

    return threshold;
}

void ThresholdRepository::update(const Threshold &threshold) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "UPDATE AppThreshold "
                        "SET temperature_min = " + std::to_string(threshold.getTemperatureMin()->value) + ", " +
                        "temperature_max = " + std::to_string(threshold.getTemperatureMax()->value) + ", " +
                        "wind_speed_min = " + std::to_string(threshold.getWindSpeedMin()->value) + ", " +
                        "wind_speed_max = " + std::to_string(threshold.getWindSpeedMax()->value) + ", " +
                        "humidity_min = " + (threshold.getHumidityMin().has_value() ? std::to_string(*threshold.getHumidityMin()) : "") + ", " +
                        "humidity_max = " + (threshold.getHumidityMax().has_value() ? std::to_string(*threshold.getHumidityMax()) : "") + ", " +
                        "precipitation_min = " + (threshold.getPrecipitationMin().has_value() ? std::to_string(*threshold.getPrecipitationMin()) : "") + ", " +
                        "precipitation_max = " + (threshold.getPrecipitationMax().has_value() ? std::to_string(*threshold.getPrecipitationMax()) : "") + " " +
                        "WHERE id = " + std::to_string(threshold.getId());

    dbConnection->execute(query);
}

bool ThresholdRepository::remove(const Threshold &threshold) {
    auto dbConnection = DatabaseConnection::getInstance();
    try {
        std::string query = "DELETE FROM AppThreshold WHERE id = " + std::to_string(threshold.getId());
        dbConnection->execute(query);
        return true;
    } catch (std::exception &e) {
        return false;
    }
}

