#include "User.h"

// Getters

User::User(std::string firstname, std::string lastname, Email email, Password password, Profile profile) : profile(profile), email(email), password(password) {
    this->firstname = firstname;
    this->lastname = lastname;
}

const std::string User::getFirstname() const {
    return this->firstname;
}

const std::string User::getLastname() const {
    return this->lastname;
}

const Email User::getEmail() const {
    return this->email.value;
}

const Password User::getPassword() const {
    return this->password.value;
}

const Profile User::getProfile() const {
    return this->profile;
}

// Setters

void User::setFirstname(std::string firstname) {
    this->firstname = firstname;
}

void User::setLastname(std::string lastname) {
    this->lastname = lastname;
}

void User::setEmail(Email email) {
    this->email = email;
}

void User::setPassword(Password password) {
    this->password = password;
}

void User::setProfile(Profile profile) {
    this->profile = profile;
}

void User::print() const {
    std::cout << "Firstname: " << this->firstname << std::endl;
    std::cout << "Lastname: " << this->lastname << std::endl;
    std::cout << "Email: " << this->email.value << std::endl;
    std::cout << "Password: " << this->password.value << std::endl;
}
