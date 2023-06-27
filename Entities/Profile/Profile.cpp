//
// Created by Romain Caron on 15/06/2023.
//

#include "Profile.h"

// Constructors
Profile::Profile(std::string name, ProfileType type, Threshold threshold) {
    this->name = name;
    this->type = type;
    this->threshold = threshold;
}

// Getters

std::string Profile::getName() const {
    return this->name;
}

ProfileType Profile::getType() const {
    return this->type;
}

Threshold Profile::getThreshold() const {
    return this->threshold;
}

// Setters

void Profile::setName(std::string name) {
    this->name = name;
}

void Profile::setType(ProfileType type) {
    this->type = type;
}

void Profile::setThreshold(Threshold threshold) {
    this->threshold = threshold;
}