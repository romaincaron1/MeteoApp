#ifndef METEO_PROFILE_H
#define METEO_PROFILE_H

#include "../Threshold/Threshold.h"
#include <string>
#include <iostream>

enum class ProfileType {
    CLOUDPROVIDER = 0,
    ENERGYPRODUCER = 1,
    INDIVIDUAL = 2,
};

class Profile {
    private:
        std::string name;
        ProfileType type;
        Threshold threshold;
    public:
        Profile(std::string name, ProfileType type, Threshold threshold);
        // Getters
        std::string getName() const;
        ProfileType getType() const;
        Threshold getThreshold() const;
        // Setters
        void setName(std::string name);
        void setType(ProfileType type);
        void setThreshold(Threshold threshold);
};


#endif //METEO_PROFILE_H
