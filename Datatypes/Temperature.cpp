#include <iostream>
#include "Temperature.h"

void Temperature::print() {
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
