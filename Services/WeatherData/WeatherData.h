//
// Created by Romain Caron on 05/07/2023.
//

#include <string>
#include "../../Datatypes/Temperature.h"
#include "../../Datatypes/WindSpeed.h"

struct WeatherData {

    struct Location {
        std::string city;
        std::string region;
        std::string country;
        double latitude;
        double longitude;
    };
    Location location;
    Temperature temperatureCelsius;
    Temperature temperatureFahrenheit;
    WindSpeed windSpeedMph;
    WindSpeed windSpeedKph;
    double precipitation;
    uint8_t humidity;
    uint cloudQuantity;

    WeatherData();
    WeatherData(const std::string &city, const std::string &region, const std::string &country,
                double latitude, double longitude, short temperatureCelsius,
                short temperatureFahrenheit, short windSpeedMph,
                short windSpeedKph, double precipitation, uint8_t humidity,
                uint cloudQuantity);
};
