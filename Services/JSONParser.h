//
// Created by Romain Caron on 06/07/2023.
//

#ifndef METEO_JSONPARSER_H
#define METEO_JSONPARSER_H

#include <iostream>
#include <json/json.h>
#include "WeatherData/WeatherData.h"

class JSONParser {
public:
    WeatherData parseWeatherDataFromJSON(const std::string& jsonString);
};


#endif //METEO_JSONPARSER_H
