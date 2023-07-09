#include "Preference.h"

// Constructors

Preference::Preference(Threshold threshold) {
    this->threshold = threshold;
}

// Getters

int Preference::getId() const {
    return this->id;
}

Threshold Preference::getThreshold() const {
    return this->threshold;
}


// Setters

void Preference::setId(int id) {
    this->id = id;
}

void Preference::setThreshold(Threshold threshold) {
    this->threshold = threshold;
}
