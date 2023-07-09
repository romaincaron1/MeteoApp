//
// Created by Romain Caron on 02/07/2023.
//

#include "ZoneRepository.h"
#include "MeteoRepository.h"

ZoneRepository::ZoneRepository() {}

int ZoneRepository::save(const Zone& zone) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppZone (country, region, city, latitude, longitude, meteoId) VALUES ('" +
                        zone.getCountry() +
                        "', '" + zone.getRegion() +
                        "', '" + zone.getCity() +
                        "', " + std::to_string(zone.getLatitude()) +
                        ", " + std::to_string(zone.getLongitude()) +
                        ", " + std::to_string(zone.getMeteo()->getId()) + ") RETURNING id";

    result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the Zone.");
}

Zone ZoneRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, country, region, city, latitude, longitude, meteoId "
                        "FROM AppZone "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No zone found with id " + std::to_string(id));
    }

    int zoneId = result[0][0].as<int>();
    std::string country = result[0][1].as<std::string>();
    std::string region = result[0][2].as<std::string>();
    std::string city = result[0][3].as<std::string>();
    double latitude = result[0][4].as<double>();
    double longitude = result[0][5].as<double>();
    int meteoId = result[0][6].as<int>();

    // Get Meteo from database
    MeteoRepository meteoRepository;
    std::optional<Meteo> meteo = meteoRepository.findById(meteoId);

    Zone zone(country, region, city, latitude, longitude, meteo);
    zone.setId(zoneId);

    return zone;
}
