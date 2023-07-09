//
// Created by Romain Caron on 05/07/2023.
//

#include "WeatherData.h"

WeatherData::WeatherData() = default;

WeatherData::WeatherData(const std::string &city, const std::string &region, const std::string &country,
                         double latitude, double longitude, short temperatureCelsius,
                         short temperatureFahrenheit, short windSpeedMph,
                         short windSpeedKph, double precipitation, uint8_t humidity,
                         uint cloudQuantity)
        : location{city, region, country, latitude, longitude},
          temperatureCelsius(temperatureCelsius, CELSIUS),
          temperatureFahrenheit(temperatureFahrenheit, FAHRENHEIT),
          windSpeedMph(windSpeedMph, MPH),
          windSpeedKph(windSpeedKph, KPH),
          precipitation(precipitation),
          humidity(humidity),
          cloudQuantity(cloudQuantity) {
}
