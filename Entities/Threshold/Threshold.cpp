#include "Threshold.h"

// Constructors

Threshold::Threshold(const std::optional<Temperature> &min, const std::optional<Temperature> &max,
                     const std::optional<WindSpeed> &windSpeedMin, const std::optional<WindSpeed> &windSpeedMax,
                     const std::optional<std::uint8_t> &humidityMin, const std::optional<std::uint8_t> &humidityMax,
                     const std::optional<std::uint8_t> &precipitationMin,
                     const std::optional<std::uint8_t> &precipitationMax)
        : temperatureMin(min),
          temperatureMax(max),
          windSpeedMin(windSpeedMin),
          windSpeedMax(windSpeedMax),
          humidityMin(humidityMin),
          humidityMax(humidityMax),
          precipitationMin(precipitationMin),
          precipitationMax(precipitationMax) {
}

// Getters

int Threshold::getId() const {
    return id;
}

std::optional<Temperature> Threshold::getTemperatureMin() const {
    if (temperatureMin) {
        return temperatureMin;
    } else {
        return {};
    }
}

std::optional<Temperature> Threshold::getTemperatureMax() const {
    if (temperatureMax) {
        return temperatureMax;
    } else {
        return {};
    }
}

std::optional<WindSpeed> Threshold::getWindSpeedMin() const {
    if (windSpeedMin) {
        return windSpeedMin;
    } else {
        return {};
    }
}

std::optional<WindSpeed> Threshold::getWindSpeedMax() const {
    if (windSpeedMax) {
        return windSpeedMax;
    } else {
        return {};
    }
}

std::optional<std::uint8_t> Threshold::getHumidityMin() const {
    if (humidityMin) {
        return humidityMin;
    } else {
        return {};
    }
}

std::optional<std::uint8_t> Threshold::getHumidityMax() const {
    if (humidityMax) {
        return humidityMax;
    } else {
        return {};
    }
}

std::optional<std::uint8_t> Threshold::getPrecipitationMin() const {
    if (precipitationMin) {
        return precipitationMin;
    } else {
        return {};
    }
}

std::optional<std::uint8_t> Threshold::getPrecipitationMax() const {
    if (precipitationMax) {
        return precipitationMax;
    } else {
        return {};
    }
}

// Setters

void Threshold::setId(int id) {
    Threshold::id = id;
}

void Threshold::setTemperatureMin(const std::optional<Temperature> &temperatureMin) {
    Threshold::temperatureMin = temperatureMin;
}

void Threshold::setTemperatureMax(const std::optional<Temperature> &temperatureMax) {
    Threshold::temperatureMax = temperatureMax;
}

void Threshold::setWindSpeedMin(const std::optional<WindSpeed> &windSpeedMin) {
    Threshold::windSpeedMin = windSpeedMin;
}

void Threshold::setWindSpeedMax(const std::optional<WindSpeed> &windSpeedMax) {
    Threshold::windSpeedMax = windSpeedMax;
}

void Threshold::setHumidityMin(const std::optional<std::uint8_t> &humidityMin) {
    Threshold::humidityMin = humidityMin;
}

void Threshold::setHumidityMax(const std::optional<std::uint8_t> &humidityMax) {
    Threshold::humidityMax = humidityMax;
}

void Threshold::setPrecipitationMin(const std::optional<std::uint8_t> &precipitationMin) {
    Threshold::precipitationMin = precipitationMin;
}

void Threshold::setPrecipitationMax(const std::optional<std::uint8_t> &precipitationMax) {
    Threshold::precipitationMax = precipitationMax;
}
