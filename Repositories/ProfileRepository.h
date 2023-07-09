//
// Created by Romain Caron on 01/07/2023.
//

#ifndef METEO_PROFILEREPOSITORY_H
#define METEO_PROFILEREPOSITORY_H

#include <iostream>
#include <vector>
#include "../Entities/Profile/Profile.h"
#include "../Database/DatabaseConnection.h"
#include "ThresholdRepository.h"

class ProfileRepository {
    public:
        ProfileRepository();
        int save(const Profile& profile);
        Profile findById(int id);
        void update(const Profile& profile);
        bool remove(const Profile& profile);
};


#endif //METEO_PROFILEREPOSITORY_H
