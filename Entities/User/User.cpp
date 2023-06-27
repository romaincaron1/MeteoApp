#include "User.h"

// Getters

User::User(std::string firstname, std::string lastname, std::string email, std::string password, Profile profile) : profile(profile) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->email = email;
    this->password = password;
}

std::string User::getFirstname() const {
    return this->firstname;
}

std::string User::getLastname() const {
    return this->lastname;
}

std::string User::getEmail() const {
    return this->email;
}

std::string User::getPassword() const {
    return this->password;
}

Profile User::getProfile() const {
    return this->profile;
}

// Setters

void User::setFirstname(std::string firstname) {
    this->firstname = firstname;
}

void User::setLastname(std::string lastname) {
    this->lastname = lastname;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setPassword(std::string password) {
    this->password = password;
}

void User::setProfile(Profile profile) {
    this->profile = profile;
}

void User::print() const {
    std::cout << "Firstname: " << this->firstname << std::endl;
    std::cout << "Lastname: " << this->lastname << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Password: " << this->password << std::endl;
}
