//
// Created by Romain Caron on 30/06/2023.
//

#include "Tsunami.h"

Tsunami::Tsunami(std::string name, float waveHeight, Meteo meteo) : Catastrophe(name, meteo) {
    this->waveHeight = waveHeight;
}
