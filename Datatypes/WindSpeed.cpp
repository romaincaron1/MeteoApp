#include "WindSpeed.h"

WindSpeed::WindSpeed(short value, WindSpeedUnit unit) {
    this->value = value;
    this->unit = unit;
}

void WindSpeed::print() {
    switch (unit) {
        case KPH:
            std::cout << value << "kph" << std::endl;
            break;
        case MPH:
            std::cout << value << "mph" << std::endl;
            break;
    }
}
