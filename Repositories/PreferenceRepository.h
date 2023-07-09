//
// Created by Romain Caron on 02/07/2023.
//

#ifndef METEO_PREFERENCEREPOSITORY_H
#define METEO_PREFERENCEREPOSITORY_H

#include <iostream>
#include <vector>
#include "../Entities/Preference/Preference.h"
#include "../Database/DatabaseConnection.h"
#include "ThresholdRepository.h"

class PreferenceRepository {
    public:
        PreferenceRepository();
        int save(const Preference& preference);
        Preference findById(int id);
        void update(const Preference& preference);
        bool remove(const Preference& preference);
};


#endif //METEO_PREFERENCEREPOSITORY_H
