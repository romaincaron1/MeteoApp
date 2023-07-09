//
// Created by Romain Caron on 27/06/2023.
//

#ifndef METEO_ZONE_H
#define METEO_ZONE_H

#include <iostream>
#include <string>

#include "../Meteo/Meteo.h"

class Zone {
    private:
        int id;
        std::string country;
        std::string region;
        std::string city;
        double latitude;
        double longitude;
        std::optional<Meteo> meteo;

    public:
        // Constructors
        Zone(const std::string country, const std::string region, const std::string city, const double latitude, const double longitude, const std::optional<Meteo> &meteo);

        // Getters
        const int getId() const;
        const std::string getCountry() const;
        const std::string getRegion() const;
        const std::string getCity() const;
        const double getLatitude() const;
        const double getLongitude() const;
        const std::optional<Meteo> getMeteo() const;

        // Setters
        void setId(int id);
        void setCountry(std::string country);
        void setRegion(std::string region);
        void setCity(std::string city);
        void setLatitude(double latitude);
        void setLongitude(double longitude);
        void setMeteo(std::optional<Meteo> meteo);

        // Methods
        void print();
};


#endif //METEO_ZONE_H
