//
// Created by Romain Caron on 05/07/2023.
//

#include "JSONParser.h"

WeatherData JSONParser::parseWeatherDataFromJSON(const std::string &jsonString) {
    WeatherData weatherData;

    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(jsonString, root);
    if (!parsingSuccessful) {
        std::cerr << "Failed to parse JSON data: " << reader.getFormattedErrorMessages() << std::endl;
        return weatherData;
    }

    // Parse location data
    const Json::Value &locationNode = root["location"];
    weatherData.location.city = locationNode["name"].asString();
    weatherData.location.region = locationNode["region"].asString();
    weatherData.location.country = locationNode["country"].asString();
    weatherData.location.latitude = locationNode["lat"].asDouble();
    weatherData.location.longitude = locationNode["lon"].asDouble();

    // Parse current weather data
    const Json::Value &currentWeatherNode = root["current"];
    weatherData.temperatureCelsius.value = currentWeatherNode["temp_c"].asDouble();
    weatherData.temperatureFahrenheit.value = currentWeatherNode["temp_f"].asDouble();
    weatherData.windSpeedMph.value = currentWeatherNode["wind_mph"].asDouble();
    weatherData.windSpeedKph.value = currentWeatherNode["wind_kph"].asDouble();
    weatherData.precipitation = currentWeatherNode["precip_mm"].asDouble();
    weatherData.humidity = currentWeatherNode["humidity"].asUInt();
    weatherData.cloudQuantity = currentWeatherNode["cloud"].asUInt();

    return weatherData;
}
