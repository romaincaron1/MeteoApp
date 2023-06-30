//
// Created by Romain Caron on 28/06/2023.
//

#include <iostream>

enum CloudQuantityDetails {
    CLEAR = 0,
    FEW = 1,
    SCATTERED = 2,
    BROKEN = 3,
    OVERCAST = 4,
    NO_INFORMATION = 9
};

struct CloudQuantity {
    std::uint8_t value;
    CloudQuantityDetails details;

    CloudQuantity(std::uint8_t value, CloudQuantityDetails details) {
        this->value = value;
        this->details = details;
    }

    void print() {
        switch(this->details) {
            case CLEAR:
                std::cout << "Clear";
                break;
            case FEW:
                std::cout << "Few";
                break;
            case SCATTERED:
                std::cout << "Scattered";
                break;
            case BROKEN:
                std::cout << "Broken";
                break;
            case OVERCAST:
                std::cout << "Overcast";
                break;
            case NO_INFORMATION:
                std::cout << "No information";
                break;
        }
    }
};