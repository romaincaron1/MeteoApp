//
// Created by Romain Caron on 30/06/2023.
//

#include <string>
#include <iostream>
#include <regex>

const uint8_t MIN_PASSWORD_LENGTH = 6;

struct Password {
    std::string value;

    /**
     * @brief Verify if the password is valid (only alphanumeric characters and at least 6 characters)
     * @param value
     * @return true if the password is valid
     */
    bool verifyPassword(std::string value) {
        if (!std::regex_match(value, std::regex("^[a-zA-Z0-9]+$"))) return false;
        if (value.length() < MIN_PASSWORD_LENGTH) return false;
        return true;
    }

    /**
     * @brief Construct a new Password object
     * @param value
     * @throw invalid_argument if the password is not a valid password (only alphanumeric characters and at least 6 characters)
     */
    Password(std::string value) {
        if (!verifyPassword(value)) throw std::invalid_argument("Invalid password format");
        this->value = value;
    }

    void print() {
        std::cout << "Password: " << this->value << std::endl;
    }
};