#include "WeatherApi.h"

size_t WeatherApi::writeCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

WeatherData WeatherApi::getWeatherData(const std::string& apiKey, const std::string& location) {
    std::string apiUrl = "https://api.weatherapi.com/v1/current.json?key=" + apiKey + "&q=" + location;

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            std::cout << "Weather data received successfully." << std::endl;

            JSONParser parser;

            WeatherData weatherData = parser.parseWeatherDataFromJSON(response);

            curl_easy_cleanup(curl);
            curl_global_cleanup();

            return weatherData;
        } else {
            std::cerr << "Failed to retrieve weather data. Error code: " << res << std::endl;
        }
    } else {
        std::cerr << "Failed to initialize curl." << std::endl;
    }

    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return WeatherData();
}
