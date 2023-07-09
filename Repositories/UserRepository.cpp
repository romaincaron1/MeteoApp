//
// Created by Romain Caron on 01/07/2023.
//

#include "UserRepository.h"

UserRepository::UserRepository() {}

int UserRepository::save(const User &user) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "INSERT INTO AppUser (firstname, lastname, email, password, profileId, preferenceId) VALUES ('" +
                        user.getFirstname() + "', '" +
                        user.getLastname() + "', '" +
                        user.getEmail().value + "', '" +
                        user.getPassword().value + "', " +
                        std::to_string(user.getProfile().getId()) + ", " +
                        std::to_string(user.getPreference().getId()) + ") RETURNING id";

    result res = dbConnection->execute(query);

    if (!res.empty()) {
        int insertedId = res[0][0].as<int>();
        return insertedId;
    }

    throw std::runtime_error("Failed to retrieve the inserted ID after saving the User.");
}

User UserRepository::findById(int id) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, firstname, lastname, email, password, profileId, preferenceId "
                        "FROM AppUser "
                        "WHERE id = " + std::to_string(id);

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No user found with id " + std::to_string(id));
    }

    int userId = result[0][0].as<int>();
    std::string firstname = result[0][1].as<std::string>();
    std::string lastname = result[0][2].as<std::string>();
    std::string email = result[0][3].as<std::string>();
    std::string password = result[0][4].as<std::string>();
    int profileId = result[0][5].as<int>();
    int preferenceId = result[0][6].as<int>();

    ProfileRepository profileRepository;
    PreferenceRepository preferenceRepository;

    Profile profile = profileRepository.findById(profileId);
    Preference preference = preferenceRepository.findById(preferenceId);

    User user(firstname, lastname, Email(email), Password(password), profile, preference);
    user.setId(userId);

    return user;
}

User UserRepository::findByEmail(const Email &email) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "SELECT id, firstname, lastname, email, password, profileId, preferenceId "
                        "FROM AppUser "
                        "WHERE email = '" + email.value + "'";

    pqxx::result result = dbConnection->execute(query);

    if (result.empty()) {
        throw std::invalid_argument("No user found with email " + email.value);
    }

    int userId = result[0][0].as<int>();
    std::string firstname = result[0][1].as<std::string>();
    std::string lastname = result[0][2].as<std::string>();
    std::string password = result[0][4].as<std::string>();
    int profileId = result[0][5].as<int>();
    int preferenceId = result[0][6].as<int>();

    ProfileRepository profileRepository;
    PreferenceRepository preferenceRepository;

    Profile profile = profileRepository.findById(profileId);
    Preference preference = preferenceRepository.findById(preferenceId);

    User user(firstname, lastname, email, Password(password), profile, preference);
    user.setId(userId);

    return user;
}

void UserRepository::update(const User &user) {
    auto dbConnection = DatabaseConnection::getInstance();
    std::string query = "UPDATE AppUser "
                        "SET firstname = '" + user.getFirstname() +
                        "', lastname = '" + user.getLastname() +
                        "', email = '" +
                        user.getEmail().value +
                        "', password = '" + user.getPassword().value +
                        "', profileid = " +
                        std::to_string(user.getProfile().getId()) +
                        ", preferenceid = " +
                        std::to_string(user.getPreference().getId()) +
                        " WHERE id = " + std::to_string(user.getId());

    dbConnection->execute(query);
}

bool UserRepository::remove(const User &user) {
    auto dbConnection = DatabaseConnection::getInstance();
    try {
        std::string query = "DELETE FROM users WHERE id = " + std::to_string(user.getId());
        dbConnection->execute(query);
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Error while deleting the user : " << e.what() << std::endl;
        return false;
    }
}
