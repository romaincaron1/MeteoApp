//
// Created by Romain Caron on 27/06/2023.
//

#ifndef METEO_ZONE_H
#define METEO_ZONE_H

#include <iostream>
#include <string>

class Zone {
    private:
        std::string name;
        std::uint8_t inseeCode;
        std::string isoCode;

    public:
        Zone() = default;
        Zone(std::string name, std::uint8_t inseeCode, std::string isoCode);
        // Getters
        virtual const std::string getName() const;
        virtual const std::uint8_t getInseeCode() const;
        virtual const std::string getIsoCode() const;
        // Setters
        virtual void setName(std::string name);
        virtual void setInseeCode(std::uint8_t inseeCode);
        virtual void setIsoCode(std::string isoCode);
};


#endif //METEO_ZONE_H
