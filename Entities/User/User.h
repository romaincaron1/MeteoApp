#ifndef METEO_USER_H
#define METEO_USER_H

#include <iostream>
#include <string>
#include "../Preference/Preference.h"
#include "../Profile/Profile.h"
#include "../../Datatypes/Email.cpp"
#include "../../Datatypes/Password.cpp"

class User {
    private:
        std::string firstname;
        std::string lastname;
        Email email;
        Password password;
        Profile profile;
    public:
        User(std::string firstname, std::string lastname, Email email, Password password, Profile profile);
        // Getters
        const std::string getFirstname() const;
        const std::string getLastname() const;
        const Email getEmail() const;
        const Password getPassword() const;
        const Profile getProfile() const;
        // Setters
        void setFirstname(std::string firstname);
        void setLastname(std::string lastname);
        void setEmail(Email email);
        void setPassword(Password password);
        void setProfile(Profile profile);
        void print() const;

};


#endif //METEO_USER_H
