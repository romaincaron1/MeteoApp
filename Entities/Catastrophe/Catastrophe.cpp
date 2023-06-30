//
// Created by Romain Caron on 28/06/2023.
//

#include "Catastrophe.h"

Catastrophe::Catastrophe(std::string name, Meteo meteo) : meteo(meteo) {
    this->name = name;
}

// Getters

std::string Catastrophe::getName() const {
    return this->name;
}

// Setters

void Catastrophe::setName(std::string name) {
    this->name = name;
}
