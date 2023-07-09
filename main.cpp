#include <iostream>

#include "Services/Demo/Demo.h"

using namespace std;
using namespace pqxx;

int main() {
    Demo demo;
    int choice = demo.introduction();
    if (choice == 0) {
        demo.registerUser();
    } else if (choice == 1) {
        demo.loginUser();
    } else if (choice == 2) {
        cout << "Goodbye!" << endl;
        return 0;
    }
    demo.displayUser();
    if (demo.getUser()->getProfile().getType() == ProfileType::NOTYPE) {
        demo.updateThreshold();
    }
    demo.getWeather();

/*    WeatherApi weatherApi;
    DatabaseConnection databaseConnection;
    MeteoRepository meteoRepository(databaseConnection);
    ZoneRepository zoneRepository(databaseConnection);

    // Ask for a location in console
    std::string location;
    std::cout << "Enter a location: ";
    std::cin >> location;

    WeatherData weatherData(weatherApi.getWeatherData("881bad16a54f4606b8a151311230207", location));
    Meteo meteo(weatherData.humidity, weatherData.precipitation, weatherData.temperatureCelsius, weatherData.windSpeedKph, weatherData.cloudQuantity);
    int meteoId = meteoRepository.save(meteo);
    meteo.setId(meteoId);
    std::optional<Meteo> optionalMeteo = meteo;
    Zone zone(weatherData.location.country, weatherData.location.region, weatherData.location.city, weatherData.location.latitude, weatherData.location.longitude, optionalMeteo);
    int zoneId = zoneRepository.save(zone);
    zone.setId(zoneId);*/

/*    DatabaseConnection databaseConnection;
    UserRepository userRepository(databaseConnection);
    ThresholdRepository thresholdRepository(databaseConnection);
    ProfileRepository profileRepository(databaseConnection);
    PreferenceRepository preferenceRepository(databaseConnection);
    ZoneRepository zoneRepository(databaseConnection);
    MeteoRepository meteoRepository(databaseConnection);

    Meteo meteo(0, 0, Temperature(0, CELSIUS), WindSpeed(0, KPH), 0);
    int meteoId = meteoRepository.save(meteo);
    meteo.setId(meteoId);
    std::optional<Meteo> optionalMeteo = meteo;
    Zone zone("France", "Picardie", "Amiens", 49.894067, 2.295753, optionalMeteo);
    int zoneId = zoneRepository.save(zone);
    zone.setId(zoneId);*/
/*    Temperature temperatureMin(0, CELSIUS);
    Temperature temperatureMax(0, CELSIUS);
    WindSpeed windSpeedMin(0, KPH);
    WindSpeed windSpeedMax(0, KPH);
    std::optional<std::uint8_t> humidityMin(0);
    std::optional<std::uint8_t> humidityMax(0);
    std::optional<std::uint8_t> precipitationMin(0);
    std::optional<std::uint8_t> precipitationMax(0);

    // Create initial threshold
    Threshold initialThreshold(temperatureMin,temperatureMax,windSpeedMin,windSpeedMax,humidityMin,humidityMax,precipitationMin,precipitationMax);
    int thresholdId = thresholdRepository.save(initialThreshold);
    initialThreshold.setId(thresholdId);

    // Create initial profile
    Profile initialProfile("Individuel", ProfileType::INDIVIDUAL, initialThreshold);
    int profileId = profileRepository.save(initialProfile);
    initialProfile.setId(profileId);

    // Create initial preference
    Preference initialPreference(initialThreshold);
    int preferenceId = preferenceRepository.save(initialPreference);
    initialPreference.setId(preferenceId);

    // Create initial user
    Email email("caron.romain@free.fr");
    Password password("azerty");
    User user("Romain", "Caron", email, password, initialProfile, initialPreference);
    int userId = userRepository.save(user);
    user.setId(userId);

    user.print();
    user.getProfile().print();*/


    return 0;
}
