//
// Created by Romain Caron on 28/06/2023.
//

#include "Meteo.h"

Meteo::Meteo(std::uint8_t humidity, std::uint8_t precipitation, Temperature temperature, WindSpeed windSpeed,
             CloudQuantity cloudQuantity) : temperature(temperature), windSpeed(windSpeed), cloudQuantity(cloudQuantity) {
    this->humidity = humidity;
    this->precipitation = precipitation;
}

// Getters

std::uint8_t Meteo::getHumidity() const {
    return this->humidity;
}

std::uint8_t Meteo::getPrecipitation() const {
    return this->precipitation;
}

Temperature Meteo::getTemperature() const {
    return this->temperature;
}

WindSpeed Meteo::getWindSpeed() const {
    return this->windSpeed;
}

CloudQuantity Meteo::getCloudQuantity() const {
    return this->cloudQuantity;
}

// Setters

void Meteo::setHumidity(std::uint8_t humidity) {
    this->humidity = humidity;
}

void Meteo::setPrecipitation(std::uint8_t precipitation) {
    this->precipitation = precipitation;
}

void Meteo::setTemperature(Temperature temperature) {
    this->temperature = temperature;
}

void Meteo::setWindSpeed(WindSpeed windSpeed) {
    this->windSpeed = windSpeed;
}

void Meteo::setCloudQuantity(CloudQuantity cloudQuantity) {
    this->cloudQuantity = cloudQuantity;
}