//
// Created by Romain Caron on 01/07/2023.
//

#include "ProfileRepository.h"

ProfileRepository::ProfileRepository() {}

int ProfileRepository::save(const Profile &profile) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppProfile (name, type, thresholdId) VALUES ('" +
            profile.getName() +
            "', " + std::to_string(static_cast<int>(profile.getType())) +
            ", " + std::to_string(profile.getThreshold().getId()) + ") RETURNING id";

    result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the Profile.");
}

Profile ProfileRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, name, type, thresholdId "
                        "FROM AppProfile "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No profile found with id " + std::to_string(id));
    }

    int profileId = result[0][0].as<int>();
    std::string name = result[0][1].as<std::string>();
    ProfileType type = static_cast<ProfileType>(result[0][2].as<int>());

    Profile profile(name, type);
    profile.setId(profileId);

    return profile;
}