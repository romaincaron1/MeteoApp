//
// Created by Romain Caron on 27/06/2023.
//

#include "City.h"

// Constructors
City::City(std::string name, std::uint8_t inseeCode, std::string isoCode) : Zone(name, inseeCode, isoCode) {

}

// Getters

std::string City::getZipcode() const {
    return this->zipcode;
}

double City::getLatitude() const {
    return this->latitude;
}

double City::getLongitude() const {
    return this->longitude;
}

short City::getAltitude() const {
    return this->altitude;
}

// Setters

void City::setZipcode(std::string zipcode) {
    this->zipcode = zipcode;
}

void City::setLatitude(double latitude) {
    this->latitude = latitude;
}

void City::setLongitude(double longitude) {
    this->longitude = longitude;
}

void City::setAltitude(short altitude) {
    this->altitude = altitude;
}
