//
// Created by Romain Caron on 01/07/2023.
//

#ifndef METEO_USERREPOSITORY_H
#define METEO_USERREPOSITORY_H

#include <iostream>
#include <vector>
#include "../Entities/User/User.h"
#include "../Database/DatabaseConnection.h"
#include "ProfileRepository.h"
#include "PreferenceRepository.h"

class UserRepository {
    public:
        UserRepository();
        int save(const User& user);
        User findById(int id);
        User findByEmail(const Email& email);
        void update(const User& user);
        bool remove(const User& user);
};


#endif //METEO_USERREPOSITORY_H
