//
// Created by Romain Caron on 28/06/2023.
//

#ifndef METEO_METEO_H
#define METEO_METEO_H

#include <iostream>
#include "../../Datatypes/Temperature.h"
#include "../../Datatypes/WindSpeed.h"
#include "../../Datatypes/CloudQuantity.cpp"

class Meteo {
    private:
        int id;
        Temperature temperature;
        WindSpeed windSpeed;
        std::uint8_t humidity;
        std::uint8_t precipitation;
        std::uint8_t cloudQuantity;
    public:
        // Constructors
        Meteo(std::uint8_t humidity, std::uint8_t precipitation, Temperature temperature, WindSpeed windSpeed,
              std::uint8_t cloudQuantity);
        // Getters
        int getId() const;
        Temperature getTemperature() const;
        WindSpeed getWindSpeed() const;
        std::uint8_t getHumidity() const;
        std::uint8_t getPrecipitation() const;
        std::uint8_t getCloudQuantity() const;
        // Setters
        void setId(int id);
        void setTemperature(Temperature temperature);
        void setWindSpeed(WindSpeed windSpeed);
        void setHumidity(std::uint8_t humidity);
        void setPrecipitation(std::uint8_t precipitation);
        void setCloudQuantity(std::uint8_t cloudQuantity);
};


#endif //METEO_METEO_H
