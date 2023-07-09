#ifndef WINDSPEED_H
#define WINDSPEED_H

#include <iostream>

enum WindSpeedUnit {
    KPH,
    MPH
};

struct WindSpeed {
    short value;
    WindSpeedUnit unit;

    WindSpeed() = default;

    WindSpeed(short value, WindSpeedUnit unit);

    void print();
};

#endif // WINDSPEED_H
