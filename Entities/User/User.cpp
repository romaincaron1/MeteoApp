#include "User.h"

User::User(std::string firstname, std::string lastname, Email email, Password password, Profile profile,
           Preference preference) : profile(profile), email(email), password(password), preference(preference) {
    this->firstname = firstname;
    this->lastname = lastname;
}

// Getters

const int User::getId() const {
    return this->id;
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

Profile User::getProfile() const {
    return this->profile;
}

Preference User::getPreference() const {
    return this->preference;
}

// Setters

void User::setId(int id) {
    this->id = id;
}

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

void User::setPreference(Preference preference) {
    this->preference = preference;
}

void User::print() const {
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Firstname: " << this->firstname << std::endl;
    std::cout << "Lastname: " << this->lastname << std::endl;
    std::cout << "Email: " << this->email.value << std::endl;
    std::cout << "Password: " << this->password.value << std::endl;
}
