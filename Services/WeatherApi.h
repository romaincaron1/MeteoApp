#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <string>
#include <curl/curl.h>
#include "JSONParser.h"

class WeatherApi {
public:
    WeatherData getWeatherData(const std::string& apiKey, const std::string& location);

private:
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* response);
};

#endif // WEATHERAPI_H
