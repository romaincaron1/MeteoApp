#ifndef METEO_PROFILE_H
#define METEO_PROFILE_H

#include "../Threshold/Threshold.h"
#include "../../Repositories/ThresholdRepository.h"
#include <string>
#include <iostream>

enum class ProfileType {
    CLOUDPROVIDER = 0,
    ENERGYPRODUCER = 1,
    INDIVIDUAL = 2,
    NOTYPE = 3
};

class Profile {
    private:
        int id{};
        std::string name;
        ProfileType type;
        Threshold threshold;
    public:
        Profile(std::string name, ProfileType type);
        // Getters
        int getId() const;
        std::string getName() const;
        ProfileType getType() const;
        Threshold getThreshold() const;
        // Setters
        void setId(int id);
        void setName(std::string name);
        void setType(ProfileType type);
        void setThreshold(Threshold threshold);

        void print() const;
};


#endif //METEO_PROFILE_H
