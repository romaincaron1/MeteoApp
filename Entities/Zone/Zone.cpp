//
// Created by Romain Caron on 27/06/2023.
//

#include "Zone.h"

Zone::Zone(std::string name, std::uint8_t inseeCode, std::string isoCode) {
    this->name = name;
    this->inseeCode = inseeCode;
    this->isoCode = isoCode;
}

// Getters
const std::string Zone::getName() const {
    return name;
}

const std::uint8_t Zone::getInseeCode() const {
    return inseeCode;
}

const std::string Zone::getIsoCode() const {
    return isoCode;
}

// Setters

void Zone::setName(std::string name) {
    this->name = name;
}

void Zone::setInseeCode(std::uint8_t inseeCode) {
    this->inseeCode = inseeCode;
}

void Zone::setIsoCode(std::string isoCode) {
    this->isoCode = isoCode;
}
