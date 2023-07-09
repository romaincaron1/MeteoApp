#ifndef METEO_THRESHOLD_H
#define METEO_THRESHOLD_H

#include "../Zone/Zone.h"

class Threshold {
    private:
        int id;
        std::optional<Temperature> temperatureMin;
        std::optional<Temperature> temperatureMax;
        std::optional<WindSpeed> windSpeedMin;
        std::optional<WindSpeed> windSpeedMax;
        std::optional<std::uint8_t> humidityMin;
        std::optional<std::uint8_t> humidityMax;
        std::optional<std::uint8_t> precipitationMin;
        std::optional<std::uint8_t> precipitationMax;
    public:
        // Constructors
        Threshold(
                const std::optional<Temperature>& min = std::nullopt,
                const std::optional<Temperature>& max = std::nullopt,
                const std::optional<WindSpeed>& windSpeedMin = std::nullopt,
                const std::optional<WindSpeed>& windSpeedMax = std::nullopt,
                const std::optional<std::uint8_t>& humidityMin = std::nullopt,
                const std::optional<std::uint8_t>& humidityMax = std::nullopt,
                const std::optional<std::uint8_t>& precipitationMin = std::nullopt,
                const std::optional<std::uint8_t>& precipitationMax = std::nullopt);
        // Getters
        int getId() const;
        std::optional<Temperature> getTemperatureMin() const;
        std::optional<Temperature> getTemperatureMax() const;
        std::optional<WindSpeed> getWindSpeedMin() const;
        std::optional<WindSpeed> getWindSpeedMax() const;
        std::optional<std::uint8_t> getHumidityMin() const;
        std::optional<std::uint8_t> getHumidityMax() const;
        std::optional<std::uint8_t> getPrecipitationMin() const;
        std::optional<std::uint8_t> getPrecipitationMax() const;

        // Setters
        void setId(int id);
        void setTemperatureMin(const std::optional<Temperature>& temperatureMin);
        void setTemperatureMax(const std::optional<Temperature>& temperatureMax);
        void setWindSpeedMin(const std::optional<WindSpeed>& windSpeedMin);
        void setWindSpeedMax(const std::optional<WindSpeed>& windSpeedMax);
        void setHumidityMin(const std::optional<std::uint8_t>& humidityMin);
        void setHumidityMax(const std::optional<std::uint8_t>& humidityMax);
        void setPrecipitationMin(const std::optional<std::uint8_t>& precipitationMin);
        void setPrecipitationMax(const std::optional<std::uint8_t>& precipitationMax);
};

#endif // METEO_THRESHOLD_H