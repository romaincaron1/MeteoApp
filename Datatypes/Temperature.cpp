#include <iostream>

enum TemperatureUnit {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

struct Temperature {
    short value;
    TemperatureUnit unit;

    Temperature(short value, TemperatureUnit unit) {
        this->value = value;
        this->unit = unit;
    }

    void print() {
        switch (unit) {
            case CELSIUS:
                std::cout << value << "°C" << std::endl;
                break;
            case FAHRENHEIT:
                std::cout << value << "°F" << std::endl;
                break;
            case KELVIN:
                std::cout << value << "K" << std::endl;
                break;
        }
    }
};