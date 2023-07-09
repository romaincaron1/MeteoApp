//
// Created by Romain Caron on 02/07/2023.
//

#include "PreferenceRepository.h"

PreferenceRepository::PreferenceRepository() {}

int PreferenceRepository::save(const Preference &preference) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppPreference (thresholdid) VALUES (" +
                        std::to_string(preference.getThreshold().getId()) + ") RETURNING id";

    result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the Preference.");
}

Preference PreferenceRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, thresholdid "
                        "FROM AppPreference "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No preference found with id " + std::to_string(id));
    }

    int preferenceId = result[0][0].as<int>();
    int thresholdId = result[0][1].as<int>();

    ThresholdRepository thresholdRepository;
    Threshold threshold = thresholdRepository.findById(thresholdId);

    Preference preference(threshold);
    preference.setId(preferenceId);

    return preference;
}

void PreferenceRepository::update(const Preference &preference) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "UPDATE AppPreference "
                        "SET thresholdid = " + std::to_string(preference.getThreshold().getId()) +
                        " WHERE id = " + std::to_string(preference.getId());

    dbConnection->execute(query);
}

bool PreferenceRepository::remove(const Preference &preference) {
    auto dbConnection = DatabaseConnection::getInstance();
    try {
        std::string query = "DELETE FROM Preference WHERE id = " + std::to_string(preference.getId());
        dbConnection->execute(query);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error while deleting the preference : " << e.what() << std::endl;
        return false;
    }
}