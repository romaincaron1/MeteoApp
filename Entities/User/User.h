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
        int id;
        std::string firstname;
        std::string lastname;
        Email email;
        Password password;
        Profile profile;
        Preference preference;
    public:
        User(std::string firstname, std::string lastname, Email email, Password password, Profile profile, Preference preference);
        // Getters
        const int getId() const;
        const std::string getFirstname() const;
        const std::string getLastname() const;
        const Email getEmail() const;
        const Password getPassword() const;
        Profile getProfile() const;
        Preference getPreference() const;
        // Setters
        void setId(int id);
        void setFirstname(std::string firstname);
        void setLastname(std::string lastname);
        void setEmail(Email email);
        void setPassword(Password password);
        void setProfile(Profile profile);
        void setPreference(Preference preference);
        void print() const;

};


#endif //METEO_USER_H
