#include <iostream>

enum WindSpeedUnit {
    KMH,
    NODE,
    MPS
};

struct WindSpeed {
    short value;
    WindSpeedUnit unit;

    WindSpeed(short value, WindSpeedUnit unit) {
        this->value = value;
        this->unit = unit;
    }

    void print() {
        switch (unit) {
            case KMH:
                std::cout << value << "km/h" << std::endl;
                break;
            case NODE:
                std::cout << value << (value > 1 ? "noeuds" : "noeud") << std::endl;
                break;
            case MPS:
                std::cout << value << "m/s" << std::endl;
                break;
        }
    }
};