//
// Created by Romain Caron on 15/06/2023.
//

#include "Profile.h"

Profile::Profile(std::string name, ProfileType type) {
    ThresholdRepository thresholdRepository;

    this->name = name;
    this->type = type;
    // Set threshold based on profile type
    if (type == ProfileType::INDIVIDUAL) {
        Temperature temperatureMin(0, CELSIUS);
        Temperature temperatureMax(30, CELSIUS);
        WindSpeed windSpeedMin(6, KPH);
        WindSpeed windSpeedMax(50, KPH);
        std::optional<std::uint8_t> humidityMin(30);
        std::optional<std::uint8_t> humidityMax(70);
        std::optional<std::uint8_t> precipitationMin(0);
        std::optional<std::uint8_t> precipitationMax(10);
        Threshold individualThreshold(temperatureMin,temperatureMax,windSpeedMin,windSpeedMax,humidityMin,humidityMax,precipitationMin,precipitationMax);
        int thresholdId = thresholdRepository.save(individualThreshold);
        individualThreshold.setId(thresholdId);
        this->threshold = individualThreshold;
    } else if (type == ProfileType::CLOUDPROVIDER) {
        Temperature temperatureMin(-10, CELSIUS);
        Temperature temperatureMax(20, CELSIUS);
        WindSpeed windSpeedMin(0, KPH);
        WindSpeed windSpeedMax(100, KPH);
        std::optional<std::uint8_t> humidityMin(20);
        std::optional<std::uint8_t> humidityMax(80);
        std::optional<std::uint16_t> precipitationMin(0);
        std::optional<std::uint16_t> precipitationMax(50);
        Threshold cloudProviderThreshold(temperatureMin,temperatureMax,windSpeedMin,windSpeedMax,humidityMin,humidityMax,precipitationMin,precipitationMax);
        int thresholdId = thresholdRepository.save(cloudProviderThreshold);
        cloudProviderThreshold.setId(thresholdId);
        this->threshold = cloudProviderThreshold;
    } else if (type == ProfileType::ENERGYPRODUCER) {
        Temperature temperatureMin(-5, CELSIUS);
        Temperature temperatureMax(35, CELSIUS);
        WindSpeed windSpeedMin(0, KPH);
        WindSpeed windSpeedMax(80, KPH);
        std::optional<std::uint8_t> humidityMin(20);
        std::optional<std::uint8_t> humidityMax(80);
        std::optional<std::uint16_t> precipitationMin(0);
        std::optional<std::uint16_t> precipitationMax(30);
        Threshold energyProducerThreshold(temperatureMin,temperatureMax,windSpeedMin,windSpeedMax,humidityMin,humidityMax,precipitationMin,precipitationMax);
        int thresholdId = thresholdRepository.save(energyProducerThreshold);
        energyProducerThreshold.setId(thresholdId);
        this->threshold = energyProducerThreshold;
    } else if (type == ProfileType::NOTYPE) {
        Temperature temperatureMin(0, CELSIUS);
        Temperature temperatureMax(0, CELSIUS);
        WindSpeed windSpeedMin(0, KPH);
        WindSpeed windSpeedMax(0, KPH);
        std::optional<std::uint8_t> humidityMin(0);
        std::optional<std::uint8_t> humidityMax(0);
        std::optional<std::uint8_t> precipitationMin(0);
        std::optional<std::uint8_t> precipitationMax(0);
        Threshold initialThreshold(temperatureMin,temperatureMax,windSpeedMin,windSpeedMax,humidityMin,humidityMax,precipitationMin,precipitationMax);
        int thresholdId = thresholdRepository.save(initialThreshold);
        initialThreshold.setId(thresholdId);
        this->threshold = initialThreshold;
    }
}


// Getters

int Profile::getId() const {
    return this->id;
}

std::string Profile::getName() const {
    return this->name;
}

ProfileType Profile::getType() const {
    return this->type;
}

Threshold Profile::getThreshold() const {
    return this->threshold;
}

// Setters

void Profile::setId(int id) {
    this->id = id;
}

void Profile::setName(std::string name) {
    this->name = name;
}

void Profile::setType(ProfileType type) {
    this->type = type;
}

void Profile::setThreshold(Threshold threshold) {
    this->threshold = threshold;
}

void Profile::print() const {
    std::cout << "Profile: " << this->name << std::endl;
    std::cout << "Type: " << (int) this->type << std::endl;
}