//
// Created by Romain Caron on 27/06/2023.
//

#include "Zone.h"

Zone::Zone(const std::string country, const std::string region, const std::string city, const double latitude,
           const double longitude, const std::optional<Meteo> &meteo): meteo(meteo) {
    this->country = country;
    this->region = region;
    this->city = city;
    this->latitude = latitude;
    this->longitude = longitude;
}

// Getters

const int Zone::getId() const {
    return id;
}

const std::string Zone::getCountry() const {
    return country;
}

const std::string Zone::getRegion() const {
    return region;
}

const std::string Zone::getCity() const {
    return city;
}

const double Zone::getLatitude() const {
    return latitude;
}

const double Zone::getLongitude() const {
    return longitude;
}

const std::optional<Meteo> Zone::getMeteo() const {
    return meteo;
}

// Setters

void Zone::setId(int id) {
    this->id = id;
}

void Zone::setCountry(std::string country) {
    this->country = country;
}

void Zone::setRegion(std::string region) {
    this->region = region;
}

void Zone::setCity(std::string city) {
    this->city = city;
}

void Zone::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Zone::setLongitude(double longitude) {
    this->longitude = longitude;
}

void Zone::setMeteo(std::optional<Meteo> meteo) {
    this->meteo = meteo;
}

// Methods

void Zone::print() {
    std::cout << "Zone: " << this->country << ", " << this->region << ", " << this->city << std::endl;
    std::cout << "Latitude: " << this->latitude << ", Longitude: " << this->longitude << std::endl;
    if (this->meteo.has_value()) {
        std::cout << "Meteo id: " << std::endl;
        std::cout << this->meteo.value().getId() << std::endl;
    }
}