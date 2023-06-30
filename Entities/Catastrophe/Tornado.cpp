//
// Created by Romain Caron on 30/06/2023.
//

#include "Tornado.h"

Tornado::Tornado(std::string name, float speed, Meteo meteo) : Catastrophe(name, meteo) {
    this->speed = speed;
}

// Getters

const float Tornado::getSpeed() const {
    return this->speed;
}

// Setters

void Tornado::setSpeed(float speed) {
    this->speed = speed;
}
