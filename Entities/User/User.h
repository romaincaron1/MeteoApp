#ifndef METEO_USER_H
#define METEO_USER_H

#include <iostream>
#include <string>
#include "../Preference/Preference.h"
#include "../Profile/Profile.h"

class User {
    private:
        std::string firstname;
        std::string lastname;
        std::string email;
        std::string password;
        Profile profile;
    public:
        User(std::string firstname, std::string lastname, std::string email, std::string password, Profile profile);
        // Getters
        std::string getFirstname() const;
        std::string getLastname() const;
        std::string getEmail() const;
        std::string getPassword() const;
        Profile getProfile() const;
        // Setters
        void setFirstname(std::string firstname);
        void setLastname(std::string lastname);
        void setEmail(std::string email);
        void setPassword(std::string password);
        void setProfile(Profile profile);
        void print() const;

};


#endif //METEO_USER_H
