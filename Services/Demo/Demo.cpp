//
// Created by Romain Caron on 09/07/2023.
//

#include "Demo.h"

Demo::Demo() {

}

/**
 * Display the introduction message
 * @return the user's choice
 */
int Demo::introduction() {
    cout << "Welcome to Meteo!" << endl;
    cout << "Enter 0 to register, 1 to login or 2 to exit: ";
    int choice;
    cin >> choice;
    while (choice < 0 || choice > 2) {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }
    return choice;
}

/**
 * Register a new user
 * @return void
 */
void Demo::registerUser() {
    cout << "Enter your email: ";
    string emailStr;
    cin >> emailStr;
    cout << "Enter your password: ";
    string passwordStr;
    cin >> passwordStr;
    cout << "Enter your first name: ";
    string firstName;
    cin >> firstName;
    cout << "Enter your last name: ";
    string lastName;
    cin >> lastName;
    cout << "Enter your profile type (0: Cloud provider, 1: Energy producer, 2: Individual, 3: No profile) ";
    int profileType;
    cin >> profileType;
    Email email = Email(emailStr);
    Password password = Password(passwordStr);
    while (profileType < 0|| profileType > 3) {
        cout << "Please enter a valid profile type: ";
        cin >> profileType;
    }
    auto profile = Profile(profileType == 0 ? "Cloud provider" : profileType == 1 ? "Energy producer" : profileType == 2 ? "Individual" : "no profile", (ProfileType) profileType);
    int profileId = profileRepository.save(profile);
    profile.setId(profileId);
    auto preference = Preference(profile.getThreshold());
    int preferenceId = preferenceRepository.save(preference);
    preference.setId(preferenceId);
    auto user = User(firstName, lastName, email, password, profile, preference);
    int userId = userRepository.save(user);
    user.setId(userId);
    User* newUser = new User(user);
    this->user = newUser;
    cout << "Welcome, " << firstName << " " << lastName << " !" << endl;
}

void Demo::loginUser() {
    cout << "Enter your email: ";
    string emailStr;
    cin >> emailStr;
    cout << "Enter your password: ";
    string password;
    cin >> password;
    try {
        Email email = Email(emailStr);
        try {
            User foundUser = userRepository.findByEmail(email);
            User* user = new User(foundUser);
            if (foundUser.getPassword().value == password) {
                this->user = user;
                cout << "Welcome back, " << foundUser.getFirstname() << " " << foundUser.getLastname() << " !" << endl;
            } else {
                cout << "Wrong password" << endl;
                return;
            }
        } catch (const out_of_range& e) {
            cout << "User not found" << endl;
            return;
        }
    } catch (const invalid_argument& e) {
        cout << "Invalid email" << endl;
        return;
    }

}

void Demo::updateThreshold() {
    cout << "Do you want to update your threshold? (0: No, 1: Yes) ";
    int choice;
    cin >> choice;
    while (choice < 0 || choice > 1) {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 0) {
        return;
    }
    cout << "Enter the minimum temperature: ";
    short minTemp;
    cin >> minTemp;
    Temperature minTemperature = Temperature(minTemp, CELSIUS);
    cout << "Enter the maximum temperature: ";
    short maxTemp;
    cin >> maxTemp;
    Temperature maxTemperature = Temperature(maxTemp, CELSIUS);
    cout << "Enter the minimum wind speed: ";
    short minWind;
    cin >> minWind;
    WindSpeed minWindSpeed = WindSpeed(minWind, KPH);
    cout << "Enter the maximum wind speed: ";
    short maxWind;
    cin >> maxWind;
    WindSpeed maxWindSpeed = WindSpeed(maxWind, KPH);
    cout << "Enter the minimum humidity: ";
    short minHumidity;
    cin >> minHumidity;
    cout << "Enter the maximum humidity: ";
    short maxHumidity;
    cin >> maxHumidity;
    cout << "Enter the minimum precipitation: ";
    short minPrecipitation;
    cin >> minPrecipitation;
    cout << "Enter the maximum precipitation: ";
    short maxPrecipitation;
    cin >> maxPrecipitation;
    auto threshold = Threshold(minTemperature, maxTemperature, minWindSpeed, maxWindSpeed, minHumidity, maxHumidity, minPrecipitation, maxPrecipitation);
    threshold.setId(user->getPreference().getThreshold().getId());
    user->getPreference().setThreshold(threshold);
    user->getProfile().setThreshold(threshold);
    thresholdRepository.update(threshold);
    cout << "Threshold updated" << endl;
    cout << user->getFirstname() << endl;
}

void Demo::getWeather() {
    WeatherApi weatherApi;
    MeteoRepository meteoRepository;
    ZoneRepository zoneRepository;

    // Ask for a location in console
    std::string location;
    std::cout << "Enter a location to get the weather: ";
    std::cin >> location;

    WeatherData weatherData(weatherApi.getWeatherData("881bad16a54f4606b8a151311230207", location));
    Meteo meteo(weatherData.humidity, weatherData.precipitation, weatherData.temperatureCelsius, weatherData.windSpeedKph, weatherData.cloudQuantity);
    int meteoId = meteoRepository.save(meteo);
    meteo.setId(meteoId);
    std::optional<Meteo> optionalMeteo = meteo;
    Zone zone(weatherData.location.country, weatherData.location.region, weatherData.location.city, weatherData.location.latitude, weatherData.location.longitude, optionalMeteo);
    int zoneId = zoneRepository.save(zone);
    zone.setId(zoneId);

    // Display the weather
    std::cout << "The weather in " << location << " is: " << std::endl;
    std::cout << "Temperature: " << weatherData.temperatureCelsius.value << "°C" << std::endl;
    std::cout << "Wind speed: " << weatherData.windSpeedKph.value << "kph" << std::endl;
    std::cout << "Humidity: " << weatherData.humidity << "%" << std::endl;
    std::cout << "Precipitation: " << weatherData.precipitation << "%" << std::endl;
    std::cout << "Cloud quantity: " << weatherData.cloudQuantity << "%" << std::endl;

    if (user->getProfile().getThreshold().getTemperatureMin().value().value > weatherData.temperatureCelsius.value) {
        std::cout << "The temperature is too low" << std::endl;
    }

    if (user->getProfile().getThreshold().getTemperatureMax().value().value < weatherData.temperatureCelsius.value) {
        std::cout << "The temperature is too high" << std::endl;
    }

    if (user->getProfile().getThreshold().getWindSpeedMin().value().value > weatherData.windSpeedKph.value) {
        std::cout << "The wind speed is too low" << std::endl;
    }

    if (user->getProfile().getThreshold().getWindSpeedMax().value().value < weatherData.windSpeedKph.value) {
        std::cout << "The wind speed is too high" << std::endl;
    }

    if (user->getProfile().getThreshold().getHumidityMin().value() > weatherData.humidity) {
        std::cout << "The humidity is too low" << std::endl;
    }

    if (user->getProfile().getThreshold().getHumidityMax().value() < weatherData.humidity) {
        std::cout << "The humidity is too high" << std::endl;
    }

    if (user->getProfile().getThreshold().getPrecipitationMin().value() > weatherData.precipitation) {
        std::cout << "The precipitation is too low" << std::endl;
    }

    if (user->getProfile().getThreshold().getPrecipitationMax().value() < weatherData.precipitation) {
        std::cout << "The precipitation is too high" << std::endl;
    }
}

void Demo::displayUser() {
    cout << "Your email: " << user->getEmail().value << endl;
    cout << "Your password: " << user->getPassword().value << endl;
    cout << "Your first name: " << user->getFirstname() << endl;
    cout << "Your last name: " << user->getLastname() << endl;
    cout << "Your profile type: " << user->getProfile().getName() << endl;
}

User *Demo::getUser() {
    return user;
}









