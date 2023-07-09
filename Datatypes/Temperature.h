#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum TemperatureUnit {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

struct Temperature {
    short value;
    TemperatureUnit unit;

    Temperature() = default;

    Temperature(short value, TemperatureUnit unit) {
        this->value = value;
        this->unit = unit;
    }

    void print();
};

#endif // TEMPERATURE_H
