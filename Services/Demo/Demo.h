//
// Created by Romain Caron on 09/07/2023.
//

#ifndef METEO_DEMO_H
#define METEO_DEMO_H

#include "../../Database/DatabaseConnection.h"
#include "../../Entities/User/User.h"
#include "../../Entities/Threshold/Threshold.h"
#include "../../Entities/Profile/Profile.h"
#include "../../Entities/Preference/Preference.h"
#include "../../Repositories/UserRepository.h"
#include "../../Repositories/ThresholdRepository.h"
#include "../../Repositories/ProfileRepository.h"
#include "../../Repositories/PreferenceRepository.h"
#include "../../Repositories/MeteoRepository.h"
#include "../../Repositories/ZoneRepository.h"
#include "../WeatherApi.h"

using namespace std;

class Demo {
    private:
        ThresholdRepository thresholdRepository;
        PreferenceRepository preferenceRepository;
        ProfileRepository profileRepository;
        UserRepository userRepository;
        User *user;
    public:
        Demo();
        int introduction();
        void registerUser();
        void loginUser();
        void updateThreshold();
        void getWeather();
        void displayUser();
        User *getUser();
};


#endif //METEO_DEMO_H
