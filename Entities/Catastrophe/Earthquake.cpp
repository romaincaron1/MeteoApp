//
// Created by Romain Caron on 30/06/2023.
//

#include "Earthquake.h"

Earthquake::Earthquake(std::string name, int magnitude, Meteo meteo) : Catastrophe(name, meteo) {
    this->magnitude = magnitude;
}

// Getters

const int Earthquake::getMagnitude() const {
    return this->magnitude;
}

// Setters

void Earthquake::setMagnitude(int magnitude) {
    this->magnitude = magnitude;
}
