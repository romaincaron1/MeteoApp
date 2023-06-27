//
// Created by Romain Caron on 27/06/2023.
//

#ifndef METEO_CITY_H
#define METEO_CITY_H

#include <string>
#include "Zone.h"

class City : public Zone {
    private:
        std::string zipcode;
        double latitude;
        double longitude;
        short altitude;
    public:
        City(std::string zipcode, double latitude, double longitude, short altitude);
        // Getters
        std::string getZipcode() const;
        double getLatitude() const;
        double getLongitude() const;
        short getAltitude() const;
        // Setters
        void setZipcode(std::string zipcode);
        void setLatitude(double latitude);
        void setLongitude(double longitude);
        void setAltitude(short altitude);

};


#endif //METEO_CITY_H
