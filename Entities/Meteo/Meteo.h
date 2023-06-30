//
// Created by Romain Caron on 28/06/2023.
//

#ifndef METEO_METEO_H
#define METEO_METEO_H

#include <iostream>
#include "../../Datatypes/Temperature.cpp"
#include "../../Datatypes/WindSpeed.cpp"
#include "../../Datatypes/CloudQuantity.cpp"

class Meteo {
    private:
        std::uint8_t humidity;
        std::uint8_t precipitation;
        Temperature temperature;
        WindSpeed windSpeed;
        CloudQuantity cloudQuantity;
    public:
        // Constructors
        Meteo(std::uint8_t humidity, std::uint8_t precipitation, Temperature temperature, WindSpeed windSpeed,
              CloudQuantity cloudQuantity);
        // Getters
        std::uint8_t getHumidity() const;
        std::uint8_t getPrecipitation() const;
        Temperature getTemperature() const;
        WindSpeed getWindSpeed() const;
        CloudQuantity getCloudQuantity() const;
        // Setters
        void setHumidity(std::uint8_t humidity);
        void setPrecipitation(std::uint8_t precipitation);
        void setTemperature(Temperature temperature);
        void setWindSpeed(WindSpeed windSpeed);
        void setCloudQuantity(CloudQuantity cloudQuantity);
};


#endif //METEO_METEO_H
