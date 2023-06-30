//
// Created by Romain Caron on 30/06/2023.
//

#include <string>
#include <regex>
#include <iostream>

struct Email {
    std::string value;

    bool verifyEmail(std::string value) {
        return std::regex_match(value, std::regex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$"));
    }

    Email(std::string value) {
        if (!verifyEmail(value)) {
            throw std::invalid_argument("Invalid email format");
        }
        this->value = value;
    }

    void print() {
        std::cout << "Email: " << this->value << std::endl;
    }
};